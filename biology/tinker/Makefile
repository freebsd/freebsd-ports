# New ports collection makefile for:   tinker
# Date Created:                26 August 1998
# Whom:                        Glenn Johnson
#
# $FreeBSD$
#

PORTNAME=	tinker
PORTVERSION=	4.1
CATEGORIES=	biology
MASTER_SITES=	ftp://dasher.wustl.edu/pub/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general purpose molecular modelling package

BUILD_DEPENDS=	imake:${X_IMAKE_PORT}

BROKEN=		Distfile has been updated to version 4.2.  Port needs update

MAKE_ENV+=	HAVE_G2C=yes INSTALL_PROGRAM="${INSTALL_PROGRAM}"

WRKSRC=		${WRKDIR}/tinker/source

MAKEFILE=	${WRKDIR}/tinker/make/Makefile
ALL_TARGET=	all listing
INSTALL_TARGET=	rename
USE_REINPLACE=	yes
RESTRICTED=	author requests no distribution except from his FTP site

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} If you get a CHECKSUM mismatch, try doing a \'make distclean\' first.
	@${ECHO_MSG} ""

.include <bsd.port.pre.mk>

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

.if defined(WITH_OPTIMIZED_FLAGS)
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations
.if (${MACHINE_ARCH} == "i386")
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
	@${REINPLACE_CMD} -e 's,%%FFLAGS%%,${FFLAGS},g' ${WRKSRC}/../make/Makefile

post-install:
	@${MKDIR} ${PREFIX}/share/tinker
	@${MKDIR} ${PREFIX}/share/tinker/params
	@${INSTALL_DATA} ${WRKDIR}/tinker/source/tinker.txt \
${PREFIX}/share/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/params/* \
${PREFIX}/share/tinker/params

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tinker
	@${MKDIR} ${PREFIX}/share/examples/tinker
	@${MKDIR} ${PREFIX}/share/tinker/bench
	@${MKDIR} ${PREFIX}/share/tinker/test
	@${INSTALL_DATA} ${WRKDIR}/tinker/doc/README \
${PREFIX}/share/doc/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/doc/*.pdf \
${PREFIX}/share/doc/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/doc/*.txt \
${PREFIX}/share/doc/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/doc/release* \
${PREFIX}/share/doc/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/example/README \
${PREFIX}/share/examples/tinker
	@${INSTALL_SCRIPT} ${WRKDIR}/tinker/example/clean.make \
${PREFIX}/share/examples/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/example/*.1st \
${PREFIX}/share/examples/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/example/*.boat \
${PREFIX}/share/examples/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/example/*.cell \
${PREFIX}/share/examples/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/example/*.chair \
${PREFIX}/share/examples/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/example/*.dat \
${PREFIX}/share/examples/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/example/*.dyn0 \
${PREFIX}/share/examples/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/example/*.key \
${PREFIX}/share/examples/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/example/*.log \
${PREFIX}/share/examples/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/example/*.pdb \
${PREFIX}/share/examples/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/example/*.xyz \
${PREFIX}/share/examples/tinker
	@${INSTALL_SCRIPT} ${WRKDIR}/tinker/example/*.run \
${PREFIX}/share/examples/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/bench/README \
${PREFIX}/share/tinker/bench
	@${INSTALL_DATA} ${WRKDIR}/tinker/bench/*.dyn0 \
${PREFIX}/share/tinker/bench
	@${INSTALL_DATA} ${WRKDIR}/tinker/bench/*.log \
${PREFIX}/share/tinker/bench
	@${INSTALL_DATA} ${WRKDIR}/tinker/bench/*.key \
${PREFIX}/share/tinker/bench
	@${INSTALL_SCRIPT} ${WRKDIR}/tinker/bench/*.run \
${PREFIX}/share/tinker/bench
	@${INSTALL_DATA} ${WRKDIR}/tinker/bench/*.xyz \
${PREFIX}/share/tinker/bench
	@${INSTALL_DATA} ${WRKDIR}/tinker/bench/results* \
${PREFIX}/share/tinker/bench
	@${INSTALL_DATA} ${WRKDIR}/tinker/test/* ${PREFIX}/share/tinker/test
.endif

.if defined(WITH_VIEWER)
	@${MKDIR} ${PREFIX}/share/tinker/rasmol
	@${INSTALL_PROGRAM} ${WRKDIR}/tinker/rasmol/tview-* ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${FILESDIR}/tview ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKDIR}/tinker/rasmol/rasmol.hlp \
		${PREFIX}/share/tinker/rasmol
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   **********************************************************"
	@${ECHO_MSG} "       The author requests that you return a license form    "
	@${ECHO_MSG} "       to him if you find Tinker to be useful.               "
	@${ECHO_MSG} "                                                             "
	@${ECHO_MSG} "       See ${PREFIX}/share/doc/tinker for license forms.     "
	@${ECHO_MSG} "   **********************************************************"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
