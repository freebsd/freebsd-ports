# $FreeBSD$

PORTNAME=	bsd
PORTVERSION=	1.0.20170329
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python wrappers for various BSD libc and system calls

LICENSE=	BSD3CLAUSE

BROKEN=		fails to build

BUILD_DEPENDS=	cython>0:lang/cython \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six

USE_GITHUB=     yes
GH_ACCOUNT=	freenas
GH_PROJECT=	py-bsd
GH_TAGNAME=	6d148fa

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34
.endif

.include <bsd.port.post.mk>
