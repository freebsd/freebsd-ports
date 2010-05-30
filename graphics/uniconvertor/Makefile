# New ports collection makefile for:	uniconvertor
# Date created:		15 Nov 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	uniconvertor
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://sk1project.org/downloads/uniconvertor/v${PORTVERSION}/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Universal vector graphics translator

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab2

CONFLICTS=	yudit-[0-9]* netatalk-[0-9]*

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PYDISTUTILS_PKGNAME=UniConvertor

WRKSRC=		${WRKDIR}/UniConvertor-${PORTVERSION}

.include <bsd.port.mk>
