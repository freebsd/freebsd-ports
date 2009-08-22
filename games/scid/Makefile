# ex:ts=8
# Ports collection makefile for:	scid
# Date created:			Mar 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scid
PORTVERSION=	3.6.26
PORTREVISION=	2
CATEGORIES=	games databases
MASTER_SITES=	SF/${PORTNAME}/Scid/Scid%20${PORTVERSION}

MAINTAINER=	bsd@volki.at
COMMENT=	A free chess database application

USE_TK=		84+
INVALID_TCL_VER=	86

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes

ALL_TARGET=	all strip

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>
MAKE_ARGS+=	TCL_VER="${TCL_VER}" \
		TCL_LIBVER="${TCL_VER:S/.//}" \
		TCL_THREADS_SUFFIX="${_TCL_THREADS_SUFFIX}" \
		TCL_LIBDIR="${TCL_LIBDIR}" \
		TCL_INCLUDEDIR="${TCL_INCLUDEDIR}" \
		TK_LIBDIR="${TK_LIBDIR}" \
		TK_INCLUDEDIR="${TK_INCLUDEDIR}"

.if defined(USE_TCL_THREADS)
MAKE_ARGS+=	PTHREAD_LIBS="${PTHREAD_LIBS}"
.endif

.include <bsd.port.post.mk>
