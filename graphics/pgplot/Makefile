# New ports collection makefile for:	pgplot
# Date created:		21 December 1996
# Whom:			jmz
#
# $FreeBSD$
#

PORTNAME=	pgplot
PORTVERSION=	5.2.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.astro.caltech.edu/pub/pgplot/
DISTNAME=	${PORTNAME}${PORTVERSION:R}

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	A C/FORTRAN library for drawing graphs on a variety of display devices

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
USE_XLIB=	yes
USE_PERL5_BUILD=yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
VERSION=	5
.else
VERSION=	5.2
.endif

.if ${OSVERSION} < 400004
FC=	./xf77
.else
FC=	f77
.endif

MAKE_ENV+=	FC=${FC}
MAKE_ARGS+=	X11BASE="${X11BASE}"

post-install:
.for f in libcpgplot.so libpgplot.so
	${LN} -sf $f.${VERSION} ${PREFIX}/lib/$f
.endfor

.include <bsd.port.post.mk>
