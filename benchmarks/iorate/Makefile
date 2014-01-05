# $FreeBSD$

PORTNAME=	iorate
PORTVERSION=	3.05
CATEGORIES=	benchmarks
MASTER_SITES=	http://sites.google.com/site/vwiorate/downloads/3-05/
DISTNAME=	iorate-${PORTVERSION}-src
EXTRACT_SUFX=	.tar

MAINTAINER=	blttll@gmail.com
COMMENT=	General purpose storage I/O benchmarking tool

USES=		bison
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}"
NO_WRKSUBDIR=	yes

PORTDOCS=	README README.versions

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,^CFLAGS ,&+,' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iorate ${WRKSRC}/ior_rand ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cycle ${WRKSRC}/gen_* ${WRKSRC}/run_* \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.ior ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
