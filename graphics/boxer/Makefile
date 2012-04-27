# Ports collection makefile for:	boxer
# Date created:		2010-11-20
# Whom:			Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	boxer
PORTVERSION=	0.3.7
CATEGORIES=	graphics
MASTER_SITES=	SF/boxc/${PORTNAME:C/^b/B/}%20-%20the%20Box%20GUI/${DISTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for Box the figure description language

LICENSE=	GPLv3 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	box:${PORTSDIR}/graphics/box

USE_GNOME=	pygtk2

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
