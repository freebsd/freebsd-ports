# Created by: Glenn Johnson
# $FreeBSD$

PORTNAME=	tinker
PORTVERSION=	6.1.01
CATEGORIES=	biology
MASTER_SITES=	http://dasher.wustl.edu/tinker/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general purpose molecular modelling package

RESTRICTED=	author requests no distribution except from his FTP site

OPTIONS_DEFINE=	OPTIMIZED_FFLAGS DATA DOCS EXAMPLES
OPTIONS_DEFAULT=DATA
OPTIMIZED_FFLAGS_DESC=	compilation optimizations

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/source
INSTALL_WRKSRC=	${WRKSRC}/source

USE_FORTRAN=	yes
MAKE_ENV=	HAVE_G2C=yes
MAKEFILE=	${WRKSRC}/make/Makefile
ALL_TARGET=	all listing
INSTALL_TARGET=	rename
MAKE_JOBS_SAFE=	yes

SUB_FILES=	pkg-message

DOCS=		0README *.pdf *.txt
SAMPLES=	0README *.make *.dyn *.int *.frac *.key *.seq *.pdb *.xyz
BENCHES=	0README *.dyn0 *.log *.key *.run *.xyz results*

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_FFLAGS}
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations
.if (${ARCH} == "i386")
FFLAGS+=	-mfancy-math-387 -malign-double
.endif # i386
.endif

.if empty(PORT_OPTIONS:MDATA)
NOPORTDATA=	yes
.endif

post-extract:
	@${CHMOD} -R u+w ${WRKSRC}

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/tinker.txt ${DATADIR}
	@${MKDIR} ${DATADIR}/params
	${INSTALL_DATA} ${WRKSRC}/params/* ${DATADIR}/params
.if ${PORT_OPTIONS:MDATA}
	@${MKDIR} ${DATADIR}/bench
	${INSTALL_DATA} ${BENCHES:S|^|${WRKSRC}/bench/|} ${DATADIR}/bench
	@${MKDIR} ${DATADIR}/test
	${INSTALL_DATA} ${WRKSRC}/test/* ${DATADIR}/test
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${SAMPLES:S|^|${WRKSRC}/example/|} ${EXAMPLESDIR}
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
