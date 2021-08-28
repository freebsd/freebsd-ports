PORTNAME=	libzim
DISTVERSION=	6.3.2
CATEGORIES=	devel
MASTER_SITES=	https://download.openzim.org/release/libzim/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Reference implementation of the ZIM specification

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	googletest>0:devel/googletest

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libxapian.so:databases/xapian-core \
		libzstd.so:archivers/zstd

USES=		compiler:c++11-lang meson pkgconfig python:3.6+ tar:xz
USE_LDCONFIG=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD:T} python3-config=${PYTHON_CMD:T}-config
PLIST_SUB=	DISTVERSION=${DISTVERSION} DISTMAJ=${DISTVERSION:C/\..*//}

.include <bsd.port.mk>
