# Created by: Florian Limberger <flo@snakeoilproductions.net>
# $FreeBSD$

PORTNAME=	mypy
PORTVERSION=	0.521
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	flo@snakeoilproductions.net
COMMENT=	Optional static typing for Python

LICENSE=	MIT PSFL
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typed-ast>=1.0.0:devel/py-typed-ast

NO_ARCH=	yes
USES=		python:3.3+ shebangfix
USE_PYTHON=	autoplist distutils
SHEBANG_FILES=	typeshed/tests/pytype_test.py		

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} < 3.5
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing>=3.5.3:devel/py-typing
.endif

.include <bsd.port.post.mk>
