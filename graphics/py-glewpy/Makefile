# New ports collection makefile for:	py-glewpy
# Date created:		2006-09-26
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glewpy
PORTVERSION=	0.7.4
PORTREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python
PATCH_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|amdmi3|}
PATCHFILES=	glewpy-${PORTVERSION}-generatedsources.diff.bz2

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Advanced OpenGL extensions to Python

BUILD_DEPENDS=	pyrex>=0.9.6.2:${PORTSDIR}/devel/pyrex

USE_GL=		glew
USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
