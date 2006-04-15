# Ports collection makefile for:  Gollem
# Date created:			  Sun Dec 16, 2001
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	gollem
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	ftp www
MASTER_SITES=	ftp://ftp.horde.org/pub/gollem/				\
		ftp://ftp.planetmirror.com/pub/horde/gollem/		\
		ftp://ftp.be.horde.org/gollem/				\
		ftp://ftp.es.horde.org/pub/gollem/			\
		ftp://ftp.it.horde.org/pub/mirror/horde.org/gollem/	\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/gollem/	\
		ftp://ftp.uk.horde.org/mirrors/ftp.horde.org/pub/gollem/\
		http://ftp.horde.org/pub/gollem/
DISTNAME=	${PORTNAME}-h3-${PORTVERSION}

MAINTAINER=	shaun@inerd.com
COMMENT=	Gollem is the Horde web-based File Manager

RUN_DEPENDS=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde

NO_BUILD=	yes
USE_GETTEXT=	yes
USE_APACHE=	1.3+	# needed to test APACHE_VERSION

PLIST_SUB=	GOLLEMDIR=${LGOLLEMDIR} HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	GOLLEMDIR=${GOLLEMDIR}

DOCS=		README docs/CHANGES docs/CREDITS docs/INSTALL	\
		docs/RELEASE_NOTES docs/TODO
CONFFILE=	backends.php credentials.php menu.php mime_drivers.php motd.php	\
		prefs.php
SUB_DIRS=	config js lib locale po templates themes

LHORDEDIR?=	www/horde
LGOLLEMDIR?=	${LHORDEDIR}/gollem

GOLLEMDIR=	${PREFIX}/${LGOLLEMDIR}
CONFDIR=	${GOLLEMDIR}/config

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 20
HORDE_INC=	${LOCALBASE}/etc/apache${APACHE_VERSION:S/20/2/}/Includes
.else
HORDE_INC=	${LOCALBASE}/etc/horde
.endif

pre-configure:
	@${SED} -e "s:/home/httpd/html/horde/gollem:${GOLLEMDIR}:g"		\
		${FILESDIR}/httpd.conf.gollem > ${WRKDIR}/httpd-gollem.conf

do-install:
	@${MKDIR}  ${GOLLEMDIR}
	@${CP} -Rp ${SUB_DIRS:S|^|${WRKSRC}/|} ${GOLLEMDIR}
	@${CP} -p  ${WRKSRC}/*.php ${GOLLEMDIR}

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${GOLLEMDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${INSTALL_DATA} ${WRKDIR}/httpd-gollem.conf ${HORDE_INC}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
