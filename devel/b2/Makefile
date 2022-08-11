PORTNAME=	b2
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.8
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Command Line Interface for Backblaze's B2 storage service

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arrow>=0.8.0:devel/py-arrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}logfury>=0.1.2:devel/py-logfury@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.9.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.5.0:misc/py-tqdm@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist concurrent optsuffix

CONFLICTS_INSTALL=	boost_build

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Backblaze
GH_PROJECT=	B2_Command_Line_Tool

.include <bsd.port.mk>
