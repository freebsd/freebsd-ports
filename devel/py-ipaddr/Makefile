# Created by: Murilo Opsfelder <mopsfelder@gmail.com>
# $FreeBSD$

PORTNAME=	ipaddr
PORTVERSION=	2.1.10
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mopsfelder@gmail.com
COMMENT=	A Google open source IPv4/IPv6 manipulation library in Python

PROJECTHOST=	ipaddr-py
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	ipaddr

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/ipaddr.py \
		%%PYTHON_SITELIBDIR%%/ipaddr.pyc \
		%%PYTHON_SITELIBDIR%%/ipaddr.pyo

NO_STAGE=	yes
.include <bsd.port.mk>
