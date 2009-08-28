# New ports collection makefile for:	dataplot
# Date created:		20 July 2003
# Whom:			Pedro F. Giffuni <pfgshield-freebsd@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	dataplot
PORTVERSION=	20080225
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.nist.gov/pub/dataplot/unix/:source \
		LOCAL/beech:source \
		http://www.itl.nist.gov/div898/software/dataplot.html/:doc \
		LOCAL/beech:doc
DISTFILES=	dpsrc.02_25_2008${EXTRACT_SUFX}:source \
		dpsnapsh.pdf:doc
DIST_SUBDIR=	dataplot
EXTRACT_ONLY=	dpsrc.02_25_2008${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free software system for statistical visualization

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_FORTRAN=	yes
FFLAGS+=	-fno-range-check
USE_XORG=	x11 xi
NO_WRKSUBDIR=	yes
MAXOBV?=	1000000	# Change if you need more observations/variable

.include <bsd.port.pre.mk>

post-extract:
	@${INSTALL_DATA} ${FILESDIR}/Makefile.tmpl ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's;%%LOCALBASE%%;${LOCALBASE};g ; \
	s;%%LOCALBASE%%;${LOCALBASE};g' \
	${WRKSRC}/Makefile
	@${MV} ${WRKSRC}/aqua_src.c ${WRKSRC}/aqua_src.c.nop
	@${MV} ${WRKSRC}/gl_src.c ${WRKSRC}/gl_src.c.nop

pre-patch:
	@${REINPLACE_CMD} -e 's/MAXOBV=1000000/MAXOBV=${MAXOBV}/' \
	${WRKSRC}/DPCOPA.INC
.if ((${ARCH}=="amd64") || (${ARCH}=="sparc64") || (${ARCH}=="ia64"))
	@${REINPLACE_CMD} -e 's;dp1_linux;dp1_linux_dp;g' \
	${WRKSRC}/Makefile
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d  ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/dpsnapsh.pdf \
		${DOCSDIR}
.endif

.include <bsd.port.post.mk>
