# ex:ts=8
# Ports collection makefile for:	scid
# Date created:			Mar 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scid
PORTVERSION=	3.3
CATEGORIES=	games databases tk83 tcl83
MASTER_SITES=	http://scid.sourceforge.net/download/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	volkmann@chello.at

LIB_DEPENDS=	tcl83:${PORTSDIR}/lang/tcl83 \
		tk83:${PORTSDIR}/x11-toolkits/tk83

USE_PYTHON=	yes
USE_XLIB=	yes
USE_GMAKE=	yes

ALL_TARGET=	all strip

.include <bsd.port.mk>
