# New ports collection makefile for:	mapnik
# Date created:		Nov 10, 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mapnik
PORTVERSION=	0.7.1
CATEGORIES=	graphics geography
MASTER_SITES=	${MASTER_SITE_BERLIOS}/${PORTNAME}/

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Free Toolkit For Developing Mapping Applications

LIB_DEPENDS=	proj:${PORTSDIR}/graphics/proj \
		png:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg \
		icuuc:${PORTSDIR}/devel/icu \
		boost_system:${PORTSDIR}/devel/boost-libs
BUILD_DEPENDS=	${LOCALBASE}/bin/freetype-config:${PORTSDIR}/print/freetype2 \
		icu>=4.1.4:${PORTSDIR}/devel/icu \
		${PYTHON_PKGNAMEPREFIX}icu>=0.8.1:${PORTSDIR}/devel/py-icu \
		boost-libs>1.41:${PORTSDIR}/devel/boost-libs \
		${LOCALBASE}/include/boost/python.hpp:${PORTSDIR}/devel/boost-python-libs

LICENSE=	LGPL21
LICENSE_FILE=   ${WRKSRC}/COPYING

USE_PGSQL=	yes
USE_BZIP2=	yes
USE_PYTHON=	2.5+
USE_LDCONFIG=	yes
USE_SCONS=	yes
USE_AUTOTOOLS=	libltdl
USE_GNOME=	pkgconfig libxml2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS=	CAIRO "Enable cairo rendering" on

.include <bsd.port.options.mk>

.if defined(WITHOUT_CAIRO)
SCONS_ARGS+=	CAIRO=False
.else
LIB_DEPENDS+=	cairo.2:${PORTSDIR}/graphics/cairo \
   		cairomm-1.0:${PORTSDIR}/graphics/cairomm
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cairo>=1.8.2:${PORTSDIR}/graphics/py-cairo
.endif

.include <bsd.port.pre.mk>

.if defined (MAKE_JOBS_NUMBER)
SCONS_ARGS+=     JOBS=${MAKE_JOBS_NUMBER}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		${WRKSRC}/SConstruct

do-install:
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${SCONS_BUILDENV} ${SCONS_BIN} \
	    ${SCONS_INSTALL_TARGET}

.include <bsd.port.post.mk>
