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

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@ ${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in ACKS.txt CHANGES.txt INSTALL.txt LICENSE.txt README.txt doc/FAQ.txt
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
