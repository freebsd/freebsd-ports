# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	filedepot
PORTVERSION=	0.8.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit for storing files and attachments in web applications

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}anyascii>=0:textproc/py-anyascii@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
