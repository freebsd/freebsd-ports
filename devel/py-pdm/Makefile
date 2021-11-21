# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pdm
PORTVERSION=	1.10.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Development Master

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}atoml>=1.0.3:textproc/py-atoml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}installer>=0.3.0<0.5:devel/py-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdm-pep517>=0.8.3<0.9:devel/py-pdm-pep517@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pep517>=0.11.0:devel/py-pep517@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=20.1:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=0.15<1:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pythonfinder>=0:devel/py-pythonfinder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}resolvelib07>=0.7.0<0.8.0:devel/py-resolvelib07@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shellingham>=1.3.2<2.0.0:devel/py-shellingham@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=1.1.0<2.0.0:textproc/py-tomli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.36.2<1.0.0:devel/py-wheel@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.post.mk>
