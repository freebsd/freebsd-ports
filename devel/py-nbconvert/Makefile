# $FreeBSD$

PORTNAME=	nbconvert
PORTVERSION=	5.1.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Converting Jupyter Notebooks

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}bleach>=0:www/py-bleach \
		${PYTHON_PKGNAMEPREFIX}entrypoints>=0.2.2:devel/py-entrypoints \
		${PYTHON_PKGNAMEPREFIX}jupyter_client>=0:devel/py-jupyter_client \
		${PYTHON_PKGNAMEPREFIX}jupyter_core>=0:devel/py-jupyter_core \
		${PYTHON_PKGNAMEPREFIX}mistune>=0:textproc/py-mistune \
		${PYTHON_PKGNAMEPREFIX}nbformat>=0:devel/py-nbformat \
		${PYTHON_PKGNAMEPREFIX}pandocfilters>=1.4.1:textproc/py-pandocfilters \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}testpath>=0:devel/py-testpath \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.2:devel/py-traitlets

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
