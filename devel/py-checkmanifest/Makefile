# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	checkmanifest
PORTVERSION=	0.21
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	check-manifest-${PORTVERSION}

MAINTAINER=	xmj@chaot.net
COMMENT=	Check MANIFEST.in in a Python source package for completeness

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PYTHON_CONCURRENT_INSTALL=	yes

PORTDOCS=	README.rst \
		CHANGES.rst

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
