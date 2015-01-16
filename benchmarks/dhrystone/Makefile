# Created by: Radim Kolar <hsn@sendmail.cz>
# $FreeBSD$

PORTNAME=	dhrystone
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	NETLIB/benchmark
DISTNAME=	dhry-c
EXTRACT_SUFX=

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Computing benchmark for integer operations

LICENSE=	BSD2CLAUSE

EXTRACT_CMD=	${SH}
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/dhry

OPTIONS_DEFINE=	DOCS

PORTDOCS=	RATIONALE submit.frm README_C VARIATIONS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhry ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
