# New ports collection makefile for:   tinker
# Date Created:                26 August 1998
# Whom:                        Glenn Johnson
#
# $FreeBSD$
#

PORTNAME=	tinker
PORTVERSION=	5.1.09
CATEGORIES=	biology
MASTER_SITES=	http://dasher.wustl.edu/tinker/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general purpose molecular modelling package

MAKE_ENV+=	HAVE_G2C=yes INSTALL_PROGRAM="${INSTALL_PROGRAM}"

WRKSRC=		${WRKDIR}/tinker/source

MAKEFILE=	${WRKDIR}/tinker/make/Makefile
ALL_TARGET=	all listing
INSTALL_TARGET=	rename
RESTRICTED=	author requests no distribution except from his FTP site

DOCS=		0README *.pdf *.txt announce/release*
SAMPLES=	0README *.make *.dyn *.int *.frac *.key *.seq *.pdb *.run *.xyz
BENCHES=	0README *.dyn0 *.log *.key *.run *.xyz results*

.include <bsd.port.pre.mk>

USE_FORTRAN=	yes

.if defined(WITH_OPTIMIZED_FLAGS)
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations
.if (${ARCH} == "i386")
FFLAGS+=	-mfancy-math-387 -malign-double
.endif # i386
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_FLAGS)
	@${ECHO_MSG} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
.endif

post-extract:
	${CHMOD} -R u+w ${WRKDIR}/tinker

post-patch:
	@${REINPLACE_CMD} -e 's|%%FFLAGS%%|${FFLAGS}|g' ${WRKSRC}/../make/Makefile

post-install:
	@${MKDIR} ${DATADIR}/params
	@${INSTALL_DATA} ${WRKDIR}/tinker/source/tinker.txt \
		${DATADIR}
	@${INSTALL_DATA} ${WRKDIR}/tinker/params/* \
		${DATADIR}/params
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${DATADIR}/bench
	@${MKDIR} ${DATADIR}/test
	@${INSTALL_DATA} ${DOCS:S|^|${WRKDIR}/tinker/doc/|} ${DOCSDIR}
	@${INSTALL_DATA} ${SAMPLES:S|^|${WRKDIR}/tinker/example/|} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${BENCHES:S|^|${WRKDIR}/tinker/bench/|} ${DATADIR}/bench
	@${INSTALL_DATA} ${WRKDIR}/tinker/test/* ${DATADIR}/test
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   **********************************************************"
	@${ECHO_MSG} "       The author requests that you return a license form    "
	@${ECHO_MSG} "       to him if you find Tinker to be useful.               "
	@${ECHO_MSG} "                                                             "
	@${ECHO_MSG} "       See ${DOCSDIR} for license forms.     "
	@${ECHO_MSG} "   **********************************************************"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
