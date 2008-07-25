# New ports collection makefile for:	dataplot
# Date created:		20 July 2003
# Whom:			Pedro F. Giffuni <pfgshield-freebsd@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	dataplot
PORTVERSION=	20070224
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.nist.gov/pub/dataplot/unix/:source \
		LOCAL/beech:source \
		http://www.itl.nist.gov/div898/software/dataplot.html/:doc \
		LOCAL/beech:doc
DISTFILES=	dpsrc.02_24_2007${EXTRACT_SUFX}:source \
		dpsnapsh.pdf:doc
DIST_SUBDIR=	dataplot
EXTRACT_ONLY=	dpsrc.02_24_2007${EXTRACT_SUFX}

MAINTAINER=	beech@FreeBSD.org
COMMENT=	A free software system for statistical visualization

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_FORTRAN=	yes
FFLAGS+=	-fno-range-check
USE_XORG=	x11 xi
NO_WRKSUBDIR=	yes
MAXOBV?=	100000	# Change if you need more observations/variable

.include <bsd.port.pre.mk>

post-extract:
	@${INSTALL_DATA} ${FILESDIR}/Makefile.tmpl ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's;%%LOCALBASE%%;${LOCALBASE};g ; \
	s;%%LOCALBASE%%;${LOCALBASE};g' \
	${WRKSRC}/Makefile
	@${MV} ${WRKSRC}/gl_src.c ${WRKSRC}/gl_src.c.bogus

pre-patch:
	@${REINPLACE_CMD} -e 's/MAXOBV=100000/MAXOBV=${MAXOBV}/' \
	${WRKSRC}/DPCOPA.INC

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d  ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/dpsnapsh.pdf \
		${DOCSDIR}
.endif

.include <bsd.port.post.mk>
