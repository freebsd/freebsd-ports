# New ports collection makefile for:	pgplot
# Version required:     5.2
# Date created:		21 December 1996
# Whom:			jmz
#
# $Id: Makefile,v 1.5 1998/10/05 03:01:29 steve Exp $
#

DISTNAME=       pgplot5.2
PKGNAME=        pgplot-5.2
CATEGORIES=     graphics
MASTER_SITES=   ftp://astro.caltech.edu/pub/pgplot/

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/pgplot

OSVERSION!=     sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
BROKEN=         makehtml not found
.endif

post-install:
.for f in libcpgplot.so libpgplot.so
	${LN} -sf $f.${VERSION} ${PREFIX}/lib/$f
.endfor
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

.if ${PORTOBJFORMAT} == "elf"
VERSION=	5
.else
VERSION=	5.2
.endif
