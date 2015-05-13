# $FreeBSD$

PORTNAME=	usb
PORTVERSION=	1.0.0b1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python wrapper around libusb

LICENSE=	BSD3CLAUSE

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	walac
GH_PROJECT=	py${PORTNAME}
GH_TAGNAME=	0546cad

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX:C/...$//}-${PORTNAME}
PORTDOCS=	*.rst

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}

regression-test: extract
	@(cd ${WRKSRC}/tests && ${PYTHON_CMD} testall.py)

.include <bsd.port.mk>
