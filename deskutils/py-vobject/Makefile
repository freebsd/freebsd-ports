# New ports collection makefile for:	py-vobject
# Date created:		10 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vobject
PORTVERSION=	0.7.1
CATEGORIES=	deskutils python
MASTER_SITES=	http://vobject.skyhouseconsulting.com/ CENKES
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ICalendar library

RUN_DEPENDS=	py*-dateutil>=1.1:${PORTSDIR}/devel/py-dateutil

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_NOEGGINFO=yes

.include <bsd.port.mk>
