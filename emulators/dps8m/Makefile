PORTNAME=	dps8m
DISTVERSION=	2.0.1rc2.20211124
CATEGORIES=	emulators

MAINTAINER=	gspurki@gmail.com
COMMENT=	SIMH based simulator for the Honeywell h6180/dps8m Multics processor

LICENSE=	ICU
LICENSE_NAME=	ICU license
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	__uint128_t is only implemented on 64-bit platforms

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		gmake

USE_GITLAB=	yes
GL_COMMIT=	572f79bb4f0f84a8b16c3892c894c2b9ed64b458

MAKEFILE=	GNUmakefile

MAKE_ARGS+=	V=1 ATOMICS=BSD

PLIST_FILES=	bin/dps8 \
		bin/prt2pdf \
		bin/punutil

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dps8/dps8 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/prt2pdf/prt2pdf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/punutil/punutil ${STAGEDIR}${PREFIX}/bin

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dps8
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/prt2pdf
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/punutil

.include <bsd.port.mk>
