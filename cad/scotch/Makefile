# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	scotch
DISTVERSION=	5.1.12b_esmumps
PORTREVISION=	1
CATEGORIES=	cad science
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/28978/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A package for graph and mesh partitioning and sparse matrix ordering

LICENSE=	CeCILL_C
LICENSE_NAME=	CeCILL-C
LICENSE_FILE=	${WRKSRC}/doc/CeCILL-C_V1-en.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS=	gbase-0.* gmap-2006.*

USES=		gmake
MAKE_JOBS_UNSAFE=	yes

.if defined(MAINTAINER_MODE)
USE_FORTRAN=	yes
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
LICDOCS=	CeCILL-C_V1-en.txt CeCILL-C_V1-fr.txt
DOCVER=		${PORTVERSION:R:R:R}
PORTDOCS=	ptscotch_user${DOCVER}.pdf scotch_user${DOCVER}.pdf
EXAMPLES=	scotch_example_1.f scotch_example_2.f90

MAN1=		acpl.1 amk_ccc.1 amk_fft2.1 amk_grf.1 amk_hy.1 amk_m2.1 amk_p2.1	\
		atst.1 dggath.1 dgmap.1 dgord.1 dgpart.1 dgscat.1 dgtst.1 gbase.1 gcv.1	\
		gmap.1 gmk_hy.1 gmk_m2.1 gmk_m3.1 gmk_msh.1 gmk_ub2.1 gmtst.1 gord.1	\
		gotst.1 gout.1 gpart.1 gtst.1 mcv.1 mmk_m2.1 mmk_m3.1 mord.1 mtst.1

PKGMESSAGE=	${WRKSRC}/LICENSE_en.txt

.if !defined(WITHOUT_MPI)
LIB_DEPENDS+=	mpich.2:${PORTSDIR}/net/mpich2

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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

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
	${REINPLACE_CMD} -e 's/-lthread/-pthread/;s/-lpthread/-pthread/'	\
		-e 's/CLIBFLAGS	=/CLIBFLAGS	= -fPIC/'	\
		${WRKSRC}/src/Make.inc/Makefile.inc.${MF}_pc_freebsd
	${LN} -sf ${WRKSRC}/src/Make.inc/Makefile.inc.${MF}_pc_freebsd	\
		${WRKSRC}/src/Makefile.inc
	${REINPLACE_CMD} -e 's|in subdirectory "doc"|under ${DATADIR}|'	\
		${WRKSRC}/LICENSE_en.txt

do-install:
	${INSTALL_PROGRAM} ${BINS:S|^|${WRKSRC}/bin/|} ${PREFIX}/bin
	${INSTALL_DATA} ${INCS:S|^|${WRKSRC}/include/|} ${PREFIX}/include
	${INSTALL_DATA} ${LIBS:S|^|${WRKSRC}/lib/|} ${PREFIX}/lib
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${LICDOCS:S|^|${WRKSRC}/doc/|} ${DATADIR}
	${INSTALL_MAN} ${MAN1:S|^|${WRKSRC}/man/man1/|} ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/grf ${EXAMPLESDIR}/tgt
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/examples/|} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/grf/* ${EXAMPLESDIR}/grf
	${INSTALL_DATA} ${WRKSRC}/tgt/* ${EXAMPLESDIR}/tgt
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.if defined(MAINTAINER_MODE)
regression-test:	install
	(amk_ccc 3 | acpl - ${WRKDIR}/ccc3.tgt &&	\
	${GUNZIP_CMD} -c ${EXAMPLESDIR}/grf/bump.grf.gz |	\
	gmap - ${WRKDIR}/ccc3.tgt ${WRKDIR}/brol.map)
	(cd ${WRKSRC}/examples &&	\
	${FC} -o scotch_test scotch_example_1.f	\
		-I${PREFIX}/include -L${PREFIX}/lib -lscotch -lscotcherr -lm	\
	&& ./scotch_test)
. if !defined(WITHOUT_MPI)
	(${GUNZIP_CMD} -c ${EXAMPLESDIR}/grf/bump.grf.gz | dgtst)
. endif
.endif

.include <bsd.port.post.mk>
