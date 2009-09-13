# New ports collection makefile for:	pgplot
# Date created:		21 December 1996
# Whom:			jmz
#
# $FreeBSD$
#

PORTNAME=	pgplot
PORTVERSION=	5.2.2
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.astro.caltech.edu/pub/pgplot/
DISTNAME=	${PORTNAME}${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C/FORTRAN library for drawing graphs on a variety of display devices

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_PERL5_BUILD=yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

USE_XORG=	x11 xproto xt
USE_FORTRAN=	yes

post-install:
.for f in libcpgplot.so libpgplot.so
	${LN} -sf $f.5 ${PREFIX}/lib/$f
.endfor

.include <bsd.port.post.mk>
