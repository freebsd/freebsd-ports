# ex:ts=8
# New ports collection makefile for:	py-ansistyle
# Date created:			Nov 2, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ansistyle
PORTVERSION=	0.6.1
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.livinglogic.de/ansistyle/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ll-${PORTNAME}-${PORTVERSION}

MAINTAINER=	whitekid@gmail.com
COMMENT=	Add ANSI color capability to output streams

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ll/__init__.py:${PORTSDIR}/devel/py-ll-core

USE_PYTHON=	2.4+
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
