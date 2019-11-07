# $FreeBSD$

PORTNAME=	pyjq
PORTVERSION=	2.4.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Python binding for jq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjq.so:textproc/jq \
		libonig.so:devel/oniguruma

USES=		localbase python
USE_PYTHON=	autoplist distutils

post-patch:
	@${RM} -r ${WRKSRC}/dependencies

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/python3.6/site-packages/_pyjq.so

.include <bsd.port.mk>
