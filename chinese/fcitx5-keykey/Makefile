PORTNAME=	fcitx5-keykey
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	chinese textproc

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Keykey support for Fcitx5
WWW=		https://github.com/polobread/KeyKey

LICENSE=	BSD3CLAUSE MIT UNICODE
LICENSE_COMB=	multi
LICENSE_NAME_UNICODE=	Unicode License v3
LICENSE_FILE_BSD3CLAUSE=	${KEYKEY_ROOT}/LICENSE.txt
LICENSE_FILE_MIT=	${KEYKEY_ROOT}/LICENSES/MIT.txt
LICENSE_FILE_UNICODE=	${KEYKEY_ROOT}/Source/Shared/Unicode-LICENSE.txt
LICENSE_PERMS_UNICODE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libFcitx5Core.so:textproc/fcitx5 \
		libfontconfig.so:x11-fonts/fontconfig \
		libjson-c.so:devel/json-c
RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USES=		cargo cmake compiler:c++17-lang gnome iconv pkgconfig python \
		sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	polobread
GH_PROJECT=	KeyKey
USE_GNOME=	gtk30 pango pygobject3

WRKSRC_SUBDIR=	Source/Loaders/Linux-IME
# the repository root, where the Rust core and the patches are
KEYKEY_ROOT=	${WRKSRC}/../../..
PATCH_WRKSRC=	${KEYKEY_ROOT}

# Guanyinma, the Rust core, is built by CMake through the core's own script;
# the cargo framework only vendors the locked crates. A subdirectory turns
# off its build, install and test, and puts .cargo/config.toml, which points
# crates-io at the vendored crates, in Source, above the crate cargo runs in.
CARGO_SRC_SUBDIR=	../../Guanyinma
MAKE_ENV+=	${CARGO_ENV}

CMAKE_ARGS+=	-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_ON=	KEYKEY_BUILD_FCITX5 KEYKEY_GUANYINMA_OFFLINE
CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
