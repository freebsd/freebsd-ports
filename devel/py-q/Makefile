# $FreeBSD$

PORTNAME=	q
DISTVERSION=	2.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Quick-and-dirty debugging output for tired programmers

LICENSE=	APACHE20

USES=		python:3.6+
USE_PYTHON=	distutils autoplist concurrent

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	DOCSDIR=${DOCSDIR}

OPTIONS_DEFINE=	DOCS
PORTDOCS=	README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
