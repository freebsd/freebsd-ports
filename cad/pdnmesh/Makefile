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

USE_XLIB=	yes
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=	pdnmesh.1
MAN5=	pdnmesh_input.5

.include <bsd.port.mk>
