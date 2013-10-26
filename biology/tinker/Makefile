# Created by: Glenn Johnson
# $FreeBSD$

PORTNAME=	tinker
PORTVERSION=	6.2.06
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	http://dasher.wustl.edu/tinker/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose molecular modelling package

RESTRICTED=	author requests no distribution except from his FTP site

OPTIONS_DEFINE=	OPTIMIZED_FFLAGS DOCS EXAMPLES
OPTIMIZED_FFLAGS_DESC=	compilation optimizations

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/source
INSTALL_WRKSRC=	${WRKSRC}/source

USE_FORTRAN=	yes
MAKE_ENV=	HAVE_G2C=yes
MAKEFILE=	${WRKSRC}/make/Makefile
ALL_TARGET=	all listing
INSTALL_TARGET=	rename

SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_FFLAGS}
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations
.if (${ARCH} == "i386")
FFLAGS+=	-mfancy-math-387 -malign-double
.endif # i386
.endif

post-extract:
	@${CHMOD} -R u+w ${WRKSRC}

pre-build:
	@${RM} -f ${BUILD_WRKSRC}/*.c 

post-install:
	@${MKDIR} ${DATADIR}
	(cd ${INSTALL_WRKSRC} && ${INSTALL_DATA} tinker.txt ${DATADIR})
	@${MKDIR} ${DATADIR}/bench
	(cd ${WRKSRC}/bench && ${INSTALL_DATA} \
		0README *.dyn0 *.log *.key *.run *.xyz results* \
		${DATADIR}/bench)
	@${MKDIR} ${DATADIR}/params
	(cd ${WRKSRC}/params && ${INSTALL_DATA} * ${DATADIR}/params)
	@${MKDIR} ${DATADIR}/test
	(cd ${WRKSRC}/test && ${INSTALL_DATA} * ${DATADIR}/test)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} 0README *.pdf *.txt ${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${INSTALL_DATA} \
		0README *.make *.dyn *.int *.frac *.key *.seq *.pdb *.xyz \
		${EXAMPLESDIR})
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
