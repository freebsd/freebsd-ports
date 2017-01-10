# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	leveldb
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Thread-safe Python binding for LevelDB

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libleveldb.so:databases/leveldb

PORTSCOUT=	skipv:0.194

USE_PYTHON=	autoplist concurrent distutils
USES=		localbase python

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/${PYSETUP}
	@${RM} -r ${WRKSRC}/leveldb/ ${WRKSRC}/snappy/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/leveldb.so

.include <bsd.port.mk>
