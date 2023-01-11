PORTNAME=	llfuse
PORTVERSION=	1.4.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for low-level FUSE API
WWW=		https://github.com/python-llfuse/python-llfuse/

LICENSE=	LGPL20+

USES=		compiler:c++11-lang fuse pkgconfig python
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/llfuse*.so

do-test:
	# apparently the code does not understand FreeBSD's /proc/NNN/status layout and looks for a line
	# prefixed Groups: which FreeBSD 13 does not provide.
	cd ${WRKSRC} && ${SETENV} PYTHONPATH=${STAGEDIR}${PREFIX}/lib/python3.9/site-packages ${PYTHON_CMD} -m pytest -x

.include <bsd.port.mk>
