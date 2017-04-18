# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	shout
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://downloads.us.xiph.org/releases/libshout/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python bindings for libshout2

LICENSE=	LGPL20

OPTIONS_DEFINE=	EXAMPLES

LIB_DEPENDS=	libshout.so:audio/libshout

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

USES=		pkgconfig python:2 shebangfix
SHEBANG_FILES=	example.py
USE_PYTHON=	distutils autoplist

PORTEXAMPLES=	example.py

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/example.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
