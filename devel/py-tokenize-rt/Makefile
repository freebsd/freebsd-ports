# $FreeBSD$

PORTNAME=	tokenize-rt
PORTVERSION=	3.2.0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	tokenize_rt-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Wrapper around the stdlib `tokenize` which roundtrips

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing>=0:devel/py-typing@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
