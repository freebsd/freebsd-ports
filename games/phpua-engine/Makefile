# New ports collection makefile for:   phpUA
# Date created:        20 Feb 2003
# Whom:                hideki
#
# $FreeBSD$
#

PORTNAME=	phpua-engine
PORTVERSION=	1.1.0b
PORTREVISION=	4
CATEGORIES=	games www
MASTER_SITES=	SF/phpua/phpUA%20Engine/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Game server monitor & admin tool

NO_BUILD=	yes
USE_APACHE=	1.3
USE_PHP=	yes

_subs=PHPUADIR=${PHPUADIR} PHPUA_USER=${PHPUA_USER} PHPUA_GROUP=${PHPUA_GROUP} APNAME=${APNAME}

PLIST_SUB+=	${_subs}
SUB_LIST+=	${_subs}

# Dynamic custom variables
PHPUA_USER?=	${WWWOWN}
PHPUA_GROUP?=	${WWWGRP}
APPNAME?=	phpua

# Static Variables
PKGOPTS=	${FILESDIR}/pkg-opts
PHPUADIR=	www/${APPNAME}

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

do-extract:
	@ ${MKDIR} ${WRKSRC}
	@ cd ${WRKSRC} && ${EXTRACT_CMD}  ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}

do-install:
	@ ${MKDIR} ${PREFIX}/${PHPUADIR}
	@ ${CHOWN} -R ${PHPUA_USER}:${PHPUA_GROUP} ${WRKSRC}
	@ ${CP} -R ${WRKSRC}/ ${PREFIX}/${PHPUADIR}/
	@ ${ECHO_MSG} ""
	@ ${ECHO_MSG} "* Files have been installed in"
	@ ${ECHO_MSG} "* ${PREFIX}/${PHPUADIR}"
	@ ${ECHO_MSG} "*"

.include <bsd.port.mk>
