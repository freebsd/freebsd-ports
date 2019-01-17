# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	typing-extensions
PORTVERSION=	3.7.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	typing_extensions-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Backported and Experimental Type Hints for Python 3.5+

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:-3.6
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3500
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing>=3.6.2:devel/py-typing@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
