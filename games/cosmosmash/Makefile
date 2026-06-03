PORTNAME=	cosmosmash
DISTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://perso.b2b2c.ca/~sarrazip/dev/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Clone of the Intellivision(TM) game Astrosmash(TM)
WWW=		http://sarrazip.com/dev/cosmosmash.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libflatzebra-0.2.so:devel/flatzebra \
		libaa.so:graphics/aalib \
		libmikmod.so:audio/libmikmod \
		libaudiofile.so:audio/libaudiofile

USES=		desktop-file-utils iconv pkgconfig sdl xorg
USE_SDL=	sdl2 gfx2 image2 mixer2 ttf2
USE_XORG=	x11 xau xdmcp

GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS NEWS README THANKS

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|^pkgsounddir =.*|pkgsounddir = ${DATADIR}/sounds|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} 's|^docdir = .*|docdir = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
