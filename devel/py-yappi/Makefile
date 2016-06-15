# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	yappi
PORTVERSION=	0.94
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	johannes@perceivon.net
COMMENT=	Yet Another Python Profiler

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_yappi.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
