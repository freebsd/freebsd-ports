# New ports collection makefile for:    bsdforen-firefox-searchplugin
# Date created:                         2006-03-24
# Whom:                                 Stefan 'Steve' Tell <stefan.tell@crashmail.de>
#
# $FreeBSD$
#

PORTNAME=	bsdforen-firefox-searchplugin
PORTVERSION=	0.1
CATEGORIES=	german www
MASTER_SITES=	http://www.crashmail.de/files/
DISTFILES=	bsdforen.src bsdforen.png
EXTRACT_ONLY=	yes

MAINTAINER=	stefan.tell@crashmail.de
COMMENT=	A firefox searchplugin for the german BSD board www.bsdforen.de

USE_X_PREFIX=	yes
NO_BUILD=	yes
USE_GECKO=	firefox

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/bsdforen.src ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/bsdforen.png ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/lib/firefox/searchplugins
	${INSTALL_DATA} ${WRKSRC}/bsdforen.src ${PREFIX}/lib/firefox/searchplugins
	${INSTALL_DATA} ${WRKSRC}/bsdforen.png ${PREFIX}/lib/firefox/searchplugins

.include <bsd.port.mk>
