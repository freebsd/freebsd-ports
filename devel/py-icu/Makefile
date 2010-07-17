# New ports collection makefile for: py-icu
# Date created:		26 Sep 2008
# Whom:			bland@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	icu
PORTVERSION=	1.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/P/PyICU
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyICU-${PORTVERSION}

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Python extension wrapping IBM's ICU C++ API

LIB_DEPENDS=	icudata:${PORTSDIR}/devel/icu

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	PyICU
PYEASYINSTALL_ARCHDEP=	yes

MAKE_ENV+= \
	PYICU_INCLUDES="${PREFIX}/include" \
	PYICU_CFLAGS="-w" \
	PYICU_LFLAGS="-L${PREFIX}/lib" \
	PYICU_LIBRARIES="icui18n:icuuc:icudata"

.include <bsd.port.mk>
