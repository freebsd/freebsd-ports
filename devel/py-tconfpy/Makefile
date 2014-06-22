# Created by: tundra
# $FreeBSD$

PORTNAME=	tconfpy
PORTVERSION=	2.112
CATEGORIES=	devel python
MASTER_SITES=	http://www.tundraware.com/Software/tconfpy/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	tconfpy@tundraware.com
COMMENT=	Python Configuration File Parser

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	READ-1ST.txt WHATSNEW.txt tconfpy-license.txt tconfpy.html tconfpy.pdf tconfpy.ps tconfpy.txt test-tc.html test-tc.pdf test-tc.ps test-tc.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/test-tc.1.gz ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/tconfpy.3.gz ${STAGEDIR}${PREFIX}/man/man3/

.include <bsd.port.mk>
