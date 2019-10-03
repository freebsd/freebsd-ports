# $FreeBSD$

PORTNAME=	kiwix-lib
DISTVERSION=	5.1.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	me@int19h.org
COMMENT=	Common code base for all Kiwix ports

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
		libcurl.so:ftp/curl

USES=		compiler:c++11-lang meson pkgconfig python:3.6+ shebangfix
USE_LDCONFIG=	yes
USE_GITHUB=	yes

GH_ACCOUNT=	kiwix
GH_TUPLE=	kiwix:${PORTNAME}:${PORTVERSION}:DEFAULT \
		kainjow:Mustache:40ddfe9:mustache

MESON_ARGS=	-Dctpp2-install-prefix=${LOCALBASE}
CPPFLAGS+=	-I${WRKSRC_mustache}
CXXFLAGS+=	-I${WRKSRC_mustache}
SHEBANG_FILES=	scripts/kiwix-compile-resources

.include <bsd.port.mk>
