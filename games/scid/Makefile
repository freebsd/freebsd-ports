# ex:ts=8
# Ports collection makefile for:	scid
# Date created:			Mar 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scid
PORTVERSION=	3.4
CATEGORIES=	games databases
MASTER_SITES=	http://scid.sourceforge.net/download/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	volkmann@inode.at

LIB_DEPENDS=	tcl84:${PORTSDIR}/lang/tcl84 \
		tk84:${PORTSDIR}/x11-toolkits/tk84

USE_PYTHON=	yes
USE_XLIB=	yes
USE_GMAKE=	yes

ALL_TARGET=	all strip

.include <bsd.port.mk>
