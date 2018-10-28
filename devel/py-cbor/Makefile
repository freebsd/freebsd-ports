# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cbor
PORTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RFC 7049 - Concise Binary Object Representation

LICENSE=	APACHE20

USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.pre.mk>

post-patch:
.if ${ARCH:Mmips*} || ${ARCH:Mpowerpc*} || ${ARCH} == sparc64
	@${REINPLACE_CMD} -e '/pragma/d' ${WRKSRC}/c/cbormodule.c
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cbor/_cbor.so

.include <bsd.port.post.mk>
