# New ports collection makefile for:	mical
# Date created:		10 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mical
PORTVERSION=	1.0.2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.0x1.org/d/projects/mical/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Minimalist iCalendar toolset

RUN_DEPENDS=	py*-dateutil>=1.1:${PORTSDIR}/devel/py-dateutil \
		py*-vobject>=0.4.8:${PORTSDIR}/deskutils/py-vobject

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
MAN1=		micreply.1 micshow.1

.include <bsd.port.mk>
