# $FreeBSD$

PORTNAME=	asn1-modules
PORTVERSION=	0.0.5
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF/pyasn1/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Collection of ASN.1 data structures for py-asn1

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1>=0.1.4:${PORTSDIR}/devel/py-asn1

USES=			shebangfix
SHEBANG_FILES=		tools/*.py
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	CHANGES README
TOOLS=		cmpdump.py crldump.py crmfdump.py ocspclient.py ocspreqdump.py \
		ocsprspdump.py ocspserver.py pkcs10dump.py pkcs1dump.py \
		pkcs7dump.py pkcs8dump.py snmpget.py x509dump.py

post-install:
	${INSTALL_SCRIPT} ${TOOLS:S|^|${WRKSRC}/tools/|} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
