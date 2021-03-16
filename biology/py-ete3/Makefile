# $FreeBSD$

PORTNAME=	ete3
DISTVERSION=	3.1.2
PORTREVISION=	4
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for the analysis and visualization of trees

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.5+ pyqt:5 shebangfix
SHEBANG_GLOB=	*.py
USE_PYTHON=	distutils concurrent autoplist
USE_PYQT=	core gui opengl printsupport svg widgets

NO_ARCH=	yes

.include <bsd.port.mk>
