# New ports collection makefile for:   tinker
# Date Created:                26 August 1998
# Whom:                        Glenn Johnson
#
# $FreeBSD$
#

PORTNAME=	tinker
PORTVERSION=	4.2.20040908
CATEGORIES=	biology
MASTER_SITES=	ftp://dasher.wustl.edu/pub/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general purpose molecular modelling package

BUILD_DEPENDS=	imake:${X_IMAKE_PORT}

MAKE_ENV+=	HAVE_G2C=yes INSTALL_PROGRAM="${INSTALL_PROGRAM}"

WRKSRC=		${WRKDIR}/tinker/source

MAKEFILE=	${WRKDIR}/tinker/make/Makefile
ALL_TARGET=	all listing
INSTALL_TARGET=	rename
USE_REINPLACE=	yes
RESTRICTED=	author requests no distribution except from his FTP site

DOCS=		README *.pdf *.txt release*
SAMPLES=	README clean.make *.1st *.boat *.cell *.chair *.dat *.dyn0	\
		*.key *.log *.pdb *.run *.xyz
BENCHES=	README *.dyn0 *.log *.key *.run *.xyz results*

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_FLAGS)
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations
.if (${ARCH} == "i386")
FFLAGS+=	-mfancy-math-387 -malign-double
.endif # i386
.endif

.if defined(WITH_VIEWER)
USE_XLIB=	yes
PLIST_SUB+=	WITH_VIEWER=""
post-build:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/build_viewer
.else
PLIST_SUB+=	WITH_VIEWER="@comment "
pre-extract:
	@${ECHO_MSG} ""
	@${ECHO_MSG} If you would like to also build
	@${ECHO_MSG} the molecular viewer, define WITH_VIEWER.
	@${ECHO_MSG} ""
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_FLAGS)
	@${ECHO_MSG} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
.endif

post-extract:
	${CHMOD} -R u+w ${WRKDIR}/tinker

post-patch:
	@${REINPLACE_CMD} -e 's,%%FFLAGS%%,${FFLAGS},g' ${WRKSRC}/../make/Makefile

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
.if defined(WITH_VIEWER)
	@${MKDIR} ${DATADIR}/rasmol
	@${INSTALL_PROGRAM} ${WRKDIR}/tinker/rasmol/tview-* ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${FILESDIR}/tview ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKDIR}/tinker/rasmol/rasmol.hlp \
		${DATADIR}/rasmol
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
