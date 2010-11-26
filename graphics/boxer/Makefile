# Ports collection makefile for:	boxer
# Date created:		2010-11-20
# Whom:			Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	boxer
PORTVERSION=	0.2.0
CATEGORIES=	graphics
MASTER_SITES=	SF/boxc/${PORTNAME:C/^b/B/}%20-%20the%20Box%20GUI/${DISTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	corky1951@comcast.net
COMMENT=	GUI for Box the figure description language

RUN_DEPENDS=	box:${PORTSDIR}/graphics/box

USE_GNOME=	pygtk2

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
