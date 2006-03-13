# New ports collection makefile for:	CalculiX
# Date created:		19 April 2003
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	CalculiX
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.dhondt.de/
DISTFILES=	${DIST_SOURCES}
.if !defined(NOPORTDOCS)
DISTFILES+=	${DIST_HTM} ${DIST_PS}
.endif
.ifdef WITH_EXAMPLES
DISTFILES+=	${DIST_EXAMPLES}
.endif
DIST_SUBDIR=	calculix
EXTRACT_ONLY=	${DIST_SOURCES}
.if !defined(NOPORTDOCS)
EXTRACT_ONLY+=	${DIST_HTM} ccx_${PORTVERSION}.ps${EXTRACT_SUFX}
.endif
.ifdef WITH_EXAMPLES
EXTRACT_ONLY+=	${DIST_EXAMPLES}
.endif

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A Three-Dimensional Structural Finite Element Program

BUILD_DEPENDS=	${LOCALBASE}/lib/libarpack.a:${PORTSDIR}/math/arpack	\
		${LOCALBASE}/lib/liblapack.a:${PORTSDIR}/math/lapack	\
		${LOCALBASE}/lib/libspooles.a:${PORTSDIR}/math/spooles	\
		${LOCALBASE}/lib/libmetis.a:${PORTSDIR}/math/metis	\
		${LOCALBASE}/lib/libtaucs.a:${PORTSDIR}/math/taucs
LIB_DEPENDS=    atlas.1:${PORTSDIR}/math/atlas \
		glut.4:${PORTSDIR}/graphics/libglut

USE_BZIP2=	yes

DIST_SOURCES=	ccx_${PORTVERSION}.src${EXTRACT_SUFX}	\
		cgx_${PORTVERSION}.all${EXTRACT_SUFX}
DIST_HTM=	ccx_${PORTVERSION}.htm${EXTRACT_SUFX}	\
		cgx_${PORTVERSION}.htm${EXTRACT_SUFX}
DIST_PS=	ccx_${PORTVERSION}.ps${EXTRACT_SUFX}	\
		cgx_${PORTVERSION}.ps.bz2
DIST_EXAMPLES=	ccx_${PORTVERSION}.test${EXTRACT_SUFX}	\
		cgx_${PORTVERSION}.exa${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
USE_GL=	yes
USE_REINPLACE=	yes
BLAS_LIBS?=	-lf77blas -latlas

BROWSER?=	mozilla
PSVIEWER?=	gv

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif

.if !defined(WITH_EXAMPLES)
PLIST_SUB=	WITH_EXAMPLES="@comment "
.else
PLIST_SUB=	WITH_EXAMPLES=""
.endif

.ifndef (WITH_EXAMPLES)
pre-everything::
	@${ECHO} "You can define WITH_EXAMPLES=yes to install example files"
.endif

pre-build:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; s+%%CC%%+${CC}+g ; \
	s+%%PTHREAD_CFLAGS%%+-DUSE_MT ${PTHREAD_CFLAGS}+g; \
	s+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g; \
	s+%%BLAS_LIBS%%+${BLAS_LIBS}+ ; \
	s+%%LOCALBASE%%+${LOCALBASE}+g;' \
		${WRKSRC}/ccx_${PORTVERSION}/src/Makefile
	@${REINPLACE_CMD} -e 's+%%X11BASE%%+${X11BASE}+g; \
	s+%%PTHREAD_CFLAGS%%+${PTHREAD_CFLAGS}+g; \
	s+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g;' \
		${WRKSRC}/cgx_${PORTVERSION}/src/Makefile
	@${REINPLACE_CMD} -e 's+%%DOCSDIR%%+${DOCSDIR}+g; \
	s+"mozilla"+"${BROWSER}"+ ; \
	s+"ghostview"+"${PSVIEWER}"+ ;' \
		${WRKSRC}/cgx_${PORTVERSION}/src/cgx.h
# This fixes bugs in ccx 1.4
	@${REINPLACE_CMD} -e 's+description[12]+description[13]+g;' \
		${WRKSRC}/ccx_1.4/src/arpackbu.c	\
		${WRKSRC}/ccx_1.4/src/arpack.c	\
		${WRKSRC}/ccx_1.4/src/arpackcs.c	\
		${WRKSRC}/ccx_1.4/src/dyna.c		\
		${WRKSRC}/ccx_1.4/src/frdcyc.c	\
		${WRKSRC}/ccx_1.4/src/nonlingeo.c	\
		${WRKSRC}/ccx_1.4/src/prespooles.c	\
		${WRKSRC}/ccx_1.4/src/profile.c	\
		${WRKSRC}/ccx_1.4/src/sensitivity.c	\
		${WRKSRC}/ccx_1.4/src/steadystate.c
	@${REINPLACE_CMD} -e 's+output[3]+output[4]+g;' \
		${WRKSRC}/ccx_1.4/src/ccx_1.4.c

do-build:
	@(cd ${WRKSRC}/ccx_${PORTVERSION}/src; ${SETENV} ${MAKE_ENV} $(GMAKE) )
	@(cd ${WRKSRC}/libSNL/src; ${SETENV} ${MAKE_ENV} $(GMAKE) )
	@(cd ${WRKSRC}/cgx_${PORTVERSION}/src; ${SETENV} ${MAKE_ENV} $(GMAKE) )

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ccx_${PORTVERSION}/src/ccx_${PORTVERSION} \
	  ${PREFIX}/bin/ccx
	@${INSTALL_PROGRAM} ${WRKSRC}/cgx_${PORTVERSION}/src/cgx \
	  ${PREFIX}/bin/cgx
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/ccx
	@${INSTALL_DATA} ${WRKSRC}/ccx_${PORTVERSION}/doc/ccx/* \
	  ${DOCSDIR}/ccx
	@${MKDIR} ${DOCSDIR}/cgx
	@${INSTALL_DATA} ${WRKSRC}/cgx_${PORTVERSION}/doc/cgx/* \
	  ${DOCSDIR}/cgx
	@${INSTALL_DATA} ${WRKSRC}/ccx_${PORTVERSION}/doc/*.ps ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cgx_${PORTVERSION}.ps.bz2	\
	  ${DOCSDIR}
	bunzip2 ${DOCSDIR}/cgx_${PORTVERSION}.ps.bz2
	@${GZIP_CMD} ${DOCSDIR}/*.ps
.endif
.ifdef WITH_EXAMPLES
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} cf - -C ${WRKSRC}/cgx_${PORTVERSION}/examples . | ${TAR} xf - -C ${EXAMPLESDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/test
	@${TAR} cf - -C ${WRKSRC}/ccx_${PORTVERSION}/test . | ${TAR} xf - -C ${EXAMPLESDIR}/test
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
