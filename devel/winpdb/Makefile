# Created by: ijliao
# $FreeBSD$

PORTNAME=	winpdb
PORTVERSION=	1.4.8
PORTREVISION=	5
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Advanced Python debugger

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:security/py-pycrypto

USES=		python
USE_PYTHON=	autoplist distutils
USE_WX=		3.0+
WX_COMPS=	python

.include <bsd.port.mk>
