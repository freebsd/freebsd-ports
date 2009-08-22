# New ports collection makefile for:	phpua-plugin_ut
# Date created:				29 March 2003
# Whom:					hideki
#
# $FreeBSD$
#

PORTNAME=	phpua-plugin_ut
PORTVERSION=	1.1.0b
PORTREVISION=	1
CATEGORIES=	games www
MASTER_SITES=	SF/phpua/Plug-in_%20Unreal%20Tournament/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Unreal Tournament plugin for phpUA

BUILD_DEPENDS=	${LOCALBASE}/${PHPUA}/index.php:${PORTSDIR}/games/phpua-engine
RUN_DEPENDS=	${BUILD_DEPENDS}

# Some variables you can change
PHPUA?=		www/phpua
PHPUA_USER?=	${WWWOWN}
PHPUA_GROUP?=	${WWWGRP}

# Static Variables
PKGOPTS=	${FILESDIR}/pkg-opts

NO_BUILD=	yes

PLIST_SUB+=	PHPUA=${PHPUA} PHPUA_USER=${PHPUA_USER} PHPUA_GROUP=${PHPUA_GROUP}

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
	@ ${CHOWN} -R ${PHPUA_USER}:${PHPUA_GROUP} ${WRKSRC}
	@ ${CP} -R ${WRKSRC}/ ${PREFIX}/${PHPUA}/
	@ ${ECHO_MSG} ""
	@ ${ECHO_MSG} "* Files have been installed in"
	@ ${ECHO_MSG} "* ${PREFIX}/${PHPUA}"
	@ ${ECHO_MSG} "*"

.include <bsd.port.mk>
