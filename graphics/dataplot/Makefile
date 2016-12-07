# Created by: Pedro F. Giffuni <pfgshield-freebsd@yahoo.com>
# $FreeBSD$

PORTNAME=	dataplot
PORTVERSION=	20132012
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.nist.gov/pub/dataplot/unix/:source \
		LOCAL/beech:source \
		http://www.itl.nist.gov/div898/software/dataplot.html/:doc \
		LOCAL/beech:doc
DISTFILES=	dpsrc${EXTRACT_SUFX}:source
DIST_SUBDIR=	dataplot
EXTRACT_ONLY=	dpsrc${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free software system for statistical visualization

LIB_DEPENDS=	libgd.so:graphics/gd \
		libpng.so:graphics/png

OPTIONS_DEFINE=	DOCS
DOCS_DISTFILES=	dpsnapsh.pdf:doc

USES=		fortran jpeg
USE_XORG=	x11 xi
NO_WRKSUBDIR=	yes
MAXOBV?=	400000	# Change if you need more observations/variable

.include <bsd.port.options.mk>

.if ((${ARCH}=="amd64") || (${ARCH}=="sparc64") || (${ARCH}=="ia64"))
FFLAGS+= -DDD -DI32 -fdefault-real-8 -fdefault-double-8
.else
FFLAGS+= -DSD -DI32 -fdefault-real-8 -fdefault-double-8
.endif

post-extract:
	@${INSTALL_DATA} ${FILESDIR}/Makefile.tmpl ${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e 's;%%CFLAGS%%;${CFLAGS};' \
		-e 's;%%FFLAGS%%;${FFLAGS};' \
		-e 's;%%LDFLAGS%%;${LDFLAGS};' \
		-e 's;%%LOCALBASE%%;${LOCALBASE};g' ${WRKSRC}/Makefile
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

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/dpsnapsh.pdf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
