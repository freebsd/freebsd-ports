# $FreeBSD$

PORTNAME=	pytc
PORTVERSION=	0.9
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Tokyo Cabinet Python bindings

LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/setup.py

.include <bsd.port.post.mk>
