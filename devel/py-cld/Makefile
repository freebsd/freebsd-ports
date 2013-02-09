# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cld
PORTVERSION=	0.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=source/c/chromium_compact_language_detector
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	chromium_compact_language_detector-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Python bindings for chromium compact language detector library

LIB_DEPENDS=	cld:${PORTSDIR}/devel/cld

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=chromium_compact_language_detector

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/cld.so

.include <bsd.port.mk>
