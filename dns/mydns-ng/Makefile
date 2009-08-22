# New ports collection makefile for:	mydns
# Date created:				23 July 2002
# Whom:					Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	mydns-ng
PORTREVISION=	1
PORTVERSION=	1.2.8.27
CATEGORIES=	dns databases
MASTER_SITES=	SF/${PORTNAME}/mydns/${PORTVERSION}
DISTNAME=	mydns-${PORTVERSION}

MAINTAINER=	gaod@hychen.org
COMMENT=	A Next Generation DNS Server for sql based DNS services

WRKSRC=		${WRKDIR}/mydns-${PORTVERSION:R}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc
USE_ICONV=	yes

USE_RC_SUBR=	mydns

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

INFO=		mydns
MAN5=		mydns.conf.5
MAN8=		mydns.8 mydnscheck.8 mydnsexport.8 mydnsimport.8 mydnsptrconvert.8 mydns-conf.8

DOCS=		AUTHORS COPYING ChangeLog NEWS QUICKSTART.mysql QUICKSTART.postgres README TODO

OPTIONS=	PGSQL "Build with PostgreSQL backend instead of MySQL" OFF \
		ALIAS "Enable server side aliases" ON \
		OPENSSL "Enable OpenSSL (if MySQL is linked with OpenSSL)" OFF	\
		NLS "Native Language Support with gettext" OFF

.include <bsd.port.pre.mk>

.if defined(WITH_ALIAS)
CONFIGURE_ARGS+=--enable-alias
.endif

.if defined(WITH_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=--with-openssl \
		--with-openssl-include=${OPENSSLINC} \
		--with-openssl-lib=${OPENSSLLIB}
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--without-mysql \
		--with-pgsql-include=${LOCALBASE}/include \
		--with-pgsql-lib=${LOCALBASE}/lib
PKGNAMESUFFIX=	-pgsql
.else
CONFIGURE_ARGS+=--without-pgsql \
		--with-mysql-include=${LOCALBASE}/include/mysql \
		--with-mysql-lib=${LOCALBASE}/lib/mysql
PKGNAMESUFFIX=	-mysql
USE_MYSQL=	yes
.endif

.if !defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--with-included-gettext
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/contrib
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/contrib/*.php ${DOCSDIR}/contrib/
	@${INSTALL_DATA} ${WRKSRC}/contrib/*.pl ${DOCSDIR}/contrib/
	@${INSTALL_DATA} ${WRKSRC}/contrib/*.pm ${DOCSDIR}/contrib/
	@${INSTALL_DATA} ${WRKSRC}/contrib/README ${DOCSDIR}/contrib/
.endif
	@${PREFIX}/sbin/mydns --dump-config >${PREFIX}/etc/mydns.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
