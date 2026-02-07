PORTNAME=	libkiwix
DISTVERSION=	14.0.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://download.kiwix.org/release/libkiwix/

MAINTAINER=	olce.freebsd.ports@certner.fr
COMMENT=	Software library to read and write ZIM files
WWW=		https://github.com/kiwix/libkiwix

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

# 'googletest' dependency is only necessary for Meson's 'test' target, but it
# must be present as soon as configure time.
BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/include/kainjow/mustache.hpp:devel/mustache \
		googletest>0:devel/googletest

LIB_DEPENDS=	libzim.so:devel/libzim \
		libpugixml.so:textproc/pugixml \
		libaria2.so:www/aria2 \
		libicui18n.so:devel/icu \
		libicuuc.so:devel/icu \
		libxapian.so:databases/xapian-core \
		libctpp2.so:textproc/ctpp2 \
		libcurl.so:ftp/curl \
		libmicrohttpd.so:www/libmicrohttpd

USES=		compiler:c++17-lang meson pkgconfig python shebangfix tar:xz
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	libkiwix13

SHEBANG_FILES=	scripts/format_code.sh
SHEBANG_REGEX=	./scripts/kiwix.*[^.].

CPPFLAGS+=	-I${LOCALBASE}/include/kainjow
CXXFLAGS+=	-I${LOCALBASE}/include/kainjow

PLIST_SUB=	PORTVERSION=${PORTVERSION} PORTMAJ=${PORTVERSION:C/\..*//}

.include <bsd.port.mk>
