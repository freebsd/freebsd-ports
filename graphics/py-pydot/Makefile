# Created by: Stefan Walter <sw@gegenunendlich.de>
# $FreeBSD$

PORTNAME=	pydot
PORTVERSION=	1.0.29
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the Graphviz Dot language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing \
		dot:graphics/graphviz

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

GH_ACCOUNT=	erocarrera
GH_TAGNAME=	ec21a11
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|__version__ = .*|__version__ = '${PORTVERSION}'|" ${WRKSRC}/pydot.py

.include <bsd.port.mk>
