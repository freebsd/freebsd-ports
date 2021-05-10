PORTNAME=	xbyak
DISTVERSIONPREFIX=	v
DISTVERSION=	5.992
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only JIT assembler for x86/x64 SIMD

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	herumi

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/xbyak/xbyak.h \
		include/xbyak/xbyak_bin2hex.h \
		include/xbyak/xbyak_mnemonic.h \
		include/xbyak/xbyak_util.h \
		lib/cmake/xbyak/xbyak-targets.cmake \
		lib/cmake/xbyak/xbyakConfig.cmake

.include <bsd.port.mk>
