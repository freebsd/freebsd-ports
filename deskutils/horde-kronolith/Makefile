# Ports collection makefile for:  Kronolith
# Date created:			  Sun Dec 02, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	kronolith
PORTVERSION=	2.1.4
DISTVERSIONPREFIX=	h3-
PORTREVISION=	1
CATEGORIES=	deskutils www
MASTER_SITES=	HORDE

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	Kronolith is the Horde calendar application

RUN_DEPENDS=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde-base

NO_BUILD=	yes
USE_PHP=	yes	# modules set by Horde, but needed to get PHP_VER
USE_GETTEXT=	yes

REINPLACE_ARGS=	-i ""
PORTDOCS=	README CHANGES CREDITS INSTALL	\
		RELEASE_NOTES TODO UPGRADING
CONFFILE=	keywords.php menu.php prefs.php
SUB_DIRS=	config js lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LKRONOLITHDIR?=	${LHORDEDIR}/kronolith

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	KRONOLITHDIR=${KRONOLITHDIR}
PLIST_SUB=	KRONOLITHDIR=${LKRONOLITHDIR}

KRONOLITHDIR=	${PREFIX}/${LKRONOLITHDIR}
CONFDIR=	${KRONOLITHDIR}/config

.include <bsd.port.pre.mk>

post-extract:
	@${MV} ${WRKSRC}/README ${WRKSRC}/docs/

pre-configure:
	@(cd ${WRKSRC}/scripts &&	\
		${FIND} . -name "*.php" -exec	\
		${REINPLACE_CMD} -e "s:/usr/local/bin/php: ${LOCALBASE}/bin/php:;s:/usr/bin/php: ${LOCALBASE}/bin/php:" {} \; )

do-install:
	@${INSTALL} -d ${KRONOLITHDIR}/
	@${CP} -Rp ${SUB_DIRS:S|^|${WRKSRC}/|} ${KRONOLITHDIR}/
	@${CP} -p ${WRKSRC}/*.php ${KRONOLITHDIR}/
	@${INSTALL_DATA} ${WRKSRC}/config/conf.xml ${CONFDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${KRONOLITHDIR}/
	@${CHMOD} -R o-rwx ${KRONOLITHDIR}/
	${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP}\
		%D/${KRONOLITHDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	${ECHO_CMD} @exec ${CHMOD} -R o-rwx\
		%D/${KRONOLITHDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
