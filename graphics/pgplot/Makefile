# New ports collection makefile for:	pgplot
# Date created:		21 December 1996
# Whom:			jmz
#
# $FreeBSD$
#

PORTNAME=	pgplot
PORTVERSION=	5.2.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.astro.caltech.edu/pub/pgplot/
DISTNAME=	${PORTNAME}5.2

MAINTAINER=	jmz@FreeBSD.org

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/pgplot

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

post-install:
.for f in libcpgplot.so libpgplot.so
	${LN} -sf $f.${VERSION} ${PREFIX}/lib/$f
.endfor

.include <bsd.port.post.mk>
