PORTNAME=	frozenlist
PORTVERSION=	1.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	List-like structure which implements collections.abc.MutableSequence

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gettext-runtime python:3.7+
USE_PYTHON=	autoplist cython distutils

pre-configure:
	@cd ${WRKSRC} && ${RM} frozenlist/_frozenlist.c && cython-${PYTHON_VER} -3 -I frozenlist -o frozenlist/_frozenlist.c frozenlist/_frozenlist.pyx

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
