# New ports collection makefile for:	pluxml-theme-snowxml
# Date created:			27 September 2007
# Whom:				Philippe Audeoud <jadawin@tuxaco.net>
#
# $FreeBSD$
#

PORTNAME=	pluxml
PORTVERSION=	0.1
CATEGORIES=	french www
MASTER_SITES=	http://jadawin.tuxaco.net/
PKGNAMESUFFIX=	-theme-snowxml
DISTNAME=	${PORTNAME}.${PKGNAMESUFFIX:C/-(.*)-(.*)/\2/}

MAINTAINER=	jadawin@tuxaco.net
COMMENT=	Theme for pluxml > 0.3.0

RUN_DEPENDS=	${WWWDIR}/pluxml:${PORTSDIR}/french/pluxml

NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

WRKSRC=		${WRKDIR}/${PKGNAMESUFFIX:C/-(.*)-(.*)/\2/}

do-install:
	${MKDIR} ${WWWDIR}/pluxml/templates/${PKGNAMESUFFIX:C/-(.*)-(.*)/\2/}
	${CP} -R ${WRKDIR}/${PKGNAMESUFFIX:C/-(.*)-(.*)/\2/} \
		${WWWDIR}/pluxml/templates/
	${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR}/pluxml/templates/${PKGNAMESUFFIX:C/-(.*)-(.*)/\2/}

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
