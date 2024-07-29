PORTNAME=	rrdtool
DISTVERSION=	0.1.16
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX} # Bindings name is different from https://pypi.org/project/rrdtool/

MAINTAINER=	darius@dons.net.au
COMMENT=	Python interface to RRDTool, the graphing and logging utility
WWW=		https://github.com/commx/python-rrdtool

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librrd.so:databases/rrdtool

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/rrdtool*.so

.include <bsd.port.mk>
