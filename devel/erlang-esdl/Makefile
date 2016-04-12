# $FreeBSD$

PORTNAME=	esdl
PORTVERSION=	1.0.1
PORTREVISION=	12
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Library for accessing SDL and OpenGL through Erlang

BUILD_DEPENDS=	erl:lang/erlang
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		dos2unix gmake
DOS2UNIX_GLOB=	Makefile
USE_GL=		gl glu
USE_SDL=	sdl
ALL_TARGET=	target
PLIST_SUB=	VERSION="${PORTVERSION}"
MAKE_ENV+=	STAGEDIR="${STAGEDIR}"

OPTIONS_DEFINE=	SDL_TTF SDL_IMAGE
OPTIONS_DEFAULT=SDL_TTF SDL_IMAGE
SDL_TTF_DESC=	SDL_ttf support
SDL_IMAGE_DESC=	SDL_image support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSDL_TTF}
USE_SDL+=	ttf
PLIST_SUB+=	SDL_TTF=""
.else
PLIST_SUB+=	SDL_TTF="@comment "
.endif

.if ${PORT_OPTIONS:MSDL_IMAGE}
USE_SDL+=	image
PLIST_SUB+=	SDL_IMAGE=""
.else
PLIST_SUB+=	SDL_IMAGE="@comment "
.endif

post-extract:
	@${FIND} ${WRKSRC} -type f -print0 | ${XARGS} -0 ${CHMOD} go+r

post-patch:
	@${REINPLACE_CMD} -Ee 's|addons|lib|' ${WRKSRC}/Makefile
.if ${PORT_OPTIONS:MSDL_TTF}
	@${REINPLACE_CMD} -e '/ENABLE_SDL_TTF = / s|no|yes|' ${WRKSRC}/Makefile
.endif
.if ${PORT_OPTIONS:MSDL_IMAGE}
	@${REINPLACE_CMD} -e '/ENABLE_SDL_IMAGE = / s|no|yes|' ${WRKSRC}/Makefile
.endif

post-install:
	@${LN} -sf ${PORTNAME}-${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}

.include <bsd.port.post.mk>
