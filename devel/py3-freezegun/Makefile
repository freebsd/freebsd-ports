# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../py-freezegun

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py3-six \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.0:devel/py3-dateutil
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py3-nose \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py3-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py3-mock

USES=		python:3.3+

.include "${MASTERDIR}/Makefile"
