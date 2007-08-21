# New ports collection makefile for:   pluxml
# Date created:                7 August 2007
# Whom:                        Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	pluxml
PORTVERSION=	0.3.1
CATEGORIES=	french www
MASTER_SITES=	http://pluxml.org/download/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	jadawin@tuxaco.net
COMMENT=	Small weblog in php and xml

USE_PHP=	xml pcre
WANT_PHP_WEB=	yes

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message

NO_BUILD=	yes

SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST=	WWWDIR=${WWWDIR} \
		PORTNAME=${PORTNAME}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

do-install:
	${MKDIR} ${WWWDIR}
.for  data in images pluxml version
	${CP} -R ${WRKSRC}/${data} ${WWWDIR}
.endfor
	${CP} ${WRKSRC}/*.php ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
