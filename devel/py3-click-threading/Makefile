# Created by: rs.os
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../py-click-threading

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py3-click
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py3-pytest \
		${RUN_DEPENDS}

USES=		python:3.3+

.include "${MASTERDIR}/Makefile"
