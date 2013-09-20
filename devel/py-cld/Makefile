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

LICENSE=	BSD

LIB_DEPENDS=	cld:${PORTSDIR}/devel/cld

USES=		pkgconfig
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	chromium_compact_language_detector

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/cld.so

NO_STAGE=	yes
.include <bsd.port.mk>
