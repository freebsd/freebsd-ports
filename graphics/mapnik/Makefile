# New ports collection makefile for:	mapnik
# Date created:		Nov 10, 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mapnik
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	graphics geography
MASTER_SITES=	${MASTER_SITE_BERLIOS}/${PORTNAME}/

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Free Toolkit For Developing Mapping Applications

LIB_DEPENDS=	geos:${PORTSDIR}/graphics/geos \
		proj:${PORTSDIR}/graphics/proj \
		ltdl:${PORTSDIR}/devel/libltdl15 \
		png:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		cairo.2:${PORTSDIR}/graphics/cairo \
		iconv:${PORTSDIR}/converters/libiconv
BUILD_DEPENDS=	${LOCALBASE}/bin/freetype-config:${PORTSDIR}/print/freetype2 \
		${PYTHON_PKGNAMEPREFIX}icu>=0.8.1:${PORTSDIR}/devel/py-icu \
		${PYTHON_PKGNAMEPREFIX}cairo>=1.8.2:${PORTSDIR}/graphics/py-cairo \
		${LOCALBASE}/include/cairomm-1.0/cairomm/cairomm.h:${PORTSDIR}/graphics/cairomm \
		${LOCALBASE}/include/boost/python.hpp:${PORTSDIR}/devel/boost-python-libs

USE_PGSQL=	yes
USE_BZIP2=	yes
NO_BUILD=	yes
USE_PYTHON=	2.4+
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} scons/scons.py install

.include <bsd.port.post.mk>
