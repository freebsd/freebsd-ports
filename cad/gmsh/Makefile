# New ports collection makefile for:  gmsh
# Date created:               19 April 2003
# Whom:                       Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	gmsh
PORTVERSION=	1.51.4
CATEGORIES=	cad
MASTER_SITES=	http://www.geuz.org/gmsh/src/	\
		http://www.cs.berkeley.edu/~jrs/:triangle
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
EXTRACT_SUFX=	.tgz
.ifdef WITH_TRIANGLE
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}	\
		triangle.shar.gz:triangle
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automatic 3D finite element mesh generator

LIB_DEPENDS=	gsl.5:${PORTSDIR}/math/gsl \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.ifndef WITH_TRIANGLE
pre-everything::
	@${ECHO_MSG} "You can make with WITH_TRIANGLE for faster 2d meshing"
.else
NO_CDROM=	"Triangle must not be sold for profit"
post-extract:
	@(cd ${WRKSRC}/Triangle; \
	${GUNZIP_CMD} < ${DISTDIR}/${DIST_SUBDIR}/triangle.shar.gz | ${SH})
	${RM} ${WRKSRC}/Triangle/makefile
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-fltk-prefix=${X11BASE} \
			--with-gsl-prefix=${LOCALBASE} \
			--with-jpeg-prefix=${LOCALBASE} \
			--with-png-prefix=${LOCALBASE}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

ALL_TARGET=	all converters

MAN1=		gmsh.1

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/gmsh
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dxf2geo ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/tutorial
	${INSTALL_DATA} ${WRKSRC}/tutorial/* ${DOCSDIR}/tutorial
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}/demos
	${INSTALL_DATA} ${WRKSRC}/demos/* ${EXAMPLESDIR}/demos
.endif

.include <bsd.port.mk>
