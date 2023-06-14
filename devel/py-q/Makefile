PORTNAME=	q
DISTVERSION=	2.7
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Quick-and-dirty debugging output for tired programmers
WWW=		https://github.com/zestyping/q

LICENSE=	APACHE20

USES=		python
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
