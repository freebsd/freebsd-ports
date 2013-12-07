# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	yunomi
PORTVERSION=	0.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	Metrics library with rate, distribution and timing information

LICENSE=	MIT

PORTDOCS=	README.rst \
		HISTORY.rst

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
