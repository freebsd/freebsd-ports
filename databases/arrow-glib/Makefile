PORTNAME=	arrow
PORTVERSION=	8.0.0
PORTREVISION=	3
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

USES=		compiler:c++11-lang gnome meson pkgconfig
USE_GNOME=	introspection

MESON_ARGS=	--default-library=both -Darrow_cpp_build_dir='' -Darrow_cpp_build_type='release' -Dgtk_doc=false
WRKSRC_SUBDIR=	c_glib

.include <bsd.port.mk>
