# Created by: Thomas Vogt <thomas.vogt@bsdunix.ch>
# $FreeBSD$

PORTNAME=	foobillard
PORTVERSION=	3.0a
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://foobillard.sunsite.dk/dnl/

MAINTAINER=	thomas@bsdunix.ch
COMMENT=	Free OpenGL billiards game

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2

OPTIONS_DEFINE=	SDL NVIDIA_BUMPREF
SDL_DESC=	SDL instead of glut
NVIDIA_BUMPREF_DESC=	NVidia extensions

.include <bsd.port.options.mk>

FREETYPE_CONFIG?=	${LOCALBASE}/bin/freetype-config

USES=		gmake
GNU_CONFIGURE=	yes
USE_XORG=	xaw ice

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES=	"Foobillard" \
			"A free OpenGL-billard game" \
			"${DATADIR}/foobillard.png" \
			"foobillard" \
			"Game;Simulation;" \
			false

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	yes
CONFIGURE_ARGS+=	--enable-SDL
.else
USE_GL=		glut
CONFIGURE_ARGS+=	--enable-glut
.endif

.if ! ${PORT_OPTIONS:MNVIDIA_BUMPREF}
CONFIGURE_ARGS+=	--disable-nvidia
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%FREETYPE_CONFIG%%|${FREETYPE_CONFIG}|g' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${INSTALL_MAN} ${WRKSRC}/foobillard.6 ${STAGEDIR}${PREFIX}/man/man6/foobillard.6

.include <bsd.port.mk>
