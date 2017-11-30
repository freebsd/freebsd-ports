# $FreeBSD$

PORTNAME=	twext
PORTVERSION=	0.20160818
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	axel.rau@chaos1.de
COMMENT=	Extensions to Twisted

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=15.4.0:devel/py-twisted@${FLAVOR}
RUN_DEPENDS=	\
 ${PYTHON_PKGNAMEPREFIX}cffi>=0.6:devel/py-cffi@${FLAVOR} \
 ${PYTHON_PKGNAMEPREFIX}twisted>=15.4:devel/py-twisted@${FLAVOR}

DAL_RUN_DEPENDS=	\
 ${PYTHON_PKGNAMEPREFIX}sqlparse01>=0.1.19:databases/py-sqlparse01@${FLAVOR} \

POSTGRES_RUN_DEPENDS=	\
 ${PYTHON_PKGNAMEPREFIX}pg8000>=1.10.2:databases/py-pg8000@${FLAVOR}

OPTIONS_DEFINE=	DAL POSTGRES
DAL_DESC=	Enables use of the Database Abstraction Layer.
POSTGRES=	Enables support for Postgres database connectivity.
OPTIONS_DEFAULT=	DAL POSTGRES
.include <bsd.port.options.mk>

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=yes

USE_GITHUB=	yes
GH_ACCOUNT=	apple
GH_PROJECT=	ccs-twistedextensions
GH_TAGNAME=	a8528bc

post-patch:
	@${REINPLACE_CMD} -e 's|"{}a1+unknown".format(base_version)|"0.20160928"|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
