# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	cosmosmash
DISTVERSION=	1.4.7
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://perso.b2b2c.ca/~sarrazip/dev/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Clone of the Intellivision(TM) game Astrosmash(TM)

LICENSE=	GPLv2

LIB_DEPENDS=	libflatzebra-0.1.so:devel/flatzebra \
		libaa.so:graphics/aalib \
		libmikmod.so:audio/libmikmod \
		libaudiofile.so:audio/libaudiofile

USES=		iconv pkgconfig desktop-file-utils sdl xorg
USE_CXXSTD=	gnu++98
USE_SDL=	sdl image mixer
USE_XORG=	x11 xau xdmcp

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include `${SDL_CONFIG} --cflags`
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib `${SDL_CONFIG} --libs`

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|^pkgsounddir = .*|pkgsounddir = ${DATADIR}/sounds|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} 's|^docdir = .*|docdir = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
