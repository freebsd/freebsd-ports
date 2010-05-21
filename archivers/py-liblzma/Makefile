# New ports collection makefile for:	py-liblzma
# Date created:		09 Dec 2008
# Whom:			David Naylor <naylor.b.david@gmail.com>
#
# $FreeBSD$

PORTNAME=	liblzma
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}source/p/pyliblzma/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYDISTUTILS_PKGNAME}-${PORTVERSION}

MAINTAINER=	naylor.b.david@gmail.com
COMMENT=	Python binding for the LZMA compression library

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config

USE_BZIP2=	yes
USE_PYTHON=	2.6+
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	py${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
LIB_DEPENDS+=	lzma.0:${PORTSDIR}/archivers/xz
.endif

.include <bsd.port.post.mk>
