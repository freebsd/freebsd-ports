# New ports collection makefile for:	py-ruledispatch
# Date created:		15 December 2006
# Whom:			Dryice Liu	<dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	RuleDispatch
PORTVERSION=	0.5.a1.r2506
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://nivi.interfree.it/distfiles/${PORTNAME}/ \
		http://peak.telecommunity.com/snapshots/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-0.5a1.dev-r2506

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Rule-based Dispatching and Generic Functions

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}PyProtocols>=1.0.a0.r2302:${PORTSDIR}/devel/py-protocols-devel \
		${PYTHON_PKGNAMEPREFIX}Extremes>=1.1:${PORTSDIR}/devel/py-extremes

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGVERSION=	0.5a1.dev_r2506
PYEASYINSTALL_ARCHDEP=	yes

PLIST_FILES+=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
