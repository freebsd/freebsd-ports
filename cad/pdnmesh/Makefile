# New ports collection makefile for:	pdnmesh
# Date created:			25 August 2001
# Whom:				Sarod Yatawatta <sarod@cs.pdn.ac.lk>
#
# $FreeBSD$
#

PORTNAME=	pdnmesh
PORTVERSION=	0.2.1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:sf/} \
		${MASTER_SITE_SUNSITE:S/$/:sun/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:sf science/visualization/:sun
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sf,sun

MAINTAINER=	sarod@users.sf.net
COMMENT=	A finite element program

LIB_DEPENDS=	gtkglext:${PORTSDIR}/x11-toolkits/gtkglext:install\
		lapack:${PORTSDIR}/math/lapack:install\
		atlas:${PORTSDIR}/math/atlas:install

USE_XLIB=	yes
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

USE_AUTOCONF_VER=259

MAN1=	pdnmesh.1
MAN5=	pdnmesh_input.5

.include <bsd.port.mk>
