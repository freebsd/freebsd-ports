# New ports collection makefile for:	pgplot
# Date created:		21 December 1996
# Whom:			jmz
#
# $FreeBSD$
#

PORTNAME=	pgplot
PORTVERSION=	5.2.2
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.astro.caltech.edu/pub/pgplot/
DISTNAME=	${PORTNAME}${PORTVERSION:R}

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	A C/FORTRAN library for drawing graphs on a variety of display devices

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_XLIB=	yes
USE_PERL5_BUILD=yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

WANT_FORTRAN=	yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42
MAKE_ENV+=	FC="${FC}" F77="${F77}" FFLAGS="${FFLAGS}"
MAKE_ARGS+=	X11BASE="${X11BASE}"

post-install:
.for f in libcpgplot.so libpgplot.so
	${LN} -sf $f.5 ${PREFIX}/lib/$f
.endfor

.include <bsd.port.post.mk>
