PORTNAME=	foobillard
PORTVERSION=	3.0a
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/FooBillard-Sources/

MAINTAINER=	thomas@bsdunix.ch
COMMENT=	Free OpenGL billiards game
WWW=		https://foobillard.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2

USES=		gmake localbase:ldflags pkgconfig xorg
USE_XORG=	xaw ice

GNU_CONFIGURE=	yes

DESKTOP_ENTRIES=	"Foobillard" \
			"A free OpenGL-billard game" \
			"${DATADIR}/foobillard.png" \
			"foobillard" \
			"Game;Simulation;" \
			false

OPTIONS_DEFINE=	SDL NVIDIA_BUMPREF

NVIDIA_BUMPREF_DESC=	NVidia extensions
SDL_DESC=	SDL instead of glut

NVIDIA_BUMPREF_CONFIGURE_OFF=	--disable-nvidia
NVIDIA_BUMPREF_CFLAGS_OFF= -DGL_AMD_gpu_shader_int64=1 -DGLuint64EXT=uint64_t -DGLint64EXT=int64_t -UGL_VERTEX_PROGRAM_NV -DGL_NV_vertex_program=1
SDL_USES=		sdl
SDL_USE=	SDL=sdl
SDL_CONFIGURE_ON=	--enable-SDL
SDL_USES_OFF=	gl
SDL_USE_OFF=	GL=glut
SDL_CONFIGURE_OFF=	--enable-glut

FREETYPE_CONFIG?=	pkg-config freetype2

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%FREETYPE_CONFIG%%|${FREETYPE_CONFIG}|g' \
		${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/foobillard.6 ${STAGEDIR}${PREFIX}/share/man/man6/foobillard.6

.include <bsd.port.mk>
