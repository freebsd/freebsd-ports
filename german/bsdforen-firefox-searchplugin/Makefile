# New ports collection makefile for:    bsdforen-firefox-searchplugin
# Date created:                         2006-03-24
# Whom:                                 Stefan 'Steve' Tell <stefan.tell@crashmail.de>
#
# $FreeBSD$
#

PORTNAME=	bsdforen-firefox-searchplugin
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	german www
MASTER_SITES=	http://www.crashmail.de/files/ \
		http://people.bsdgroup.de/~steve/files/
DISTFILES=	bsdforen.src bsdforen.png bsdforen-wiki.src bsdforen-wiki.png
EXTRACT_ONLY=	yes

MAINTAINER=	stefan.tell@crashmail.de
COMMENT=	Firefox searchplugins for the www.bsdforen.de board and wiki

NO_BUILD=	yes
USE_GECKO=	firefox

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/bsdforen.src ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/bsdforen.png ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/bsdforen-wiki.src ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/bsdforen-wiki.png ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/lib/firefox/searchplugins
	${INSTALL_DATA} ${WRKSRC}/bsdforen.src ${PREFIX}/lib/firefox/searchplugins
	${INSTALL_DATA} ${WRKSRC}/bsdforen.png ${PREFIX}/lib/firefox/searchplugins
	${INSTALL_DATA} ${WRKSRC}/bsdforen-wiki.src ${PREFIX}/lib/firefox/searchplugins
	${INSTALL_DATA} ${WRKSRC}/bsdforen-wiki.png ${PREFIX}/lib/firefox/searchplugins

.include <bsd.port.post.mk>
