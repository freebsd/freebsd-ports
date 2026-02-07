PORTNAME=	commoncode
DISTVERSION=	32.2.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tuukka.pasanen@ilmi.fi
COMMENT=	Set of common utilities, originally split from ScanCode
WWW=		https://github.com/aboutcode-org/commoncode

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/apache-2.0.LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=25.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.13.0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=2.8:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>2.7.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}saneyaml>0.5.2:devel/py-saneyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}text-unidecode>1.0:converters/py-text-unidecode@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest
PYTEST_BROKEN_TESTS=	test_parse_os_release test_is_readable_is_writeable_dir \
			test_is_readable_is_writeable_file \
			test_chmod_read_write_file \
			test_chmod_read_write_non_recursively_on_dir \
			test_chmod_read_write_recursively_on_dir \
			test_copyfile_does_not_keep_permissions \
			test_copytree_copies_unreadable_files \
			test_copytree_does_not_keep_non_writable_permissions \
			test_resource_iter_can_walk_unicode_path_with_zip

NO_ARCH=	yes

.include <bsd.port.mk>
