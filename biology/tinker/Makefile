# New ports collection makefile for:   tinker
# Version required:    3.6
# Date Created:                26 August 1998
# Whom:                        Glenn Johnson
#
# $Id$
#

DISTNAME=      tinker
PKGNAME=       tinker-3.6
CATEGORIES=    biology
MASTER_SITES=  ftp://dasher.wustl.edu/pub/

MAINTAINER=    gjohnson@nola.srrc.usda.gov

LIB_DEPENDS=	U77:${PORTSDIR}/devel/libU77

# If you have EGCS installed you can uncomment the following
# line and comment out the LIB_DEPENDS line above
#BUILD_DEPENDS=	g77:${PORTSDIR}/lang/egcs

.include <bsd.port.pre.mk>

WRKSRC=                ${WRKDIR}/tinker/source

MAKEFILE=      ${WRKDIR}/tinker/make/Makefile
ALL_TARGET=    all listing
INSTALL_TARGET=        rename

RESTRICTED=    author requests no distribution except from his FTP site

post-install:
	${MKDIR} ${PREFIX}/share/tinker/params
	${INSTALL_DATA} ${WRKDIR}/tinker/params/* \
${PREFIX}/share/tinker/params
	${INSTALL_DATA} ${WRKDIR}/tinker/source/tinker.txt \
${PREFIX}/share/tinker
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/tinker/doc
	${MKDIR} ${PREFIX}/share/tinker/example
	${MKDIR} ${PREFIX}/share/tinker/bench
	${MKDIR} ${PREFIX}/share/tinker/test
	${INSTALL_DATA} ${WRKDIR}/tinker/doc/README \
${PREFIX}/share/tinker/doc
	${INSTALL_DATA} ${WRKDIR}/tinker/doc/*.ps \
${PREFIX}/share/tinker/doc
	${INSTALL_DATA} ${WRKDIR}/tinker/doc/*.Z \
${PREFIX}/share/tinker/doc
	${INSTALL_DATA} ${WRKDIR}/tinker/doc/*.txt \
${PREFIX}/share/tinker/doc
	${INSTALL_DATA} ${WRKDIR}/tinker/example/README \
${PREFIX}/share/tinker/example
	${INSTALL_DATA} ${WRKDIR}/tinker/example/anion.dyn0 \
${PREFIX}/share/tinker/example
	${INSTALL_DATA} ${WRKDIR}/tinker/example/*.in* \
${PREFIX}/share/tinker/example
	${INSTALL_DATA} ${WRKDIR}/tinker/example/*.key \
${PREFIX}/share/tinker/example
	${INSTALL_DATA} ${WRKDIR}/tinker/example/*.log \
${PREFIX}/share/tinker/example
	${INSTALL_DATA} ${WRKDIR}/tinker/example/*.xyz \
${PREFIX}/share/tinker/example
	${INSTALL_DATA} ${WRKDIR}/tinker/example/argon.1st \
${PREFIX}/share/tinker/example
	${INSTALL_DATA} ${WRKDIR}/tinker/example/crambin.pdb \
${PREFIX}/share/tinker/example
	${INSTALL_DATA} ${WRKDIR}/tinker/example/cyclohex.boat \
${PREFIX}/share/tinker/example
	${INSTALL_DATA} ${WRKDIR}/tinker/example/cyclohex.chair \
${PREFIX}/share/tinker/example
	${INSTALL_DATA} ${WRKDIR}/tinker/example/formamide.cell \
${PREFIX}/share/tinker/example
	${INSTALL_SCRIPT} ${WRKDIR}/tinker/example/clean.make \
${PREFIX}/share/tinker/example
	${INSTALL_SCRIPT} ${WRKDIR}/tinker/example/*.run \
${PREFIX}/share/tinker/example
	${INSTALL_DATA} ${WRKDIR}/tinker/bench/*.input \
${PREFIX}/share/tinker/bench
	${INSTALL_DATA} ${WRKDIR}/tinker/bench/*.key \
${PREFIX}/share/tinker/bench
	${INSTALL_DATA} ${WRKDIR}/tinker/bench/*.xyz \
${PREFIX}/share/tinker/bench
	${INSTALL_DATA} ${WRKDIR}/tinker/bench/water.dyn0 \
${PREFIX}/share/tinker/bench
	${INSTALL_DATA} ${WRKDIR}/tinker/bench/results* \
${PREFIX}/share/tinker/bench
	${INSTALL_SCRIPT} ${WRKDIR}/tinker/bench/*.run \
${PREFIX}/share/tinker/bench
	${INSTALL_DATA} ${WRKDIR}/tinker/test/* ${PREFIX}/share/tinker/test
.endif
	@${ECHO} ""
	@${ECHO} "   **********************************************************"
	@${ECHO} "       The author requests that you return a license form    "
	@${ECHO} "          to him if you find Tinker to be useful.            "
	@${ECHO} "                                                             "
	@${ECHO} "       See ${PREFIX}/share/tinker/doc for license forms.     "
	@${ECHO} "   **********************************************************"
	@${ECHO} ""

.include <bsd.port.post.mk>
