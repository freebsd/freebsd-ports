PORTNAME=	durus
PORTVERSION=	3.9
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		http://www.mems-exchange.org/software/durus/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Durus-${PORTVERSION}

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Persistent object storage system for Python
WWW=		https://www.mems-exchange.org/software/durus/

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@ ${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in ACKS.txt CHANGES.txt INSTALL.txt LICENSE.txt README.txt doc/FAQ.txt
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
