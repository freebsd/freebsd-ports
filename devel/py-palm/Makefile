# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	palm
PORTVERSION=	0.1.7
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Fast Protocol Buffer library for Python

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simpleparse>0:devel/py-simpleparse@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e 's|"protobuf>=2.4.1,<=2.4.999"|"protobuf>=2.4.1"|' \
		${WRKSRC}/setup.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/palm/palm.so

.include <bsd.port.mk>
