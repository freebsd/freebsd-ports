PORTNAME=	ctags
PORTVERSION=	1.0.5
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-ctags-${PORTVERSION}

MAINTAINER=	ahkdiep@gmail.com
COMMENT=	Python bindings for ctags index file
WWW=		https://pypi.org/project/python-ctags/

LICENSE=	LGPL20+

USES=		python:3.9
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
