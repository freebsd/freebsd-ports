PORTNAME=	flam3
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1-5
PORTREVISION=	5
DISTVERSIONSUFFIX=	-g7fb50c8
CATEGORIES=	graphics

MAINTAINER=	john.c.prather@gmail.com
COMMENT=	Algorithmically generated fractal flames images and animations
WWW=		http://flam3.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake gnome jpeg libtool localbase pathfix
USE_GNOME=	libxml2
USE_GITHUB=	yes
GH_ACCOUNT=	scottdraves
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-shared --disable-static
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^libflam3_la_SOURCES = .*|& sincos.c| ; s| isaac.lo$$|& sincos.lo|' \
		${WRKSRC}/Makefile.in # sincos is missing on some systems: bug#218300
	@${REINPLACE_CMD} -e 's| -g -O3||' ${WRKSRC}/Makefile.in # https://github.com/scottdraves/flam3/issues/25

pre-build:
	@${CP} ${FILESDIR}/sincos.c ${WRKSRC}

.include <bsd.port.mk>
