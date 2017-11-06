
MASTERDIR=	${.CURDIR}/../py-pygit2

USES=	python:3.3+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py3-cffi
RUN_DEPENDS=   ${BUILD_DEPENDS} \
                ${PYTHON_PKGNAMEPREFIX}six>0:devel/py3-six

.include "${MASTERDIR}/Makefile"
