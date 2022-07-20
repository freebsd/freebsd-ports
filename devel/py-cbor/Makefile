PORTNAME=	cbor
PORTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RFC 7049 - Concise Binary Object Representation

LICENSE=	APACHE20

USES=		compiler python:3.6+
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc && ${COMPILER_VERSION} <= 42
post-patch:
	@${REINPLACE_CMD} -e '/pragma/d' ${WRKSRC}/c/cbormodule.c
.endif

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
