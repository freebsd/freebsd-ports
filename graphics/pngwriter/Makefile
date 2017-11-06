# Created by: ijliao
# $FreeBSD$

PORTNAME=	pngwriter
PORTVERSION=	0.6.0
CATEGORIES=	graphics devel

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	C++ library for creating PNG images

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2

BROKEN_mips=		fails to build: ios_base.h: 'std::ios_base::ios_base(const std::ios_base&)' is private
BROKEN_mips64=		fails to build: ios_base.h: 'std::ios_base::ios_base(const std::ios_base&)' is private
BROKEN_powerpc64=	fails to build: ios_base.h: 'std::ios_base::ios_base(const std::ios_base&)' is private

USES=		cmake:outsource
USE_GITHUB=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	include/pngwriter.h \
		lib/libpngwriter.a \
		lib/libpngwriter.so

.include <bsd.port.mk>
