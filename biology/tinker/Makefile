# New ports collection makefile for:   tinker
# Date Created:                26 August 1998
# Whom:                        Glenn Johnson
#
# $FreeBSD$
#

PORTNAME=	tinker
PORTVERSION=	3.9
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://dasher.wustl.edu/pub/
DISTNAME=	${PORTNAME}

MAINTAINER=	gjohnson@srrc.ars.usda.gov

MAKE_ENV+=	HAVE_G2C=yes INSTALL_PROGRAM="${INSTALL_PROGRAM}"

WRKSRC=		${WRKDIR}/tinker/source

MAKEFILE=	${WRKDIR}/tinker/make/Makefile
ALL_TARGET=	all listing
INSTALL_TARGET=	rename

RESTRICTED=	author requests no distribution except from his FTP site

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} If you get a CHECKSUM mismatch, try doing a \'make distclean\' first.
	@${ECHO_MSG} ""

.if defined(WITH_VIEWER)
.if ${XFREE86_VERSION} == 3
BUILD_DEPENDS+=	imake:${PORTSDIR}/devel/imake
.elif ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	imake:${PORTSDIR}/devel/imake-4
.endif
PLIST=		${PKGDIR}/pkg-plist.viewer
USE_XLIB=	yes
post-build:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/build_viewer
.else
pre-extract:
	@${ECHO} ""
	@${ECHO} If you would like to also build
	@${ECHO} the molecular viewer, define WITH_VIEWER.
	@${ECHO} ""
.endif

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
	@${INSTALL_DATA} ${WRKDIR}/tinker/doc/*.gz \
${PREFIX}/share/doc/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/doc/*.pdf \
${PREFIX}/share/doc/tinker
	@${INSTALL_DATA} ${WRKDIR}/tinker/doc/*.ps \
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

	@${ECHO} ""
	@${ECHO} "   **********************************************************"
	@${ECHO} "       The author requests that you return a license form    "
	@${ECHO} "       to him if you find Tinker to be useful.               "
	@${ECHO} "                                                             "
	@${ECHO} "       See ${PREFIX}/share/doc/tinker for license forms.     "
	@${ECHO} "   **********************************************************"
	@${ECHO} ""

.include <bsd.port.mk>
