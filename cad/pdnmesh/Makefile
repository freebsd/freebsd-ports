# New ports collection makefile for:	pdnmesh
# Date created:			25 August 2001
# Whom:				Sarod Yatawatta <sarod@cs.pdn.ac.lk>
#
# $FreeBSD$
#

PORTNAME=	pdnmesh
PORTVERSION=	0.1.4
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	${PORTNAME} science/visualization

MAINTAINER=	sarod@users.sf.net
COMMENT=	A finite element program

LIB_DEPENDS=	gtkglext:${PORTSDIR}/x11-toolkits/gtkglext:install

USE_REINPLACE=	yes
USE_XLIB=	yes
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=	pdnmesh.1
MAN5=	pdnmesh_input.5

post-patch:
.for FILE in ${DISTNAME}/src/contour.c
	@${REINPLACE_CMD} -e "s/^\#include <GL\/glut.h>//g" ${WRKSRC}/${FILE}
.endfor

.include <bsd.port.mk>
