# Created by: ijliao
# $FreeBSD$

PORTNAME=	sdl
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/ocaml${PORTNAME}/OCamlSDL/ocaml${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	ocaml-
DISTNAME=	ocamlsdl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml interface to the SDL

LICENSE=	LGPL20+ # source says LGPL20+, COPYING says LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ocaml-lablgl>0:graphics/ocaml-lablgl

USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAMLFIND_PLIST=yes
USE_OCAML_LDCONFIG=yes

USES=		gmake
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lablgldir=${LOCALBASE} \
		--with-sdl-prefix=${LOCALBASE} \
		--with-installdir=${PREFIX}

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

INFO=		ocamlsdl
PORTDOCS=	*

OPTIONS_DEFINE=	SDL_GFX SDL_IMAGE SDL_MIXER SDL_TTF DOCS
OPTIONS_DEFAULT=SDL_GFX SDL_IMAGE SDL_MIXER SDL_TTF

SDL_GFX_DESC=	Enable SDL_gfx support
SDL_IMAGE_DESC=	Enable SDL_image support
SDL_MIXER_DESC=	Enable SDL_mixer support
SDL_TTF_DESC=	Enable SDL_ttf support

SDL_GFX_USE=		SDL=gfx
SDL_GFX_CONFIGURE_OFF=	--disable-sdl-gfx

SDL_IMAGE_USE=		SDL=image
SDL_IMAGE_CONFIGURE_OFF=--disable-sdl-image

SDL_MIXER_USE=		SDL=mixer
SDL_MIXER_CONFIGURE_OFF=--disable-sdl-mixer

SDL_TTF_USE=		SDL=ttf
SDL_TTF_CONFIGURE_OFF=	--disable-sdl-ttf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib/sdl/*.so
	${INSTALL_DATA} ${WRKSRC}/doc/ocamlsdl.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
