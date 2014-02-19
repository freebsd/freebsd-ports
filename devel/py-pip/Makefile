# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pip
PORTVERSION=	1.5.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tool for installing and managing Python packages

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS

USES=			shebangfix
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

SHEBANG_FILES=	pip/__init__.py
python_OLD_CMD=	/usr/bin/env python
python_CMD=	${PYTHON_CMD}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
