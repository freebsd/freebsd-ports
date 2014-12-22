# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cld
PORTVERSION=	0.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=source/c/chromium_compact_language_detector
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	chromium_compact_language_detector-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Python bindings for chromium compact language detector library

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcld.so:${PORTSDIR}/devel/cld

USES=		pkgconfig python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	chromium_compact_language_detector

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/cld.so

.include <bsd.port.mk>
