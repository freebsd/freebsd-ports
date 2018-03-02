# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	send2trash
PORTVERSION=	1.3.0
CATEGORIES=	deskutils
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Send2Trash-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	koalative@gmail.com
COMMENT=	Small package that sends files to the Trash

LICENSE=	BSD3CLAUSE

USES=		python
USE_PYTHON=	distutils autoplist

PORTDOCS=	CHANGES.rst README.rst
OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
