# New ports collection makefile for:	py-rabbyt
# Date created:		12 Oct 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	rabbyt
PORTVERSION=	0.8.2
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP} \
		http://mirror.amdmi3.ru/
MASTER_SITE_SUBDIR=source/R/Rabbyt
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Rabbyt-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A fast sprite library for Python

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Rabbyt
PYEASYINSTALL_ARCHDEP=	yes
USE_GL=			gl glu

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
