# $FreeBSD$

PORTNAME=	fs
PORTVERSION=	2.4.11
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Python Filesystem abstraction layer, version 2.x

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.3:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10:devel/py-six@${PY_FLAVOR} \
		${PY_TYPING} \
		${PY_ENUM34}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
PORTSCOUT=	limit:^2\.

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.os>=0.1:devel/py-backports.os@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 3500
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}scandir>=1.5:sysutils/py-scandir@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
