# New ports collection makefile for:	pgplot
# Date created:		21 December 1996
# Whom:			jmz
#
# $FreeBSD$
#

PORTNAME=       pgplot
PORTVERSION=	5.2
CATEGORIES=     graphics
MASTER_SITES=   ftp://astro.caltech.edu/pub/pgplot/
DISTNAME=       ${PORTNAME}${PORTVERSION}

MAINTAINER=	jmz@FreeBSD.org

USE_XLIB=	yes
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
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
