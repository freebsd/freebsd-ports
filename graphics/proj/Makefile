PORTNAME=	proj
PORTVERSION=	8.2.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics geography
MASTER_SITES=	https://download.osgeo.org/proj/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Cartographic Projections library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	proj-data>=0:graphics/proj-data

USES=		compiler:c++11-lang cpe gmake libtool pathfix pkgconfig sqlite
USE_LDCONFIG=	yes

CPE_VENDOR=	proj_project

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
