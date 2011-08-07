# New ports collection makefile for:	pip
# Date created:		2009-01-19
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pip
PORTVERSION=	1.0.2
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

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

post-patch:
	${REINPLACE_CMD} ${WRKSRC}/pip/__init__.py

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
