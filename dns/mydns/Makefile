# New ports collection makefile for:	mydns
# Date created:				23 July 2002
# Whom:					Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	mydns
PORTVERSION=	1.0.0
CATEGORIES=	dns databases
MASTER_SITES=	http://mydns.bboy.net/download/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	DNS server designed to utilize the MySQL database

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc
USE_ICONV=	yes
USE_LIBTOOL_VER=	15
USE_BZIP2=	yes

USE_RC_SUBR=	mydns.sh

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

INFO=		mydns
MAN5=		mydns.conf.5
MAN8=		mydns.8 mydnscheck.8 mydnsexport.8 mydnsimport.8 mydnsptrconvert.8 mydns-conf.8

DOCS=		AUTHORS COPYING ChangeLog NEWS QUICKSTART.mysql QUICKSTART.postgres README TODO

.if defined(WITH_ALIAS)
CONFIGURE_ARGS+=--enable-alias
.endif

.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--without-mysql
PKGNAMESUFFIX=	-pg
.else
CONFIGURE_ARGS+=--without-pgsql
PKGNAMESUFFIX=	-mysql
USE_MYSQL=	yes
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} >= 502102
BROKEN=		"Does not compile on alpha 5.x"
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_PGSQL=yes          Build with PostgreSQL support"
	@${ECHO} "      WITH_ALIAS=yes          Enable server side aliases"
	@${ECHO} "      WITH_OPENSSL=yes        Enable OpenSSL (needed if MySQL is linked with OpenSSL)"
	@${ECHO} ""

post-install:
	@install-info ${PREFIX}/info/mydns.info ${PREFIX}/info/dir
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/contrib
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/contrib/*.php ${DOCSDIR}/contrib/
	@${INSTALL_DATA} ${WRKSRC}/contrib/*.pm ${DOCSDIR}/contrib/
	@${INSTALL_DATA} ${WRKSRC}/contrib/README ${DOCSDIR}/contrib/
.endif
	@${PREFIX}/sbin/mydns --dump-config >${PREFIX}/etc/mydns.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
