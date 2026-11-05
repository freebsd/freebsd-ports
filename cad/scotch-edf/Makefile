PORTNAME=	scotch
DISTVERSION=	7.0.4
CATEGORIES=	cad science
PKGNAMESUFFIX=	-edf

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Package for graph and mesh partitioning and sparse matrix ordering
WWW=		https://www.labri.fr/perso/pelegrin/scotch/

LICENSE=	CeCILL_C
LICENSE_NAME=	CeCILL-C
LICENSE_FILE=	${WRKSRC}/LICENSE_en.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		bison fortran gmake localbase
BINARY_ALIAS=	gfortran=gfortran${_GCC_VER}

CONFLICTS_INSTALL=	gbase gmap # bin/gbase bin/gmap

DEPRECATED=	consumers should switch to cad/scotch
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS EXAMPLES MPICH
OPTIONS_DEFAULT=MPICH
OPTIONS_SUB=	yes

TAGNAME=	82ec87f558f4acb7ccb69a079f531be380504c92
WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}-${TAGNAME}
CFLAGS+=	-DINTSIZE64 -DCOMMON_OS_FREEBSD
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
TEST_WRKSRC=	${BUILD_WRKSRC}
ALL_TARGET=	esmumps
TEST_TARGET=	check	# To be run after install
MAKE_ENV=	prefix=${STAGEDIR}${PREFIX} mandir=${STAGEDIR}${PREFIX}/share/man	\
		-DSCOTCH_PTHREAD_NUMBER=2
USE_LDCONFIG=	yes

DOCVER=		${PORTVERSION:R}
PORTDOCS=	ptscotch_user${DOCVER}.pdf scotch_user${DOCVER}.pdf scotch_example.f
LIBS=		esmumps scotch scotcherr scotcherrexit scotchmetisv3 scotchmetisv5

MPICH_USES=		mpi:mpich
MPICH_ALL_TARGET=	ptesmumps
MPICH_TEST_TARGET=	ptcheck
MPICH_LIBS+=	ptesmumps ptscotch ptscotcherr ptscotcherrexit ptscotchparmetisv3

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
MF=	i686
.else
MF=	x86-64
.endif

pre-everything::
.if !defined(WITHOUT_MPICH)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITHOUT_MPI if PT-Scotch is not wanted."
	@${ECHO_MSG}
.endif

pre-configure:
	${LN} -sf ${WRKSRC}/src/Make.inc/Makefile.inc.${MF}_pc_freebsd	\
		${WRKSRC}/src/Makefile.inc
	${REINPLACE_CMD} -E -e 's|cd (.*) ; * \$$\(MAKE\)|\$$(MAKE) -C \1|'	\
		-e 's|\&\& \$$\(MAKE\)||' ${WRKSRC}/src/Makefile

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* ${STAGEDIR}${PREFIX}/lib/lib*
.for l in ${LIBS}
	${MV} ${STAGEDIR}${PREFIX}/lib/lib${l}.so ${STAGEDIR}${PREFIX}/lib/lib${l}.so.0
	${LN} -sf lib${l}.so.0 ${STAGEDIR}${PREFIX}/lib/lib${l}.so
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/grf ${STAGEDIR}${EXAMPLESDIR}/tgt
	${INSTALL_DATA} ${WRKSRC}/grf/* ${STAGEDIR}${EXAMPLESDIR}/grf
	${INSTALL_DATA} ${WRKSRC}/tgt/* ${STAGEDIR}${EXAMPLESDIR}/tgt

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
