# New ports collection makefile for:	py-liblarch_gtk
# Date created:				13 February 2012
# Whom:					Ruslan Mahmatkhanov <rm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liblarch_gtk
PORTVERSION=	0.1.0
CATEGORIES=	devel python
MASTER_SITES=	http://gtg.fritalk.com/publique/gtg.fritalk.com/liblarch/0.1/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GTK binding for Liblarch

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}liblarch>=0:${PORTSDIR}/devel/py-liblarch

USE_GNOME=	pygobject pygtk2
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
