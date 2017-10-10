# Created by: Bartek Rutkowski <robak@FreeBSD.org>
# $FreeBSD$

PORTNAME=	b2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
CATEGORIES=	devel

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Command Line Interface for Backblaze's B2 storage service

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arrow>=0.8.0:devel/py-arrow \
		${PYTHON_PKGNAMEPREFIX}logfury>=0.1.2:devel/py-logfury \
		${PYTHON_PKGNAMEPREFIX}requests>=2.9.1:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>=1.10:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.5.0:misc/py-tqdm

USES=		python:2.7+
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	Backblaze
GH_PROJECT=	B2_Command_Line_Tool

.include <bsd.port.mk>
