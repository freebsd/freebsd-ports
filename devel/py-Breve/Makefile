# New ports collection makefile for:	py-breve
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Breve
PORTVERSION=	1.1.6
CATEGORIES=	devel python
MASTER_SITES=	http://breve.twisty-industries.com/downloads/ \
		LOCAL/nivit/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A Python s-expression style template engine

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	${PYTHON_SITELIBDIR:S|${PREFIX}/||}/${PYEASYINSTALL_EGG}

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
