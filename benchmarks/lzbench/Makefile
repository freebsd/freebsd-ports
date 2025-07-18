PORTNAME=	lzbench
PORTVERSION=	2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	benchmarks

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	In-memory benchmark of open-source LZ77/LZSS/LZMA compressors
WWW=		https://github.com/inikep/lzbench

USES=		compiler:c11 gmake
USE_GITHUB=	yes
GH_ACCOUNT=	inikep
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/lzbench
PORTDOCS=	CHANGELOG README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/PROGOS/s,Linux,${OPSYS},' \
		${WRKSRC}/bench/lzbench.h
	@${REINPLACE_CMD} -e 's,shell echo|$$(CC),& 2>/dev/null,' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^#if defined(__FreeBSD__)/,+1s,machine,sys,' \
		${WRKSRC}/misc/kanzi-cpp/src/Memory.hpp
	@${REINPLACE_CMD} -e '/^#if/s,defined(__aarch64__),& ||\
		__riscv_xlen == 64,' ${WRKSRC}/lz/tornado/Common.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lzbench ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
