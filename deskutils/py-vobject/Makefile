# New ports collection makefile for:	py-vobject
# Date created:		10 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vobject
PORTVERSION=	0.8.1c
PORTREVISION=	1
CATEGORIES=	deskutils python
MASTER_SITES=	http://vobject.skyhouseconsulting.com/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	ICalendar library

RUN_DEPENDS=	py*-dateutil>=1.1:${PORTSDIR}/devel/py-dateutil

USE_PYTHON=	2.5+
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
