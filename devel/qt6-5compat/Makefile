PORTNAME=	5compat
DISTVERSION=	${QT6_VERSION}
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 module that contains unsupported Qt 5 APIs
WWW=		https://qt-project.org

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libdouble-conversion.so:devel/double-conversion \
		libpcre.so:devel/pcre \
		libpcre2-16.so:devel/pcre2 \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang gettext-runtime gnome \
		qt-dist:6
USE_GNOME=	glib20
USE_QT=		base declarative shadertools
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
