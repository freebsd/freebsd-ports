# New ports collection makefile for:	flare
# Date created:		03 May 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flare
DISTVERSION=	016
CATEGORIES=	games
MASTER_SITES=	http://cloud.github.com/downloads/clintbellanger/flare/ \
		http://mirror.amdmi3.ru/files/
DISTNAME=	${PORTNAME}_linux_v${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Libre Action Roleplaying Engine

LICENSE=	GPLv3

USE_ZIP=	yes
USE_CMAKE=	yes
USE_SDL=	sdl mixer image ttf
MAKE_JOBS_SAFE=	yes
CMAKE_BUILD_TYPE=	#empty
INSTALLS_ICONS=	yes

CMAKE_ARGS=	-DBINDIR="bin" -DDATADIR="share/flare"

LATEST_LINK=	flare-rpg

WRKSRC=		${WRKDIR}/${PORTNAME}_v${DISTVERSION}

PORTDOCS=	*

post-extract:
	@${FIND} ${WRKSRC} -name '._*' -delete

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
