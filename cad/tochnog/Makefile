# New ports collection makefile for:	tochnog
# Date created:		19 Apr 2003
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	tochnog
PORTVERSION=	20010211
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tochnog
DISTNAME=	${PORTNAME}_feb11_2001

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free explicit/implicit Finite Element Program

BUILD_DEPENDS=	${LOCALBASE}/lib/libf2c.a:${PORTSDIR}/lang/f2c \
		${LOCALBASE}/lib/libf77blas.a:${PORTSDIR}/math/atlas
.ifdef USE_THREADS
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsuperlu_mt.a:${PORTSDIR}/math/superlu_mt
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsuperlu.a:${PORTSDIR}/math/superlu
.endif

BROKEN=		"Does not compile"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
USE_GCC=	2.95	# 3.2 should also work !!
.endif

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/src
MAKEFILE=	makefile

.ifdef USE_THREADS
BLAS_LIBS=	-L${LOCALBASE}/lib -lptf77blas -latlas_r
SUPERLU=	superlu_mt
ALL_TARGET=	freebsd_parallel
.else
BLAS_LIBS=	-L${LOCALBASE}/lib -lf77blas -latlas
SUPERLU=	superlu
ALL_TARGET=	freebsd_old
.endif

.ifndef USE_THREADS
pre-everything::
	@${ECHO_MSG} "make USE_THREADS=yes for threaded version"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g ; \
	s,%%PTHREAD_CFLAGS%%,${PTHREAD_CFLAGS},g ; s,%%PTHREAD_LIBS%%,${PTHREAD_LIBS},g ; \
	s,%%SUPERLU%%,${SUPERLU},g ; \
	s,%%BLAS_LIBS%%,${BLAS_LIBS},g' \
	${WRKSRC}/makefile
.ifdef USE_THREADS
	@${REINPLACE_CMD} -e 's,SUPERLU_MT_USE 0,SUPERLU_MT_USE 1,' \
	${WRKSRC}/tnsuplu.h
.else
	@${REINPLACE_CMD} -e 's,SUPERLU_USE 0,SUPERLU_USE 1,' \
	${WRKSRC}/tnsuplu.h
.endif

post-build:
	@(cd ${WRKDIR}/tochnog/tools; ${CXX} ${CXXFLAGS} -o aba2tn aba2tn.cc)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tochnog ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/tochnog/tools/aba2tn ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/tochnog/tools/*.awk ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/test
	@${RM} -f ${WRKDIR}/tochnog/test/*.orig
	${INSTALL_DATA} ${WRKDIR}/tochnog/test/* ${DOCSDIR}/test
.endif

.include <bsd.port.post.mk>
