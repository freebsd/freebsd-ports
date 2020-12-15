# Created by: Rui Lopes <rgl ruilopes com>
# $FreeBSD$

PORTNAME=	tailor
PORTVERSION=	0.9.36
CATEGORIES=	devel python
MASTER_SITES=	https://BSDforge.com/projects/source/devel/tailor/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Migrates changesets between version control systems

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}
RUN_DEPENDS=	${LOCALBASE}/bin/rsync:net/rsync \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}

USES=		python:3.7+ tar:txz
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
