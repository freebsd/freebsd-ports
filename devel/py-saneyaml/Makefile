# $FreeBSD$

PORTNAME=	saneyaml
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Dump readable YAML and load safely any YAML data

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/apache-2.0.LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	nexB

NO_ARCH=	yes

.include <bsd.port.mk>
