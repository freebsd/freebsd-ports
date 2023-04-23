PORTNAME=	dataplot
DISTVERSION=	20210713
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free software system for statistical visualization
WWW=		https://www.itl.nist.gov/div898/software/dataplot/index.htm

LICENSE=	PD

LIB_DEPENDS=	libgd.so:graphics/gd \
		libpng.so:graphics/png

USES=		gmake gnome fortran jpeg readline xorg
USE_XORG=	x11 xi
USE_GNOME=	cairo

USE_GITHUB=	yes
GH_ACCOUNT=	usnistgov
GH_TAGNAME=	d5eb15dd86dd80098c6535aa68898ab8392ab700

WRKSRC_SUBDIR=	src

MAXOBV?=	450000	# Change if you need more observations/variable

FFLAGS+=	-DLINUX -fdefault-real-8 -fdefault-double-8 -std=legacy

PORTDATA=	*

PLIST_FILES=	bin/dataplot bin/xdataplot

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/MAXOBV=1500000/MAXOBV=${MAXOBV}/' \
		${WRKSRC}/DPCOPA.INC
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
