# New ports collection makefile for:	pluxml-theme-bridge
# Date created:			27 September 2007
# Whom:				Philippe Audeoud <jadawin@tuxaco.net>
#
# $FreeBSD$
#

PORTNAME=	pluxml
PORTVERSION=	0.1
CATEGORIES=	french www
MASTER_SITES=	http://skins.pluxml.org/download/
PKGNAMESUFFIX=	-theme-bridge
DISTNAME=	${PORTNAME}.${PKGNAMESUFFIX:C/-(.*)-(.*)/\2/}

MAINTAINER=	jadawin@tuxaco.net
COMMENT=	Theme for pluxml > 0.3.0

RUN_DEPENDS=	${WWWDIR}/pluxml:${PORTSDIR}/french/pluxml

NO_BUILD=	yes
USE_ZIP=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

do-install:
	${MV} ${WRKDIR}/${PORTNAME}.${PKGNAMESUFFIX:C/-(.*)-(b)(.*)/B\3/} \
		${WRKDIR}/${PKGNAMESUFFIX:C/-(.*)-(.*)/\2/}
	${MKDIR} ${WWWDIR}/pluxml/templates/${PKGNAMESUFFIX:C/-(.*)-(.*)/\2/}
	${CP} -R ${WRKDIR}/${PKGNAMESUFFIX:C/-(.*)-(.*)/\2/} \
		${WWWDIR}/pluxml/templates/
	${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR}/pluxml/templates/${PKGNAMESUFFIX:C/-(.*)-(.*)/\2/}

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
