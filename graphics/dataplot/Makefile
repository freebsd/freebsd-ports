PORTNAME=	dataplot
DISTVERSION=	20240806
CATEGORIES=	graphics

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Free software system for statistical visualization
WWW=		https://www.itl.nist.gov/div898/software/dataplot/index.htm

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

LIB_DEPENDS=	libgd.so:graphics/gd \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	xclip:x11/xclip

USES=		gmake gnome fortran readline xorg
USE_GITHUB=	yes
GH_ACCOUNT=	usnistgov
GH_TAGNAME=	b779512889cc78757fae29f9546e01b9c6cef95d
USE_GNOME=	cairo
USE_XORG=	x11 xft xi

FFLAGS+=	-fdefault-real-8 -fdefault-double-8 -std=legacy

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/dataplot bin/xdataplot
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e 's;%%FC%%;${FC};' \
		-e 's;%%CC%%;${CC};' \
		-e 's;%%FFLAGS%%;${FFLAGS};' \
		-e 's;%%CFLAGS%%;${CFLAGS};' \
		-e 's;%%DATADIR%%;${DATADIR};' \
		-e 's;%%LOCALBASE%%;${LOCALBASE};g' ${WRKSRC}/Makefile

post-build:
	@${STRIP_CMD} ${WRKSRC}/dataplot

.include <bsd.port.mk>
