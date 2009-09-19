# New ports collection makefile for:   crux
# Date created:        8 June 2009
# Whom:                jasone
#
# $FreeBSD$
#

PORTNAME=      crux
PORTVERSION=   1.2.0
PORTREVISION=  1
CATEGORIES=    biology python
MASTER_SITES=  http://www.canonware.com/download/Crux/

MAINTAINER=    jasone@FreeBSD.org
COMMENT=       Software toolkit for phylogenetic inference

USE_BZIP2=     yes
GNU_CONFIGURE= yes
CONFIGURE_ARGS=--with-python=${PYTHON_CMD} --disable-mpi
USE_CSTD=      gnu99
USE_GMAKE=     yes
USE_PYTHON=    2.5+

OPTIONS=       SYS_LINALG "Enable system ATLAS/LAPACK" Off

.include <bsd.port.pre.mk>

CPPFLAGS+=      -I${LOCALBASE}/include
LDFLAGS+=       -L${LOCALBASE}/lib
CONFIGURE_ENV+= CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_FORTRAN=   yes
.if defined(WITH_SYS_LINALG)
CONFIGURE_ARGS+= --enable-sys-linalg
LIB_DEPENDS+=   atlas.2:${PORTSDIR}/math/atlas
.else
CONFIGURE_ARGS+= --disable-sys-linalg
.endif

post-install:
	@${PREFIX}/bin/crux -b -q /dev/null

.include <bsd.port.post.mk>
