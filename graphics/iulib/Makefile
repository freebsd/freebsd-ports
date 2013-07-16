# Created by: Hiroto Kagotani <hiroto.kagotani@gmail.com>
# $FreeBSD$

PORTNAME=	iulib
PORTVERSION=	0.4
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
EXTRACT_SUFX=	.tgz

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	A library of image understanding-related algorithms

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

OPTIONS_DEFINE=	SDL VIDIO
SDL_DESC=	Enable SDL for graphical debugging
VIDIO_DESC=	Enable Video Input/Output (using ffmpeg)

MAKE_JOBS_SAFE=	yes
USE_GCC=	any
USE_PYTHON_BUILD=	yes
USE_AUTOTOOLS=	libtool aclocal automake autoconf
ACLOCAL_ARGS=	--automake-acdir=${ACLOCAL_DIR} -I${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl gfx
PLIST_SUB+=	SDL=""
.else
CONFIGURE_ARGS+=--without-SDL
PLIST_SUB+=	SDL="@comment "
.endif

.if ${PORT_OPTIONS:MVIDIO}
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
.endif

post-patch:
.if ! ${PORT_OPTIONS:MVIDIO}
	@${REINPLACE_CMD} -e 's/novidio, 0/novidio, 1/' ${WRKSRC}/configure.ac
.endif
	@${REINPLACE_CMD} -e 's/nov4l2, 0/nov4l2, 1/' ${WRKSRC}/configure.ac

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} \
	  && ${SETENV} ${PYTHON_CMD} genAM.py >Makefile.am \
	  && ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} --automake)

run-autotools: run-autotools-aclocal run-autotools-automake run-autotools-autoconf

.include <bsd.port.mk>
