# New ports collection makefile for:	scotch
# Date created:		Thu 2 feb 2006
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	scotch
PORTVERSION=	5.0.6
PORTREVISION=	5
CATEGORIES=	cad science
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/3795/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A package for graph and mesh partitioning and sparse matrix ordering

USE_GMAKE=	yes
.if defined(MAINTAINER_MODE)
USE_FORTRAN=	yes
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:R}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/bin
ALL_TARGET=	scotch

VER=		${PORTVERSION:R}
BINS=		acpl amk_ccc amk_fft2 amk_grf amk_hy amk_m2 amk_p2 atst	\
		gbase gcv gmap gmk_hy gmk_m2 gmk_m3 gmk_msh gmk_ub2 gmtst gord\
		gotst gout gtst mcv mmk_m2 mmk_m3 mord mtst
INCS=		common.h scotch.h scotchf.h
LIBS=		libcommon.a libscotch.a libscotcherr.a libscotcherrcom.a\
		libscotchmetis.a
LICDOCS=	CeCILL-C_V1-en.txt CeCILL-C_V1-fr.txt
PORTDOCS=	scotch_user${VER}.pdf
EXAMPLES=	scotch_example.f

PKGMESSAGE=	${WRKSRC}/LICENSE_en.txt

.if !defined(WITHOUT_MPI)
BUILD_DEPENDS+=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/lib/libmpich.so:${PORTSDIR}/net/mpich2

ALL_TARGET+=	ptscotch

INCS+=		ptscotch.h ptscotchf.h
LIBS+=		libptscotch.a libptscotcherr.a
BINS+=		dgord dgscat dgtst

PLIST_SUB+=	MPI=""
.else
PLIST_SUB+=	MPI="@comment "
.endif

pre-everything::
.if !defined(WITHOUT_MPI)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITHOUT_MPI if PT-Scotch is not wanted."
	@${ECHO_MSG}
.endif

pre-configure:
	${LN} -sf ${WRKSRC}/src/Make.inc/Makefile.inc.freebsd	\
		${WRKSRC}/src/Makefile.inc
	${REINPLACE_CMD} -e 's|in subdirectory "doc"|under ${DATADIR}|'	\
		${WRKSRC}/LICENSE_en.txt

do-install:
	${INSTALL_PROGRAM} ${BINS:S|^|${INSTALL_WRKSRC}/|} ${PREFIX}/bin
	${INSTALL_DATA} ${INCS:S|^|${INSTALL_WRKSRC}/|} ${PREFIX}/include
	${INSTALL_DATA} ${LIBS:S|^|${INSTALL_WRKSRC}/|} ${PREFIX}/lib
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${LICDOCS:S|^|${WRKSRC}/doc/|} ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/grf ${EXAMPLESDIR}/tgt
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/doc/|} ${EXAMPLESDIR}
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
	(cd ${WRKSRC}/doc &&	\
	${FC} -o scotch_test scotch_example.f	\
		-I${PREFIX}/include -L${PREFIX}/lib -lscotch -lscotcherr -lm	\
	&& ./scotch_test)
. if !defined(WITHOUT_MPI)
	(${GUNZIP_CMD} -c ${EXAMPLESDIR}/grf/bump.grf.gz | dgtst)
. endif
.endif

.include <bsd.port.mk>
