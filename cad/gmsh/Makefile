# New ports collection makefile for:  gmsh
# Date created:               19 April 2003
# Whom:                       Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	gmsh
PORTVERSION=	1.55.0
CATEGORIES=	cad
MASTER_SITES=	http://www.geuz.org/gmsh/src/	\
		http://cm.bell-labs.com/netlib/voronoi/:triangle
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
EXTRACT_SUFX=	.tgz
.if defined(WITH_TRIANGLE)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} triangle.shar.gz:triangle
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automatic 3D finite element mesh generator

LIB_DEPENDS=	gsl.6:${PORTSDIR}/math/gsl \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-fltk-prefix=${X11BASE} \
		--with-gsl-prefix=${LOCALBASE} \
		--with-jpeg-prefix=${LOCALBASE} \
		--with-png-prefix=${LOCALBASE}
ALL_TARGET=	all converters

MAN1=		gmsh.1

.if !defined(WITH_TRIANGLE)
NO_CDROM=	"Triangle must not be sold for profit"
.endif

pre-everything::
.if !defined(WITH_TRIANGLE)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can make with WITH_TRIANGLE for faster 2d meshing"
	@${ECHO_MSG}
.endif

post-extract:
.if defined(WITH_TRIANGLE)
	@(cd ${WRKSRC}/Triangle; \
	${GUNZIP_CMD} < ${DISTDIR}/${DIST_SUBDIR}/triangle.shar.gz | \
	${SED} 's:/ \*:/* :g' | ${SH})
	${RM} ${WRKSRC}/Triangle/makefile
.endif

post-patch:
.for demo in isosurf.scp lowmem-anim.geo
	@${REINPLACE_CMD} -e "s|../tutorial|${DOCSDIR}/tutorial|"	\
		${WRKSRC}/demos/${demo}
.endfor

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/gmsh
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dxf2geo ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DOCSDIR}
	cd ${WRKSRC} && ${FIND} tutorial | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${FIND} demos ! -name "*.bak" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
