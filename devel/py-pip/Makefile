# New ports collection makefile for:	pip
# Date created:		2009-01-19
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pip
PORTVERSION=	0.6.1
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		LOCAL/nivit/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Pip installs (Python) packages. An easy_install replacement

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0.6c9:${PORTSDIR}/devel/py-setuptools

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

REINPLACE_ARGS=	-i.bak -e "s/env python$$/&${PYTHON_VER}/"

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	${FIND} ${WRKSRC} -type f -name "pip*" -print0 | ${XARGS} -0 ${REINPLACE_CMD}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
