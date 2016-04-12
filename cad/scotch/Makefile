# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	scotch
DISTVERSION=	5.1.12b_esmumps
PORTREVISION=	5
CATEGORIES=	cad science
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/28978/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Package for graph and mesh partitioning and sparse matrix ordering

LICENSE=	CeCILL_C
LICENSE_NAME=	CeCILL-C
LICENSE_FILE=	${WRKSRC}/doc/CeCILL-C_V1-en.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS=	gbase-0.* gmap-2006.*

USES=		gmake

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS EXAMPLES

.if defined(MAINTAINER_MODE)
USES+=		fortran
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:C/b_/_/}
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	scotch

CFLAGS+=	-I${LOCALBASE}/include

VER=		${PORTVERSION:R}
BINS=		acpl amk_ccc amk_fft2 amk_grf amk_hy amk_m2 amk_p2 atst	\
		gbase gcv gmap gmk_hy gmk_m2 gmk_m3 gmk_msh gmk_ub2	\
		gmtst gord gotst gout gpart gscat gtst mcv mmk_m2 mmk_m3\
		mord mtst
INCS=		esmumps.h scotch.h scotchf.h
LIBS=		libesmumps.a libscotch.a libscotcherr.a libscotcherrexit.a libscotchmetis.a
DOCVER=		${PORTVERSION:R:R:R}
PORTDOCS=	ptscotch_user${DOCVER}.pdf scotch_user${DOCVER}.pdf
EXAMPLES=	scotch_example_1.f scotch_example_2.f90

.if !defined(WITHOUT_MPI)
LIB_DEPENDS+=	libmpich.so:net/mpich2

ALL_TARGET+=	ptscotch
MAKE_ENV+=	PATH=${PATH}:${LOCALBASE}/mpich2/bin

INCS+=		ptscotch.h ptscotchf.h
LIBS+=		libptesmumps.a libptscotch.a libptscotcherr.a libptscotcherrexit.a	\
		libptscotchparmetis.a
BINS+=		dggath dgmap dgord dgpart dgscat dgtst

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

do-install:
	${INSTALL_PROGRAM} ${BINS:S|^|${WRKSRC}/bin/|} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${INCS:S|^|${WRKSRC}/include/|} ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${LIBS:S|^|${WRKSRC}/lib/|} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${STAGEDIR}${MANPREFIX}/man/man1
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}
do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/grf ${STAGEDIR}${EXAMPLESDIR}/tgt
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/examples/|} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/grf/* ${STAGEDIR}${EXAMPLESDIR}/grf
	${INSTALL_DATA} ${WRKSRC}/tgt/* ${STAGEDIR}${EXAMPLESDIR}/tgt

.if defined(MAINTAINER_MODE)
regression-test:	install
	(amk_ccc 3 | acpl - ${WRKDIR}/ccc3.tgt &&	\
	${GUNZIP_CMD} -c ${EXAMPLESDIR}/grf/bump.grf.gz |	\
	gmap - ${WRKDIR}/ccc3.tgt ${WRKDIR}/brol.map)
	(cd ${WRKSRC}/examples &&	\
	${FC} -o scotch_test scotch_example_1.f ${FCFLAGS}	\
		-I${PREFIX}/include ${LDFLAGS} -L${PREFIX}/lib -lscotch -lscotcherr -lm	\
	&& ./scotch_test)
. if !defined(WITHOUT_MPI)
	(${GUNZIP_CMD} -c ${EXAMPLESDIR}/grf/bump.grf.gz | dgtst)
. endif
.endif

.include <bsd.port.mk>
