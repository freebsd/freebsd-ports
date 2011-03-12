# New ports collection makefile for:	pip
# Date created:		2009-01-19
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pip
PORTVERSION=	0.8.3
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		LOCAL/nivit/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Pip installs (Python) packages. An easy_install replacement

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

REINPLACE_ARGS=	-i.bak -e "s/env python$$/&${PYTHON_VER}/"

PLIST_SUB=	PYTHON_VER=${PYTHON_VER}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

post-patch:
	${FIND} ${WRKSRC} -type f -name "pip*" -print0 | ${XARGS} -0 ${REINPLACE_CMD}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs/_build && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
