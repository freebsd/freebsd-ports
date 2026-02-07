PORTNAME=	dps8m
DISTVERSIONPREFIX=	R
DISTVERSION=	3.1.0
CATEGORIES=	emulators

MAINTAINER=	gspurki@gmail.com
COMMENT=	SIMH based simulator for the Honeywell h6180/dps8m Multics processor
WWW=		https://dps8m.gitlab.io/dps8m

LICENSE=	ICU
LICENSE_NAME=	ICU license
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	__uint128_t is only implemented on 64-bit platforms

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		gmake
USE_GITLAB=	yes

CFLAGS_powerpc64=	-Datomic_testandset_64=atomic_testandset_long
CFLAGS_powerpc64le=	-Datomic_testandset_64=atomic_testandset_long
CFLAGS_riscv64=		-Datomic_testandset_64=atomic_testandset_long

MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/dps8 \
		bin/prt2pdf \
		bin/punutil

MAKE_ARGS=	V=1 NO_LTO=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dps8/dps8 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/prt2pdf/prt2pdf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/punutil/punutil ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
