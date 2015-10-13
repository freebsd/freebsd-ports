# $FreeBSD$

PORTNAME=	pyvisa
PORTVERSION=	1.8
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Python VISA bindings for GPIB, RS232, and USB instruments

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyvisa-py>0:${PORTSDIR}/devel/pyvisa-py

USE_GITHUB=	yes
GH_ACCOUNT=	hgrecco

USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>0:${PORTSDIR}/devel/py-enum34
.endif

.include <bsd.port.post.mk>
