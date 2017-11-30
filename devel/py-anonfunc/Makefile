# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	anonfunc
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	LOCAL/perky \
		http://people.freebsd.org/~perky/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module that provides easy anonymous function

LICENSE=	BSD2CLAUSE

USES=		python:2.7
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/anonfunc.so

.include <bsd.port.mk>
