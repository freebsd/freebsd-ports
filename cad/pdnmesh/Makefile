# New ports collection makefile for:	pdnmesh
# Date created:			25 August 2001
# Whom:				Sarod Yatawatta <sarod@cs.pdn.ac.lk>
#
# $FreeBSD$
#

PORTNAME=	pdnmesh
PORTVERSION=	0.2.1
PORTREVISION=	8
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}

MAINTAINER=	sarod@users.sf.net
COMMENT=	A finite element program

LIB_DEPENDS=	gtkglext:${PORTSDIR}/x11-toolkits/gtkglext

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

USE_FORTRAN=	yes
CONFIGURE_ENV+=	BLAS_LIBS="${BLAS}" LAPACK_LIBS="${LAPACK}"
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=	pdnmesh.1
MAN5=	pdnmesh_input.5

.include <bsd.port.post.mk>
