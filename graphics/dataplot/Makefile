# Created by: Pedro F. Giffuni <pfgshield-freebsd@yahoo.com>
# $FreeBSD$

PORTNAME=	dataplot
PORTVERSION=	20090821
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.nist.gov/pub/dataplot/unix/:source \
		LOCAL/beech:source \
		http://www.itl.nist.gov/div898/software/dataplot.html/:doc \
		LOCAL/beech:doc
DISTFILES=	dpsrc${EXTRACT_SUFX}:source \
		dpsnapsh.pdf:doc
DIST_SUBDIR=	dataplot
EXTRACT_ONLY=	dpsrc${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free software system for statistical visualization

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd \
		png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_FORTRAN=	yes
USE_XORG=	x11 xi
NO_WRKSUBDIR=	yes
MAXOBV?=	400000	# Change if you need more observations/variable

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ((${ARCH}=="amd64") || (${ARCH}=="sparc64") || (${ARCH}=="ia64"))
FFLAGS+= -DDD -DI32 -fdefault-real-8 -fdefault-double-8
.else
FFLAGS+= -DSD -DI32 -fdefault-real-8 -fdefault-double-8
.endif

post-extract:
	@${INSTALL_DATA} ${FILESDIR}/Makefile.tmpl ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's;%%LOCALBASE%%;${LOCALBASE};g ; \
	s;%%LOCALBASE%%;${LOCALBASE};g' \
	${WRKSRC}/Makefile
# Ensure preprocessing is done
	@${CP} ${WRKSRC}/dp1_linux.f ${WRKSRC}/dp1_linux.F
# Turn off some dependencies
	@${MV} ${WRKSRC}/aqua_src.c ${WRKSRC}/aqua_src.c.nop
	@${MV} ${WRKSRC}/gl_src.c ${WRKSRC}/gl_src.c.nop
	@${MV} ${WRKSRC}/libplot_src.c ${WRKSRC}/libplot_src.c.nop
	@${MV} ${WRKSRC}/rldp.c ${WRKSRC}/rldp.c.nop

pre-patch:
	@${REINPLACE_CMD} -e 's/MAXOBV=1000000/MAXOBV=${MAXOBV}/' \
	${WRKSRC}/DPCOPA.INC

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d  ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/dpsnapsh.pdf \
		${DOCSDIR}
.endif

.include <bsd.port.post.mk>
