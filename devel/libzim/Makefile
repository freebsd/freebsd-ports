PORTNAME=	libzim
DISTVERSION=	8.2.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://download.openzim.org/release/libzim/

MAINTAINER=	olce.freebsd.ports@certner.fr
COMMENT=	Reference implementation of the ZIM specification
WWW=		https://www.openzim.org/wiki/OpenZIM

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	googletest>0:devel/googletest
LIB_DEPENDS=	libicui18n.so:devel/icu \
		libxapian.so:databases/xapian-core \
		libzstd.so:archivers/zstd

USES=		compiler:c++14-lang meson pkgconfig python tar:xz
USE_LDCONFIG=	yes

MESON_ARGS=	-Dcpp_std=c++14

BINARY_ALIAS=	python3=${PYTHON_CMD:T} python3-config=${PYTHON_CMD:T}-config

PLIST_SUB=	DISTVERSION=${DISTVERSION} DISTMAJ=${DISTVERSION:C/\..*//}

.include <bsd.port.mk>
