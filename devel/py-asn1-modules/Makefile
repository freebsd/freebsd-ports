# $FreeBSD$

PORTNAME=	asn1-modules
PORTVERSION=	0.0.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Collection of ASN.1 data structures for py-asn1

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1>=0.1.8:${PORTSDIR}/devel/py-asn1

NO_ARCH=	yes
USES=		python shebangfix
SHEBANG_FILES=	tools/*.py
USE_PYTHON=	autoplist distutils

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	CHANGES.txt README.txt
TOOLS=		cmpdump.py crldump.py crmfdump.py ocspclient.py ocspreqdump.py \
		ocsprspdump.py pkcs10dump.py pkcs1dump.py pkcs7dump.py \
		pkcs8dump.py snmpget.py x509dump.py

post-install:
	${INSTALL_SCRIPT} ${TOOLS:S|^|${WRKSRC}/tools/|} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
