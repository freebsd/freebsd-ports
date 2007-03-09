# New ports collection makefile for:	py-tada
# Date created:		2005-09-18
# Whom:			clive crous <clive@darkarts.co.za>
#
# $FreeBSD$
#

PORTNAME=	tada
PORTVERSION=	1.4.0
CATEGORIES=	databases python
MASTER_SITES=	http://www.darkarts.co.za/projects/${PORTNAME}/attachment/wiki/downloads/${PORTVERSION}/
EXTRACT_SUFX=	.tar.gz?format=raw
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	clive@darkarts.co.za
COMMENT=	Twisted Asynchronous Database API

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
