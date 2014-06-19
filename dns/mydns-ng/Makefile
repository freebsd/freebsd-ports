# Created by: Simon Dick <simond@irrelevant.org>
# $FreeBSD$

PORTNAME=	mydns-ng
PORTVERSION=	1.2.8.31
PORTREVISION=	1
CATEGORIES=	dns databases
MASTER_SITES=	SF/${PORTNAME}/mydns/${PORTVERSION}
DISTNAME=	mydns-${PORTVERSION}

MAINTAINER=	gaod@hychen.org
COMMENT=	Next Generation DNS Server for sql based DNS services

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc
USES=		iconv

USE_RC_SUBR=	mydns

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

INFO=		mydns
MAN5=		mydns.conf.5
MAN8=		mydns.8 mydnscheck.8 mydnsexport.8 mydnsimport.8 mydnsptrconvert.8 mydns-conf.8

DOCS=		AUTHORS COPYING ChangeLog NEWS QUICKSTART.mysql QUICKSTART.postgres README TODO

OPTIONS_DEFINE=		PGSQL ALIAS SSL NLS
OPTIONS_DEFAULT=	ALIAS
ALIAS_DESC=	Server side aliasas

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALIAS}
CONFIGURE_ARGS+=--enable-alias
.endif

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=yes
CONFIGURE_ARGS+=--with-openssl \
		--with-openssl-include=${OPENSSLINC} \
		--with-openssl-lib=${OPENSSLLIB}
.endif

.if ${PORT_OPTIONS:MPGSQL}
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

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
CONFIGURE_ARGS+=--with-included-gettext
USES+=		gettext
PLIST_SUB+=	NLS=""
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
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

.include <bsd.port.mk>
