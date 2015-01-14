# Created by: Radim Kolar <hsn@sendmail.cz>
# $FreeBSD$

PORTNAME=	dhrystone
PORTVERSION=	2.1
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_NETLIB}
MASTER_SITE_SUBDIR=benchmark
DISTNAME=	dhry-c
EXTRACT_SUFX=

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Computing benchmark for integer operations

LICENSE=	BSD2CLAUSE

EXTRACT_CMD=	${MKDIR} ${WRKSRC};cd ${WRKSRC} && ${SH}

PLIST_FILES=	bin/dhry

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	RATIONALE submit.frm README_C VARIATIONS
.endif

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -c dhry_1.c && \
		${CC} ${CFLAGS} -c dhry_2.c && \
		${CC} -o dhry *.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhry ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
