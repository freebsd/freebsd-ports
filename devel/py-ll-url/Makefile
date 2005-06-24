# New ports collection makefile for:	ll-url
# Date created:		2005-06-23
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	ll-url
PORTVERSION=	0.15.1
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.livinglogic.de/url/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	whitekid@gmail.com
COMMENT=	RFC2396 implementation of URLs and file like classes for URLs

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ll/__init__.py:${PORTSDIR}/devel/py-ll-core

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
USE_BZIP2=	yes

.include <bsd.port.mk>
