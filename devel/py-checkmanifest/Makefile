# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	checkmanifest
PORTVERSION=	0.17
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	check-manifest-${PORTVERSION}

MAINTAINER=	xmj@chaot.net
COMMENT=	Check MANIFEST.in in a Python source package for completeness

LICENSE=	MIT

PORTDOCS=	README.rst \
		CHANGES.rst

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	check_manifest

OPTIONS_DEFINE=	DOCS
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
