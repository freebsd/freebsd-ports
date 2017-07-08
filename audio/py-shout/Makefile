# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	shout
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	audio python
MASTER_SITES=	http://downloads.us.xiph.org/releases/libshout/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python bindings for libshout2

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libshout.so:audio/libshout

OPTIONS_DEFINE=	EXAMPLES

USES=		pkgconfig python:2 shebangfix
SHEBANG_FILES=	example.py
USE_PYTHON=	autoplist distutils

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTEXAMPLES=	example.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/shout.so

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/example.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
