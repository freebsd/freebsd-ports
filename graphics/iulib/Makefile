# Created by: Hiroto Kagotani <hiroto.kagotani@gmail.com>
# $FreeBSD$

PORTNAME=	iulib
PORTVERSION=	0.4
PORTREVISION=	18
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Library of image understanding-related algorithms

LICENSE=	APACHE20

BROKEN=		Unfetchable (google code has gone away)

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

OPTIONS_DEFINE=	SDL VIDIO
SDL_DESC=	Enable SDL for graphical debugging
VIDIO_DESC=	Enable Video Input/Output (using ffmpeg)

USES=		autoreconf jpeg libtool python:build tar:tgz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl gfx
PLIST_SUB+=	SDL=""
.else
CONFIGURE_ARGS+=--without-SDL
PLIST_SUB+=	SDL="@comment "
.endif

.if ${PORT_OPTIONS:MVIDIO}
LIB_DEPENDS+=	libavcodec.so:multimedia/ffmpeg
.endif

post-patch:
.if ! ${PORT_OPTIONS:MVIDIO}
	@${REINPLACE_CMD} -e 's/novidio, 0/novidio, 1/' ${WRKSRC}/configure.ac
.endif
	@${REINPLACE_CMD} -e 's/nov4l2, 0/nov4l2, 1/' ${WRKSRC}/configure.ac

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} \
	  && ${SETENV} ${PYTHON_CMD} genAM.py > Makefile.am)

.include <bsd.port.mk>
