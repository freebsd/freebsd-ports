PORTNAME=	zim-tools
DISTVERSION=	3.5.0
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	https://download.openzim.org/release/zim-tools/

MAINTAINER=	olce.freebsd.ports@certner.fr
COMMENT=	Tools for handling ZIM files
WWW=		https://github.com/openzim/zim-tools

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/kainjow/mustache.hpp:devel/mustache \
		googletest>0:devel/googletest
LIB_DEPENDS=	libdocopt.so:devel/docopt.cpp \
		libgumbo.so:devel/gumbo \
		libicui18n.so:devel/icu \
		libzim.so:devel/libzim

USES=		compiler:c++17-lang meson pkgconfig tar:xz

CPPFLAGS+=	-I${LOCALBASE}/include/kainjow
CXXFLAGS+=	-I${LOCALBASE}/include/kainjow

PLIST_SUB=	DISTVERSION=${DISTVERSION} DISTMAJ=${DISTVERSION:C/\..*//}

.include <bsd.port.mk>
