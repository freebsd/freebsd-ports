PORTNAME=	fcitx5-keykey
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
CATEGORIES=	chinese textproc

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Keykey support for Fcitx5
WWW=		https://github.com/polobread/KeyKey

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/../../../LICENSE.txt
LICENSE_FILE_MIT=	${WRKSRC}/../../../LICENSING.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libFcitx5Core.so:textproc/fcitx5

USES=		cmake compiler:c++17-lang iconv pkgconfig python:build sqlite

WRKSRC_SUBDIR=	Source/Loaders/Linux-IME

USE_GITHUB=	yes
GH_ACCOUNT=	polobread
GH_PROJECT=	KeyKey
CMAKE_ARGS+=	-DBUILD_TESTING=OFF -DKEYKEY_BUILD_FCITX5=ON

.include <bsd.port.mk>
