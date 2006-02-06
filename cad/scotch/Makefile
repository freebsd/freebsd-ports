# New ports collection makefile for:	scotch
# Date created:		Thu 2 feb 2006
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	scotch
PORTVERSION=	4.0.0
PORTREVISION=	1
CATEGORIES=	cad science
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/464/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A package for graph and mesh partitioning and sparse matrix ordering

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:R}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/bin

F77?=		f77

BINS=		acpl amk_ccc amk_fft2 amk_grf amk_hy amk_m2 amk_p2 atst	\
		gcv gmap gmk_hy gmk_m2 gmk_m3 gmk_msh gmk_ub2 gmtst gord\
		gotst gout gtst mcv mmk_m2 mmk_m3 mord mtst
INCS=		common.h scotch.h scotchf.h
LIBS=		libcommon.a libscotch.a libscotcherr.a libscotcherrcom.a
PORTDOCS=	scotch_user4.0.pdf
EXAMPLES=	scotch_example.f

pre-configure:
	${LN} -sf ${WRKSRC}/src/Make.inc/Makefile.inc.freebsd	\
		${WRKSRC}/src/Makefile.inc

do-install:
	${INSTALL_PROGRAM} ${BINS:S|^|${INSTALL_WRKSRC}/|} ${PREFIX}/bin
	${INSTALL_DATA} ${INCS:S|^|${INSTALL_WRKSRC}/|} ${PREFIX}/include
	${INSTALL_DATA} ${LIBS:S|^|${INSTALL_WRKSRC}/|} ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}/grf ${EXAMPLESDIR}/tgt
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/doc/|} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/grf/* ${EXAMPLESDIR}/grf
	${INSTALL_DATA} ${WRKSRC}/tgt/* ${EXAMPLESDIR}/tgt
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.if defined(MAINTAINER_MODE)
test:	install
	(amk_ccc 3 | acpl - ${WRKDIR}/ccc3.tgt &&	\
	${GUNZIP_CMD} -c ${EXAMPLESDIR}/grf/bump.grf.gz |	\
	gmap - ${WRKDIR}/ccc3.tgt ${WRKDIR}/brol.map)
	(cd ${WRKSRC}/doc &&	\
	${F77} -o scotch_test scotch_example.f	\
		-I${PREFIX}/include -L${PREFIX}/lib -lscotch -lscotcherr -lm	\
	&& ./scotch_test)
.endif

.include <bsd.port.mk>
