PORTNAME=	libkiwix
DISTVERSION=	12.1.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	olce.freebsd.ports@certner.fr
COMMENT=	Common code base for all Kiwix ports
WWW=		https://www.kiwix.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libzim.so:devel/libzim \
		libpugixml.so:textproc/pugixml \
		libaria2.so:www/aria2 \
		libicui18n.so:devel/icu \
		libicuuc.so:devel/icu \
		libxapian.so:databases/xapian-core \
		libctpp2.so:textproc/ctpp2 \
		libcurl.so:ftp/curl \
		libmicrohttpd.so:www/libmicrohttpd

USES=		compiler:c++11-lang meson pkgconfig python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	kiwix
GH_TUPLE=	kiwix:${PORTNAME}:${PORTVERSION}:DEFAULT \
		kainjow:Mustache:v4.1:mustache
USE_LDCONFIG=	yes

SHEBANG_FILES=	scripts/format_code.sh
SHEBANG_REGEX=	./scripts/kiwix.*[^.].

CPPFLAGS+=	-I${WRKSRC_mustache}
CXXFLAGS+=	-I${WRKSRC_mustache}
LDFLAGS+=	-lz

PLIST_SUB=	PORTVERSION=${PORTVERSION} PORTMAJ=${PORTVERSION:C/\..*//}

.include <bsd.port.mk>
