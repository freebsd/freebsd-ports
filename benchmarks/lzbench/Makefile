PORTNAME=	lzbench
PORTVERSION=	1.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	benchmarks

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	In-memory benchmark of open-source LZ77/LZSS/LZMA compressors

USES=		compiler:c11 gmake
USE_GITHUB=	yes
GH_ACCOUNT=	inikep

PLIST_FILES=	bin/lzbench
PORTDOCS=	NEWS README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/PROGOS/s,Linux,${OPSYS},' \
		${WRKSRC}/_lzbench/lzbench.h
	@${REINPLACE_CMD} -e 's,shell echo|$$(CC),& 2>/dev/null,' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/pithy_Load64/s,vld1_u64(,&(uint64_t *),' \
		${WRKSRC}/pithy/pithy.cpp
	@${REINPLACE_CMD} -e '/^#if/s,defined(__aarch64__),& ||\
		__riscv_xlen == 64,' ${WRKSRC}/tornado/Common.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lzbench ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
