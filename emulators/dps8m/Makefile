PORTNAME=	dps8m
DISTVERSIONPREFIX=	R
DISTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Simulator of the 36-bit GE/Honeywell/Bull 600/6000-series mainframes
WWW=		https://dps8m.gitlab.io/dps8m/ \
		https://gitlab.com/dps8m/dps8m/ \
		https://multics-wiki.swenson.org/index.php/Main_Page

LICENSE=	ICU
LICENSE_NAME=	ICU license
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	__uint128_t is only implemented on 64-bit platforms

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		gmake
USE_GITLAB=	yes

MAKEFILE=	GNUmakefile
MAKE_ARGS=	NO_LTO=1 V=1

CFLAGS_powerpc64=	-Datomic_testandset_64=atomic_testandset_long
CFLAGS_powerpc64le=	-Datomic_testandset_64=atomic_testandset_long
CFLAGS_riscv64=		-Datomic_testandset_64=atomic_testandset_long

PLIST_FILES=	bin/dps8 \
		bin/prt2pdf \
		bin/punutil

do-install:
.for f in dps8/dps8 prt2pdf/prt2pdf punutil/punutil
	${INSTALL_PROGRAM} ${WRKSRC}/src/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
