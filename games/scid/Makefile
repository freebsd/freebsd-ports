# ex:ts=8
# Ports collection makefile for:	scid
# Date created:			Mar 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scid
PORTVERSION=	3.6.26
CATEGORIES=	games databases
MASTER_SITES=	SF

MAINTAINER=	bsd@volki.at
COMMENT=	A free chess database application

LIB_DEPENDS=	tcl85:${PORTSDIR}/lang/tcl85 \
		tk85:${PORTSDIR}/x11-toolkits/tk85

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes

ALL_TARGET=	all strip

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
