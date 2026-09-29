PORTNAME=	coherent.deps
PORTVERSION=	1.7.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	coherent_deps-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utilities for resolving imports to dependencies
WWW=		https://github.com/coherent-oss/coherent.deps

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.11<5:devel/py-flit-core@${PY_FLAVOR}
xRUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco.collections>=0:devel/py-jaraco.collections@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.compat>=4.4:devel/py-jaraco.compat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.context>=0:devel/py-jaraco.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.functools>=0:devel/py-jaraco.functools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.mongodb>=0:devel/py-jaraco.mongodb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.ui>=0:devel/py-jaraco.ui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>=0,1:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-file>=0:www/py-requests-file@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}retry-requests>=0:www/py-retry-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tempora>=0:devel/py-tempora@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zipp>=0:devel/py-zipp@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes
PEP517_INSTALL_CMD?=	${PYTHON_CMD} -m installer --destdir ${STAGEDIR} --prefix ${PREFIX} ${BUILD_WRKSRC}/dist/${PORTNAME:C|[-_.]+|_|g}-${PORTVERSION}*.whl

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	@cd ${INSTALL_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${PEP517_INSTALL_CMD}
	@${PYTHON_CMD} -B ${PORTSDIR}/Mk/Scripts/strip_RECORD.py \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME:C|[-_.]+|_|g}-${PORTVERSION}*.dist-info/RECORD >> ${_PYTHONPKGLIST}
	@${REINPLACE_CMD} \
		-e '/\.pyc$$/d' \
		-e 's|^|${PYTHONPREFIX_SITELIBDIR}/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../etc/|etc/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../bin/|bin/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../include/|include/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../lib/|lib/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../libdata/|libdata/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../libexec/|libexec/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../man/|man/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../sbin/|sbin/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../share/|share/|' \
			${_PYTHONPKGLIST}
	@cd ${STAGEDIR}${PREFIX} && ${FIND} lib -name '*.pyc' >> ${_PYTHONPKGLIST}

.include <bsd.port.mk>
