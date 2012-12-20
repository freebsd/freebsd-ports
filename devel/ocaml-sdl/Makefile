# Created by: ijliao
# $FreeBSD$

PORTNAME=	sdl
PORTVERSION=	0.9.1
CATEGORIES=	devel
MASTER_SITES=	SF/ocaml${PORTNAME}/OCamlSDL/ocaml${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	ocaml-
DISTNAME=	ocamlsdl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OCaml interface to the SDL

LICENSE=	LGPL21

BUILD_DEPENDS=	ocaml-lablgl>0:${PORTSDIR}/graphics/ocaml-lablgl

OPTIONS_DEFINE=	SDL_GFX SDL_IMAGE SDL_MIXER SDL_TTF DOCS
OPTIONS_DEFAULT=SDL_GFX SDL_IMAGE SDL_MIXER SDL_TTF
SDL_GFX_DESC=	Enable SDL_gfx support
SDL_IMAGE_DESC=	Enable SDL_image support
SDL_MIXER_DESC=	Enable SDL_mixer support
SDL_TTF_DESC=	Enable SDL_ttf support

USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAMLFIND_PLIST=yes
USE_OCAML_LDCONFIG=yes

USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lablgldir=${LOCALBASE} \
		--with-sdl-prefix=${LOCALBASE} \
		--with-installdir=${PREFIX}
MAKE_JOBS_SAFE=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

INFO=		ocamlsdl
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL_GFX}
USE_SDL+=	gfx
.else
CONFIGURE_ARGS+=--disable-sdl-gfx
.endif

.if ${PORT_OPTIONS:MSDL_IMAGE}
USE_SDL+=	image
.else
CONFIGURE_ARGS+=--disable-sdl-image
.endif

.if ${PORT_OPTIONS:MSDL_MIXER}
USE_SDL+=	mixer
.else
CONFIGURE_ARGS+=--disable-sdl-mixer
.endif

.if ${PORT_OPTIONS:MSDL_TTF}
USE_SDL+=	ttf
.else
CONFIGURE_ARGS+=--disable-sdl-ttf
.endif

.if ${PORT_OPTIONS:MDOCS}
PLIST_DIRSTRY+=	${OCAML_DOCSDIR:S,^${PREFIX}/,,}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/ocamlsdl.info ${PREFIX}/${INFO_PATH}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc/html && ${INSTALL_DATA} * ${DOCSDIR})
.endif

.include <bsd.port.mk>
