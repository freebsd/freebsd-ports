# New ports collection makefile for:    pisces
# Date created:         11-1-1999
# Whom:                 Gianlorenzo Masini <masini@uniroma3.it>
#
# $FreeBSD$
#

PORTNAME=	piscesIIB
PORTVERSION=	1.0
CATEGORIES=	cad
MASTER_SITES=	ftp://gloworm.stanford.edu/tcad/sw/Pisces/
DISTNAME=	relB.9009
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	masini@uniroma3.it

BUILD_DEPENDS=	f2c:${PORTSDIR}/lang/f2c

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} != 3
BUILD_DEPENDS+=	imake:${PORTSDIR}/devel/imake-4
.endif

NO_WRKSUBDIR=	yes
USE_XLIB=	yes
MANL=		digit.l dplot.l gplot.l gplot2.l high2.l

NO_BUILD=	yes

MAKE_ENV+=	WRKDIR=${WRKDIR}

post-install:
	strip ${PREFIX}/bin/digit
	strip ${PREFIX}/bin/dplot
	strip ${PREFIX}/bin/genii3
	strip ${PREFIX}/bin/hsl2rgb
	strip ${PREFIX}/bin/pisces2

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pisces
	${CP} -R ${WRKSRC}/pisces/9009/doc ${PREFIX}/share/doc/pisces
	${CP} -R ${WRKSRC}/pisces/9009/test_suite ${PREFIX}/share/doc/pisces
.endif

.include <bsd.port.post.mk>
