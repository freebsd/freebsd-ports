# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	shout
PORTVERSION=	0.2.1
CATEGORIES=	audio python
MASTER_SITES=	http://downloads.us.xiph.org/releases/libshout/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python bindings for libshout2

LICENSE=	LGPL20

LIB_DEPENDS=	libshout.so:${PORTSDIR}/audio/libshout2

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

USES=			pkgconfig
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PORTEXAMPLES=	example.py

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/example.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
