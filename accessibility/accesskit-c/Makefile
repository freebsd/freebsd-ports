PORTNAME=	accesskit-c
DISTVERSION=	0.17.1
PORTREVISION=	1
CATEGORIES=	accessibility

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	AccessKit C bindings for UI toolkits
WWW=		https://accesskit.dev \
		https://github.com/AccessKit/accesskit-c

LICENSE=	APACHE20 BSD3CLAUSE LGPL21 MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE.chromium
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	rust-cbindgen>0:devel/rust-cbindgen

USES=	cargo compiler meson pkgconfig python:build shebangfix
SHEBANG_FILES=	meson/*.py

MESON_ARGS=	-Db_lundef=false

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

MAKE_ENV=	${CARGO_ENV}
BINARY_ALIAS=	python3=${PYTHON_CMD}

# Depends of API version found in x11-toolkits/gtk40
PORTSCOUT=	limit:^0\.17\.

PLIST_SUB=	API_VER=0.17

COMPILER_TYPE=	clang

USE_GITHUB=	yes
GH_ACCOUNT=	AccessKit

.include <bsd.port.mk>
