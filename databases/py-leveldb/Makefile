# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	leveldb
PORTVERSION=	0.201
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Thread-safe Python binding for LevelDB

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libleveldb.so:databases/leveldb

PORTSCOUT=	skipv:0.194

USES=		compiler:c11 localbase python
USE_PYTHON=	autoplist concurrent distutils

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/setup.py
	@${RM} -r ${WRKSRC}/leveldb/ ${WRKSRC}/snappy/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/leveldb.so

.include <bsd.port.mk>
