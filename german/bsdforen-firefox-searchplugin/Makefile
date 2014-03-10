# Created by: Stefan 'Steve' Tell <stefan.tell@crashmail.de>
# $FreeBSD$

PORTNAME=	bsdforen-firefox-searchplugin
PORTVERSION=	0.3
PORTREVISION=	8
CATEGORIES=	german www
MASTER_SITES=	http://www.crashmail.de/files/ \
		http://people.bsdgroup.de/~steve/files/
DISTFILES=	bsdforen.src bsdforen.png bsdforen-wiki.src bsdforen-wiki.png
EXTRACT_ONLY=	yes

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Firefox search plugins for the www.bsdforen.de board and wiki

USE_FIREFOX=	yes

NO_BUILD=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

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
