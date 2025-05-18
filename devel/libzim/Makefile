PORTNAME=	libzim
DISTVERSION=	9.2.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://download.openzim.org/release/libzim/

MAINTAINER=	olce.freebsd.ports@certner.fr
COMMENT=	Reference implementation of the ZIM specification
WWW=		https://wiki.openzim.org/wiki/Libzim

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

# 'googletest' dependency is only necessary for Meson's 'test' target, but it
# must be present as soon as configure time.
BUILD_DEPENDS=	googletest>0:devel/googletest
LIB_DEPENDS=	libicui18n.so:devel/icu \
		libxapian.so:databases/xapian-core \
		libzstd.so:archivers/zstd

# Python is necessary for the build against Xapian and for Meson's 'test' target
# as well, for which it must be present as soon as configure time.
USES=		compiler:c++17-lang meson pkgconfig python:build tar:xz
USE_LDCONFIG=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD:T} python3-config=${PYTHON_CMD:T}-config

PLIST_SUB=	DISTVERSION=${DISTVERSION} DISTMAJ=${DISTVERSION:C/\..*//}

.include <bsd.port.mk>
