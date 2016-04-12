# Created by: ijliao
# $FreeBSD$

PORTNAME=	pngwriter
PORTVERSION=	0.5.5
CATEGORIES=	graphics devel

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	C++ library for creating PNG images

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2

USES=		cmake:outsource
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	${PORTNAME}

PLIST_FILES=	include/pngwriter.h \
		lib/libpngwriter.a \
		lib/libpngwriter.so

.include <bsd.port.mk>
