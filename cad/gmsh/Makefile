# New ports collection makefile for:  gmsh
# Date created:               19 April 2003
# Whom:                       Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	gmsh
PORTVERSION=	1.60.1
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.geuz.org/gmsh/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automatic 3D finite element mesh generator

RUN_DEPENDS=	getdp:${PORTSDIR}/science/getdp
LIB_DEPENDS=	gsl.7:${PORTSDIR}/math/gsl \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

.if defined(PACKAGE_BUILDING)
WITHOUT_TRIANGLE=	yes
.endif

.if !defined(WITHOUT_TRIANGLE)
EXTRACT_DEPENDS+=	${NONEXISTENT}:${TRIANGLE_PORTDIR}:patch
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
TRIANGLE_PORTDIR=	${PORTSDIR}/math/triangle

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-fltk-prefix=${X11BASE} \
		--with-gsl-prefix=${LOCALBASE} \
		--with-jpeg-prefix=${LOCALBASE} \
		--with-png-prefix=${LOCALBASE}
ALL_TARGET=	all utils

MAN1=		gmsh.1

.if !defined(WITHOUT_TRIANGLE)
NO_CDROM=	Triangle must not be sold for profit
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CONFIGURE_ARGS+=	--disable-netgen	# Problem with Netgen & gcc-295
.endif

post-extract:
.if !defined(WITHOUT_TRIANGLE)
	${CP} `cd ${TRIANGLE_PORTDIR}; ${MAKE} -V WRKSRC`/triangle.* ${WRKSRC}/Triangle
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
