# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	cosmosmash
DISTVERSION=	1.4.7
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://perso.b2b2c.ca/sarrazip/dev/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A clone of the Intellivision(TM) game Astrosmash(TM)

LICENSE=	GPLv2

LIB_DEPENDS=	libflatzebra-0.1.so:${PORTSDIR}/devel/flatzebra \
		libaa.so:${PORTSDIR}/graphics/aalib \
		libmikmod.so:${PORTSDIR}/audio/libmikmod \
		libaudiofile.so:${PORTSDIR}/audio/libaudiofile

USE_SDL=	sdl image mixer
USE_XORG=	x11 xau xdmcp
USES=		iconv pkgconfig desktop-file-utils
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include `${SDL_CONFIG} --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} `${SDL_CONFIG} --libs`

post-patch:
	@${REINPLACE_CMD} 's|^pkgsounddir = .*|pkgsounddir = ${DATADIR}/sounds|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} 's|^docdir = .*|docdir = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
