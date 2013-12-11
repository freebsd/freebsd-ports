# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flare
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}-game/Linux/
DISTNAME=	${PORTNAME}-engine.${PORTVERSION}
PKGNAMESUFFIX=	-engine

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Libre Action Roleplaying Engine

LICENSE=	GPLv3

USES=		cmake
USE_SDL=	sdl mixer image ttf
CMAKE_BUILD_TYPE=	#empty

CMAKE_ARGS=	-DBINDIR="bin" -DDATADIR="share/flare" -DMANDIR="man"

PORTDOCS=	*
PORTDATA=	*

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/flare.1.gz

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.engine ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
