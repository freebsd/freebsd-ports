# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	scotch
DISTVERSION=	6.0.4-aster7
CATEGORIES=	cad science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Package for graph and mesh partitioning and sparse matrix ordering

LICENSE=	CeCILL_C
LICENSE_NAME=	CeCILL-C
LICENSE_FILE=	${WRKSRC}/doc/CeCILL-C_V1-en.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS=	gbase-0.* gmap-2015.*

USES=		bison:alias gmake localbase

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS EXAMPLES

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
TEST_WRKSRC=	${BUILD_WRKSRC}
ALL_TARGET=	esmumps
TEST_TARGET=	check
MAKE_ENV=	prefix=${STAGEDIR}${PREFIX} mandir=${STAGEDIR}${PREFIX}/share/man	\
		-DSCOTCH_PTHREAD_NUMBER=2

DOCVER=		${PORTVERSION:R:R}
PORTDOCS=	ptscotch_user${DOCVER}.pdf scotch_user${DOCVER}.pdf scotch_example.f
EXAMPLES=	scotch_example.f

.if !defined(WITHOUT_MPI)
LIB_DEPENDS+=	libmpich.so:net/mpich2

ALL_TARGET+=	ptesmumps
MAKE_ENV+=	PATH=${PATH}:${LOCALBASE}/mpich2/bin
TEST_TARGET+=	ptcheck

PLIST_SUB+=	MPI=""
.else
PLIST_SUB+=	MPI="@comment "
.endif

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
MF=	i686
.else
MF=	x86-64
.endif

pre-everything::
.if !defined(WITHOUT_MPI)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITHOUT_MPI if PT-Scotch is not wanted."
	@${ECHO_MSG}
.endif

pre-configure:
	${REINPLACE_CMD} -e 's/-lthread/-pthread/;s/-lpthread/-pthread/'\
		-e 's/CLIBFLAGS	=/CLIBFLAGS	= -fPIC/'	\
		${WRKSRC}/src/Make.inc/Makefile.inc.${MF}_pc_freebsd
	${LN} -sf ${WRKSRC}/src/Make.inc/Makefile.inc.${MF}_pc_freebsd	\
		${WRKSRC}/src/Makefile.inc
	${REINPLACE_CMD} -E -e 's|cd (.*) ; * \$$\(MAKE\)|\$$(MAKE) -C \1|'	\
		-e 's|\&\& \$$\(MAKE\)||' ${WRKSRC}/src/Makefile

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/grf ${STAGEDIR}${EXAMPLESDIR}/tgt
	${INSTALL_DATA} ${WRKSRC}/grf/* ${STAGEDIR}${EXAMPLESDIR}/grf
	${INSTALL_DATA} ${WRKSRC}/tgt/* ${STAGEDIR}${EXAMPLESDIR}/tgt

.if !defined(WITHOUT_MPI)
pre-test:
. if !exists(${HOME}/.mpd.conf)
	@${ECHO_CMD} "MPD_SECRETWORD=change_on_install" > ${HOME}/.mpd.conf
	${CHMOD} go-r ${HOME}/.mpd.conf
	@${ECHO_MSG} "${HOME}/.mpd.conf has been generated - please change the secret word!"
. endif
	${LOCALBASE}/bin/mpd &
.endif

.if !defined(WITHOUT_MPI)
post-test:
	${LOCALBASE}/bin/mpdallexit
.endif

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
