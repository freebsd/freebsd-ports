# $FreeBSD$

PORTNAME=	Pyrseas
PORTVERSION=	0.6.1
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Framework and utilities to upgrade and maintain a relational database

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml

USE_GITHUB=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes
NO_STAGE=	yes

GH_ACCOUNT=	jmafc
GH_COMMIT=	9d64338
GH_TAGNAME=	v${PORTVERSION}

.include <bsd.port.mk>
