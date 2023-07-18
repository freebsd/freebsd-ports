PORTNAME=	bde
DISTVERSION=	3.117.0.0
CATEGORIES=	devel
PKGNAMEPREFIX=	bloomberg-

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	foundational C++ libraries used at Bloomberg
WWW=		https://github.com/bloomberg/bde

LICENSE=	APACHE20

USES=		cmake python:3.8+,build pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	bloomberg
GH_PROJECT=	bde-tools:tools

_tools=		${WRKDIR}/bde-tools-${DISTVERSION}

CMAKE_ARGS=	\
		-DBBS_ENV_MARKER=ON \
		-DBBS_BUILD_SYSTEM=ON \
		-DBDE_BUILD_TARGET_CPP17=1 \
		-DBdeBuildSystem_DIR=${_tools}/BdeBuildSystem/ \
		-DCMAKE_TOOLCHAIN_FILE=${_tools}/BdeBuildSystem/toolchains/linux/clang-default.cmake \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DCMAKE_INSTALL_LIBDIR=lib \
		--log-level=ERROR

.include <bsd.port.mk>
