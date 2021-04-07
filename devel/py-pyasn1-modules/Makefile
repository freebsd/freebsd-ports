PORTNAME=	pyasn1-modules
DISTVERSION=	0.2.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Collection of ASN.1 data structures for py-pyasn1

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0.4.1:devel/py-pyasn1@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.6+ shebangfix
SHEBANG_FILES=	tools/*.py
USE_PYTHON=	autoplist concurrent distutils

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CHANGES.txt README.md
TOOLS=		cmcdump.py cmpdump.py crldump.py crmfdump.py ocspclient.py \
		ocspreqdump.py ocsprspdump.py pkcs10dump.py pkcs1dump.py \
		pkcs7dump.py pkcs8dump.py snmpget.py x509dump-rfc5280.py \
		x509dump.py

post-install:
	${INSTALL_SCRIPT} ${TOOLS:S|^|${WRKSRC}/tools/|} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
