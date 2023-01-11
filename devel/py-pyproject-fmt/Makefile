PORTNAME=	pyproject-fmt
PORTVERSION=	0.3.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyproject_fmt-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Format your pyproject.toml file
WWW=		https://github.com/tox-dev/pyproject-fmt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=21.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.11.3:textproc/py-tomlkit@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.3:devel/py-typing-extensions@${PY_FLAVOR}
.endif

post-patch:
	@${RM} ${WRKSRC}/pyproject.toml
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.post.mk>
