PORTNAME=	meson
PORTVERSION=	1.10.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	https://github.com/mesonbuild/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	High performance build system
WWW=		https://mesonbuild.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-subtests>0:devel/py-pytest-subtests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastjsonschema>0:devel/py-fastjsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		git:devel/git \
		pkg-config:devel/pkgconf \
		rustc:lang/${RUST_DEFAULT} \
		gcc${GCC_DEFAULT}:lang/gcc${GCC_DEFAULT}

USES=		ninja:run python shebangfix vala:test
USE_PYTHON=	autoplist cython_test optsuffix pep517 pytest
SHEBANG_FILES=	mesonbuild/rewriter.py \
		mesonbuild/scripts/cmake_run_ctgt.py
NO_ARCH=	yes

# https://github.com/mesonbuild/meson/issues/6016
TEST_ENV=	${MAKE_ENV:NCC=*:NCXX=*}

.if make(test)
NO_CCACHE=	yes
.endif

# Hide from regular build to avoid accidental dependency on symlinks
.if make(test) || ("${WITH_TESTING}" == yes && make(package))
# helper_create_binary_wrapper, test_python_module, test cases/*.py
BINARY_ALIAS+=	python3=${PYTHON_CMD:T} python=${PYTHON_CMD:T}
pre-test: create-binary-alias # force if run late
.endif

# test_pkgconfig_formatting		separate libintl not expected
# test_static_link			pkgconf: Package 'func6' not found
PYTEST_BROKEN_TESTS=	test_pkgconfig_formatting \
			test_static_link

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python3|${PYTHON_CMD}|' \
		-e 's|/usr/bin/meson|${LOCALBASE}/bin/meson|' \
		${WRKSRC}/data/com.mesonbuild.install.policy
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		-e "s|'lib', 'pkgconfig'|'libdata', 'pkgconfig'|g" \
		-e "s|self.libdir, 'pkgconfig'|'libdata', 'pkgconfig'|g" \
		-e "s|yonder_libdir, 'pkgconfig'|yonder_prefix, 'libdata', 'pkgconfig'|g" \
		${WRKSRC}/unittests/internaltests.py \
		${WRKSRC}/unittests/linuxliketests.py
	@${REINPLACE_CMD} -e "s|'gcc'|'gcc${GCC_DEFAULT}'|g" \
		${WRKSRC}/unittests/internaltests.py

.include <bsd.port.mk>
