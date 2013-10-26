# Created by: ijliao
# $FreeBSD$

PORTNAME=	winpdb
PORTVERSION=	1.4.8
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
MASTER_SITE_SUBDIR=	winpdb

MAINTAINER=	mva@FreeBSD.org
COMMENT=	An advanced Python debugger

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_WX=		2.6+
WX_COMPS=	python
WANT_UNICODE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
