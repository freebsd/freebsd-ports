# New ports collection makefile for:	pdnmesh
# Date created:			25 August 2001
# Whom:				Sarod Yatawatta <sarod@cs.pdn.ac.lk>
#
# $FreeBSD$
#

PORTNAME=	pdnmesh
PORTVERSION=	0.1.2
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	${PORTNAME} science/visualization

MAINTAINER=	sarod@cs.pdn.ac.lk

USE_XLIB=	yes
USE_MESA=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=	pdnmesh.1 d2m.1
MAN5=	pdnmesh_input.5

.include <bsd.port.mk>
