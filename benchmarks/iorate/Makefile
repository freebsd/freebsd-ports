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
FETCH_ARGS=	-Fpr
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}"
NO_WRKSUBDIR=	yes

MAN1=		${PORTNAME}.1
PORTDOCS=	README README.versions

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,^CFLAGS ,&+,' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iorate ${WRKSRC}/ior_rand ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cycle ${WRKSRC}/gen_* ${WRKSRC}/run_* \
		${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.ior ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
