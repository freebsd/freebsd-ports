PORTNAME=	pyyaml
DISTVERSION=	6.0.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python YAML parser
WWW=		https://pyyaml.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe localbase python
USE_PYTHON=	autoplist concurrent cython pep517 pytest

OPTIONS_DEFINE=	LIBYAML EXAMPLES
OPTIONS_DEFAULT=LIBYAML
LIBYAML_DESC=	Use textproc/libyaml for faster parsing

LIBYAML_LIB_DEPENDS=	libyaml.so:textproc/libyaml

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLIBYAML}
PEP517_BUILD_CONFIG_SETTING=	--config-json '{"pyyaml_build_config": "{\"include_dirs\": [\"${LOCALBASE}/include\"], \"library_dirs\": [\"${LOCALBASE}/lib\"]}"}'
MAKE_ENV+=			PYYAML_FORCE_LIBYAML=1
.else
MAKE_ENV+=			PYYAML_FORCE_LIBYAML=0
NO_ARCH=			yes
.endif

post-install-EXAMPLES-on:
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/)

post-install-LIBYAML-on:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/yaml/_yaml*.so

.include <bsd.port.post.mk>

