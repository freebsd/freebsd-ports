# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	rabbyt
PORTVERSION=	0.8.2
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP/source/R/Rabbyt \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Rabbyt-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A fast sprite library for Python

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Rabbyt
PYEASYINSTALL_ARCHDEP=	yes
USE_GL=			gl glu

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

NO_STAGE=	yes
.include <bsd.port.mk>
