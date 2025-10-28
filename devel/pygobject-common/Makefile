PKGNAMEPREFIX=
PKGNAMESUFFIX=	-common

COMMENT=	Common files for Python bindings for GObject Introspection

TEST_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	include/pygobject-3.0/pygobject.h \
		libdata/pkgconfig/pygobject-3.0.pc

# tests/test_glib.py is flaky - its tests fail when run together, but pass when
# executed separately
TEST_ENV=	PYTEST_ADDOPTS='-k "not test_io_add_watch and not test_main_loop"'

SLAVE_PORT=	common

MASTERDIR=	${.CURDIR}/../../devel/py-pygobject

.include "${MASTERDIR}/Makefile"
