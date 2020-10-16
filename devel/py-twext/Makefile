# $FreeBSD$

PORTNAME=	twext
PORTVERSION=	0.20170227
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	axel.rau@chaos1.de
COMMENT=	Extensions to Twisted

LICENSE=	APACHE20

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-11-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=16.6.0:devel/py-twisted@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=0.6:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=16.6:devel/py-twisted@${PY_FLAVOR}

OPTIONS_DEFINE=		DAL POSTGRES
OPTIONS_DEFAULT=	DAL POSTGRES

DAL_DESC=		Enables use of the Database Abstraction Layer.
POSTGRES_DESC=		Enables support for Postgres database connectivity.

DAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlparse020>=0.2.0:databases/py-sqlparse020@${PY_FLAVOR}
POSTGRES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pg8000-112>=1.10.2:databases/py-pg8000-112@${PY_FLAVOR}

.include <bsd.port.options.mk>

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	apple
GH_PROJECT=	ccs-twistedextensions
GH_TAGNAME=	2c4046d

post-patch:
	@${REINPLACE_CMD} -e 's|"{}a1+unknown".format(base_version)|"${PORTVERSION}"|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
