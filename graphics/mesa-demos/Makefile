# New ports collection makefile for:    mesa-demos
# Date created:         7 Nov 2003
# Whom:                 anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	demos
PORTVERSION=	5.0.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:sf/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	mesa3d/:sf \
			anholt/:local
PKGNAMEPREFIX=	mesa-
DISTFILES=	MesaDemos-${PORTVERSION}${EXTRACT_SUFX}:sf \
		MesaLib-${PORTVERSION}${EXTRACT_SUFX}:sf

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	OpenGL demos distributed with Mesa

LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut

USE_BZIP2=	yes
USE_REINPLACE=	yes
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKEFILE=	Makefile.X11
ALL_TARGET=	targets
WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}/demos
SHAREDIR=	${PREFIX}/share/mesa-demos

post-extract:
	${REINPLACE_CMD} -e 's|../images/|${SHAREDIR}/images/|g' \
		-e 's|geartrain.dat|${SHAREDIR}/data/geartrain.dat|g' \
		-e 's|terrain.dat|${SHAREDIR}/data/terrain.dat|g' \
		-e 's|isosurf.dat|${SHAREDIR}/data/isosurf.dat|g' \
		${WRKSRC}/*.c

post-install:
	${MKDIR} ${PREFIX}/share/mesa-demos/images
	${MKDIR} ${PREFIX}/share/mesa-demos/data
	@for img in `${LS} ${WRKDIR}/Mesa-${PORTVERSION}/images/*.rgb`; do \
		${INSTALL_DATA} $$img ${SHAREDIR}/images ; \
	done
	@for dat in `${LS} ${WRKSRC}/*.dat`; do \
		${INSTALL_DATA} $$dat ${SHAREDIR}/data ; \
	done

.include <bsd.port.mk>
