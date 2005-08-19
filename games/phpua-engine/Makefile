# New ports collection makefile for:   phpUA
# Date created:        20 Feb 2003
# Whom:                hideki
#
# $FreeBSD$
#

PORTNAME=	phpua-engine
PORTVERSION=	1.1.0b
PORTREVISION=	2
CATEGORIES=	games www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpua

MAINTAINER=	hido@coreblack.com
COMMENT=	Game server monitor & admin tool

NO_BUILD=	yes
USE_APACHE=	yes
USE_PHP=	yes

PLIST_SUB+=	PHPUADIR=${PHPUADIR} PHPUA_USER=${PHPUA_USER} PHPUA_GROUP=${PHPUA_GROUP}

# Dynamic custom variables
WWWDOC?=	www/data
PHPUA_USER?=	${WWWOWN}
PHPUA_GROUP?=	${WWWGRP}
APPNAME?=	phpua

# Static Variables
PKGOPTS=	${FILESDIR}/pkg-opts
PHPUADIR=	${WWWDOC}/${APPNAME}

PKGMESSAGE=	${WRKDIR}/pkg-message

options:
	@ ${ECHO_MSG} "===>  Build options for ${PKGNAME}:"
	@ ${CAT} ${PKGOPTS}

pre-everything::
.if !defined(BATCH)
	@ ${TEST} -r ${PKGOPTS} && \
	(${ECHO_MSG} '-------------------------------------------------------------------------'; \
	${ECHO_MSG} 'Perform a "make options" to see a list of available installation options.'; \
	${ECHO_MSG} '-------------------------------------------------------------------------')
.endif

post-patch:
	@${CAT} ${FILESDIR}/pkg-message.in | ${SED} -e \
		's|%%PREFIX%%|${PREFIX}| ; s|%%PHPUADIR%%|${PHPUADIR}| ; s|%%APPNAME%%|${APPNAME}|' \
		> ${PKGMESSAGE}

do-install:
	@ ${MKDIR} ${PREFIX}/${PHPUADIR}
	@ ${CP} ${WRKDIR}/*.php ${PREFIX}/${PHPUADIR}/
	@ ${CP} -R ${WRKDIR}/doc ${PREFIX}/${PHPUADIR}/
	@ ${CP} -R ${WRKDIR}/images ${PREFIX}/${PHPUADIR}/
	@ ${CP} -R ${WRKDIR}/includes ${PREFIX}/${PHPUADIR}/
	@ ${CP} -R ${WRKDIR}/languages ${PREFIX}/${PHPUADIR}/
	@ ${CP} -R ${WRKDIR}/plugins ${PREFIX}/${PHPUADIR}/
	@ ${CP} -R ${WRKDIR}/templates ${PREFIX}/${PHPUADIR}/
	@ ${CP} -R ${WRKDIR}/wap ${PREFIX}/${PHPUADIR}/
	@ ${CHOWN} -R ${PHPUA_USER}:${PHPUA_GROUP} ${PREFIX}/${PHPUADIR}/

.include <bsd.port.mk>
