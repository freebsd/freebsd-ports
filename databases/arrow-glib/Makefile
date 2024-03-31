PORTNAME=	arrow
PORTVERSION=	15.0.2
CATEGORIES=	databases
MASTER_SITES=	APACHE/arrow/arrow-${PORTVERSION}/
PKGNAMESUFFIX=	-glib
DISTNAME=	apache-arrow-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C API wrapper library for Arrow C++
WWW=		https://arrow.apache.org/ \
		https://github.com/apache/arrow/tree/master/c_glib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

BUILD_DEPENDS=	arrow>=${PORTVERSION}<${PORTVERSION}_99:databases/arrow
LIB_DEPENDS=	libarrow.so:databases/arrow

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GNOME=	introspection

MESON_ARGS=	--default-library=both -Darrow_cpp_build_dir='' -Darrow_cpp_build_type='release' -Dgtk_doc=false
WRKSRC_SUBDIR=	c_glib

PLIST_SUB=	SHLIB_VER=${PORTVERSION:R:R}00.${PORTVERSION:E}.0

.include <bsd.port.mk>
