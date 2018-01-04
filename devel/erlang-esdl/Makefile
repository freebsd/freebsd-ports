# $FreeBSD$

PORTNAME=	esdl
PORTVERSION=	1.0.1
PORTREVISION=	13
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	erlang-
DISTNAME=	${PORTNAME}-${PORTVERSION}.src
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Library for accessing SDL and OpenGL through Erlang

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.terms

BUILD_DEPENDS=	erl:lang/erlang
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		dos2unix gmake
DOS2UNIX_GLOB=	Makefile
USE_GL=		gl glu
USE_SDL=	sdl
ALL_TARGET=	target
PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=	SDL_TTF SDL_IMAGE
OPTIONS_DEFAULT=SDL_TTF SDL_IMAGE
OPTIONS_SUB=	yes
SDL_TTF_DESC=	SDL_ttf support
SDL_TTF_USE=	SDL=ttf
SDL_IMAGE_DESC=	SDL_image support
SDL_IMAGE_USE=	SDL=image

post-patch:
	@${REINPLACE_CMD} -Ee 's|addons|lib|' ${WRKSRC}/Makefile

post-patch-SDL_TTF-on:
	@${REINPLACE_CMD} -e '/ENABLE_SDL_TTF = / s|no|yes|' ${WRKSRC}/Makefile

post-patch-SDL_IMAGE-on:
	@${REINPLACE_CMD} -e '/ENABLE_SDL_IMAGE = / s|no|yes|' ${WRKSRC}/Makefile

post-install:
	@${LN} -sf ${PORTNAME}-${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}

.include <bsd.port.mk>
