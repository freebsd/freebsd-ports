# New ports collection makefile for:  gmsh
# Date created:               19 April 2003
# Whom:                       Pedro Giffuni <giffunip@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	gmsh
PORTVERSION=	1.45.1
CATEGORIES=	cad
MASTER_SITES=	http://www.geuz.org/gmsh/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automatic 3D finite element mesh generator

LIB_DEPENDS=	gsl.4:${PORTSDIR}/math/gsl \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

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
