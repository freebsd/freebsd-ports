# New ports collection makefile for:	dataplot
# Date created:		20 July 2003
# Whom:			Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	dataplot
PORTVERSION=	20060425
PORTREVISION=
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.nist.gov/pub/dataplot/unix/:source \
		http://www.itl.nist.gov/div898/software/dataplot.html/:doc
DISTFILES=	dpsrc.04_25_2006.tar.gz:source \
		dpsnapsh.pdf:doc
DIST_SUBDIR=	dataplot
EXTRACT_ONLY=	dpsrc.04_25_2006.tar.gz

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	A free software system for statistical visualization

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_XLIB=	yes
NO_WRKSUBDIR=	yes
MAXOBV?=	20000	# Make bigger if you need more observations/variable

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not link on alpha (.got subsegment exceeds 64k)
.endif

post-extract:
	@${INSTALL_DATA} ${FILESDIR}/Makefile.tmpl ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's;%%LOCALBASE%%;${LOCALBASE};g ; \
	s;%%X11BASE%%;${X11BASE};g' \
	${WRKSRC}/Makefile
	@${MV} ${WRKSRC}/gl_src.c ${WRKSRC}/gl_src.c.bogus
pre-patch:
	@${REINPLACE_CMD} -e 's/MAXOBV=100000/MAXOBV=${MAXOBV}/' \
	${WRKSRC}/DPCOPA.INC

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR}  ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/dpsnapsh.pdf \
		${DOCSDIR}
.endif

.include <bsd.port.post.mk>
