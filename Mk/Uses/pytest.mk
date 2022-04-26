# handle testing with pytest
#
# Feature:	pytest
# Usage:	USES=pytest[:4]
#
# It implies USES=python:test automatically if no USES=python has been
# specified yet
#
# It provides the following additional variables to set by the ports:
#
# PYTEST_ARGS		additional args to pytest (defaults to empty).
# PYTEST_IGNORED_TESTS	lists of `pytest -k` patterns of tests to ignore
# 			(defaults to empty). For tests which are not
#			expected to pass, such as ones requiring a database
#			access.
# PYTEST_BROKEN_TESTS	lists of `pytest -k` patterns of tests to ignore
# 			(defaults to empty). For broken tests which require
#			fixing.
#
# The following variables may be set by the user:
#
# PYTEST_ENABLE_IGNORED_TESTS	enable tests which are otherwise ignored by
#				PYTEST_IGNORED_TESTS.
# PYTEST_ENABLE_BROKEN_TESTS	enable tests which are otherwise ignored by
#				PYTEST_BROKEN_TESTS.
# PYTEST_ENABLE_ALL_TESTS	enable tests which are otherwise ignored by
#				PYTEST_IGNORED_TESTS and PYTEST_BROKEN_TESTS.
#
# MAINTAINER: amdmi3@FreeBSD.org

.if !defined(_INCLUDE_USES_PYTEST_MK)
_INCLUDE_USES_PYTEST_MK=	yes

.  if !${USES:Mpython*}
python_ARGS=	test
.    include "${USESDIR}/python.mk"
.  endif

.  if empty(pytest_ARGS)
TEST_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}
.  elif ${pytest_ARGS} == "4"
TEST_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}pytest4>=0:devel/py-pytest4@${PY_FLAVOR}
.  else
IGNORE=	Incorrect 'USES+=pytest:${pytest_ARGS}' expecting 'USES+=pytest[:4]'
.  endif

PYTEST_IGNORED_TESTS?=	# empty
PYTEST_BROKEN_TESTS?=	# empty
PYTEST_ARGS?=		# empty

_PYTEST_ALL_IGNORED_TESTS?=	# empty
.  if !defined(PYTEST_ENABLE_IGNORED_TESTS) && !defined(PYTEST_ENABLE_ALL_TESTS)
_PYTEST_ALL_IGNORED_TESTS+=	${PYTEST_IGNORED_TESTS}
.  endif
.  if !defined(PYTEST_ENABLE_BROKEN_TESTS) && !defined(PYTEST_ENABLE_ALL_TESTS)
_PYTEST_ALL_IGNORED_TESTS+=	${PYTEST_BROKEN_TESTS}
.  endif

_PYTEST_FILTER_EXPRESSION=	${_PYTEST_ALL_IGNORED_TESTS:C/^(.)/and not \1/:tW:C/^and //}

.  if !target(do-test)
do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest \
		-k '${_PYTEST_FILTER_EXPRESSION}' \
		-v -rs -o addopts= \
		${PYTEST_ARGS}
.  endif

.endif
