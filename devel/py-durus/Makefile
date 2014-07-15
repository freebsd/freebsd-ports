# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	durus
PORTVERSION=	3.9
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://www.mems-exchange.org/software/durus/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Durus-${PORTVERSION}

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Persistent object storage system for Python

LICENSE=	MIT

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	Durus

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@ ${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in ACKS.txt CHANGES.txt INSTALL.txt LICENSE.txt README.txt doc/FAQ.txt
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
