PORTNAME=	mrkd
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Write man pages using Markdown, and convert them to Roff or HTML

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=21.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=3.0.6:devel/py-pyparsing@${PY_FLAVOR}

RUN_DEPENDS=	${BUILD_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistune>=0.8.4:textproc/py-mistune@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.7.2:textproc/py-pygments@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils flavors

NO_ARCH=	yes

.include <bsd.port.mk>
