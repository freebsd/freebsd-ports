# $FreeBSD$

PORTNAME=	pyvisa
PORTVERSION=	1.9.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python VISA bindings for GPIB, RS232, and USB instruments

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyvisa-py>0:devel/py-pyvisa-py@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	hgrecco

USES=		python
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34@${FLAVOR}
.endif

.include <bsd.port.post.mk>
