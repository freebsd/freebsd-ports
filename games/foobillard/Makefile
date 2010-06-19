# New ports collection makefile for:	foobillard
# Date created:				26 October 2002
# Whom:					Thomas Vogt <thomas.vogt@bsdunix.ch>
#
# $FreeBSD$
#

PORTNAME=	foobillard
PORTVERSION=	3.0a
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://foobillard.sunsite.dk/dnl/

MAINTAINER=	thomas@bsdunix.ch
COMMENT=	A free OpenGL-billard game

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

OPTIONS=	SDL	"Use SDL instead of glut"	off \
		NVIDIA_BUMPREF	"Enable NVidia extensions"	off

.include <bsd.port.pre.mk>

FREETYPE_CONFIG?=	${LOCALBASE}/bin/freetype-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_XORG=	xaw ice

CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${LOCALBASE}/lib"

DESKTOP_ENTRIES=	"Foobillard" \
			"A free OpenGL-billard game" \
			"${DATADIR}/foobillard.png" \
			"foobillard" \
			"Game;Simulation;" \
			false

.if defined(WITH_SDL)
USE_SDL=	yes
CONFIGURE_ARGS+=	--enable-SDL
.else
USE_GL=		glut
CONFIGURE_ARGS+=	--enable-glut
.endif

.if !defined(WITH_NVIDIA_BUMPREF)
CONFIGURE_ARGS+=	--disable-nvidia
.endif

MAN6=		foobillard.6

post-patch:
	@${REINPLACE_CMD} -e 's|%%FREETYPE_CONFIG%%|${FREETYPE_CONFIG}|g' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${INSTALL_MAN} ${WRKSRC}/foobillard.6 ${PREFIX}/man/man6/foobillard.6

.include <bsd.port.post.mk>
