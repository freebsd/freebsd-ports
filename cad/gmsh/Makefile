# New ports collection makefile for:  gmsh
# Date created:               19 April 2003
# Whom:                       Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	gmsh
PORTVERSION=	1.65.0
CATEGORIES=	cad
MASTER_SITES=	http://www.geuz.org/gmsh/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automatic 3D finite element mesh generator

RUN_DEPENDS=	getdp:${PORTSDIR}/science/getdp
LIB_DEPENDS=	gsl.9:${PORTSDIR}/math/gsl \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

.if defined(PACKAGE_BUILDING)
#Triangle and Tetgen are NO_CDROM
WITHOUT_TRIANGLE=	yes
WITHOUT_TETGEN=		yes
.endif

.if !defined(WITHOUT_TRIANGLE)
EXTRACT_DEPENDS+=	${NONEXISTENT}:${TRIANGLE_PORTDIR}:patch
TRIANGLE_PORTDIR=	${PORTSDIR}/math/triangle
.endif

.if !defined(WITHOUT_TETGEN)
EXTRACT_DEPENDS+=	${NONEXISTENT}:${TETGEN_PORTDIR}:patch
TETGEN_PORTDIR=		${PORTSDIR}/math/tetgen
TETGEN_SRC=		predicates.cxx tetgen.cxx tetgen.h
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-fltk-prefix=${X11BASE} \
		--with-gsl-prefix=${LOCALBASE} \
		--with-jpeg-prefix=${LOCALBASE} \
		--with-png-prefix=${LOCALBASE}
ALL_TARGET=	all utils

MAN1=		gmsh.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CONFIGURE_ARGS+=	--disable-netgen	# Problem with Netgen & gcc-295
BROKEN=		Does not compile with gcc-295
.endif

post-extract:
.if !defined(WITHOUT_TRIANGLE)
	${CP} `cd ${TRIANGLE_PORTDIR}; ${MAKE} -V WRKSRC`/triangle.*	\
		${WRKSRC}/contrib/Triangle
.endif
.if !defined(WITHOUT_TETGEN)
	${CP} ${TETGEN_SRC:S|^|`cd ${TETGEN_PORTDIR}; ${MAKE} -V WRKSRC`/|}	\
		${WRKSRC}/contrib/Tetgen
.endif

pre-configure:
.for demo in lowmem-anim.geo
	@${REINPLACE_CMD} -e "s|../tutorial|${DOCSDIR}/tutorial|"	\
		${WRKSRC}/demos/${demo}
.endfor

do-install:
.for f in dxf2geo gmsh mshsort
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/gmsh.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DOCSDIR}
	cd ${WRKSRC} && ${FIND} tutorial | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${FIND} demos ! -name "*.bak" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
