# New ports collection makefile for:	py-liblzma
# Date created:		09 Dec 2008
# Whom:			David Naylor <dragonsa@highveldmail.co.za>
#
# $FreeBSD$

PORTNAME=	liblzma
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}source/p/pyliblzma/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYDISTUTILS_PKGNAME}-${PORTVERSION}

MAINTAINER=	dragonsa@highveldmail.co.za
COMMENT=	Python binding for the LZMA compression library

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	lzma.0:${PORTSDIR}/archivers/xz

USE_BZIP2=	yes
USE_PYTHON=	2.6+
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	py${PORTNAME}

.include <bsd.port.mk>
