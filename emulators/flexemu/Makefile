PORTNAME=	flexemu
DISTVERSIONPREFIX=	V
DISTVERSION=	3.31
CATEGORIES=	emulators

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	MC6809 emulator running FLEX operating system
WWW=		https://flexemu.neocities.org/

LICENSE=	GPLv2

USES=		cmake compiler:c++17-lang desktop-file-utils gl \
		ncurses qt:6 shared-mime-info xorg
USE_GITHUB=	yes
GH_ACCOUNT=	aladur
GH_TUPLE=	fmtlib:fmt:e424e3f:fmt/fmt \
		google:googletest:b514bdc:googletest/googletest \
		open-source-parsers:jsoncpp:8214f71:jsoncpp/jsoncpp
USE_GL=		gl opengl
USE_QT=		base declarative
USE_XORG=	ice sm x11

# The minimum supported clang-tidy version is 19.0.0
CMAKE_ARGS+=	-DFLEXEMU_QT_MAJOR_VERSION=6 \
		-DCLANG_TIDY=${LOCALBASE}/bin/clang-tidy${COMPILER_VERSION:C/.$//} \
		-DRUN_CLANG_TIDY=${LOCALBASE}/llvm${COMPILER_VERSION:C/.$//}/bin/run-clang-tidy

# test target should be executed as a regular user
TEST_TARGET=	test

.include <bsd.port.mk>
