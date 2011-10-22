# New ports collection makefile for:	py-virtualenvwrapper
# Date created:		2010-05-06
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	virtualenvwrapper
PORTVERSION=	2.10.1
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://www.doughellmann.com/downloads/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A set of extensions to Virtual Python Environment builder

RUN_DEPENDS=	${PKGNAMEPREFIX}virtualenv>=1.4.8:${PORTSDIR}/devel/py-virtualenv

USE_PYDISTUTILS=	easy_install
USE_PYTHON=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs/html && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
