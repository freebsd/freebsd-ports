# New ports collection makefile for:	openthreads
# Date created:		16 October 2003
# Whom:			Ying-Chieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	openthreads
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	http://www.openscenegraph.org/downloads/snapshots/
#
# the following master distribution contains the version of OpenThreads
# as described above by PORTVERSION and PORTREVISION.
DISTNAME=	OSG_OP_OT-1.0

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	A library which provides OO thread interface for C++ programmers

USE_ZIP=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAKEFILE=	GNUmakefile
WRKSRC=		${WRKDIR}/${DISTNAME}/OpenThreads
MAKE_ENV+=	FREEBSD_ARCH="${ARCH}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

# Optimisation/Debug flags:
#   opt = optimised ($OPTF added)
#   debug = debug ($DBGF added)
# opt is default
#
ALL_TARGET=	opt

.include <bsd.port.mk>
