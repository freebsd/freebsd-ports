# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flare
PORTVERSION=	0.19
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}-game/Linux/
DISTNAME=	${PORTNAME}-engine.${PORTVERSION}
PKGNAMESUFFIX=	-engine

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Libre Action Roleplaying Engine

LICENSE=	GPLv3

USES=		cmake compiler:env
USE_SDL=	sdl mixer image ttf
CMAKE_BUILD_TYPE=	#empty

CMAKE_ARGS=	-DBINDIR="bin" -DDATADIR="share/flare" -DMANDIR="man"

PORTDOCS=	*
PORTDATA=	*

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/flare.1.gz

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == "clang"
	@${REINPLACE_CMD} -e 's|-fwhole-program||' ${WRKSRC}/CMakeLists.txt
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/flare
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.engine ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>
