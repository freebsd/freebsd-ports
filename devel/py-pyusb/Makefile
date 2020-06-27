# $FreeBSD$

PORTNAME=	pyusb
PORTVERSION=	1.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python wrapper around libusb

LICENSE=	BSD3CLAUSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

USE_GITHUB=	yes

#NO_ARCH=	yes

PORTDOCS=	*.rst

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}

test: extract
	@(cd ${WRKSRC}/tests && ${PYTHON_CMD} testall.py)

.include <bsd.port.mk>
