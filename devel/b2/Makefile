# Created by: Bartek Rutkowski <robak@FreeBSD.org>
# $FreeBSD$

PORTNAME=	b2
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	devel

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Command Line Interface for Backblaze's B2 storage service

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arrow>=0.8.0:devel/py-arrow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}logfury>=0.1.2:devel/py-logfury@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.9.1:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.5.0:misc/py-tqdm@${FLAVOR}

USES=		python:2.7+
USE_PYTHON=	distutils autoplist concurrent optsuffix

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Backblaze
GH_PROJECT=	B2_Command_Line_Tool

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}futures>=3.0.5:devel/py-futures@${FLAVOR}
.endif

.include <bsd.port.post.mk>
