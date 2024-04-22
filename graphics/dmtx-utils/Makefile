PORTNAME=	dmtx-utils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.6
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Software for reading and writing Data Matrix barcodes
WWW=		https://libdmtx.sourceforge.net

LICENSE=	LGPL21+

LIB_DEPENDS=	libdmtx.so:graphics/libdmtx

USES=		autoreconf libtool localbase magick tar:bzip2 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	dmtx

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
PLIST_FILES=	bin/dmtxread bin/dmtxwrite bin/dmtxquery \
		share/man/man1/dmtxread.1.gz share/man/man1/dmtxwrite.1.gz \
		share/man/man1/dmtxquery.1.gz

.include <bsd.port.mk>
