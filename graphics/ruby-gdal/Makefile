# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdal
PORTVERSION=	1.9.2
CATEGORIES=	graphics ruby
MASTER_SITES=	http://download.osgeo.org/gdal/ \
		ftp://ftp.remotesensing.org/pub/gdal/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding for GDAL

BUILD_DEPENDS=	${LOCALBASE}/bin/swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	gdal:${PORTSDIR}/graphics/gdal

LIBTOOLFILES=	# empty
MAKE_ARGS=	USER_DEFS=-fPIC
MAKEFILE=	GNUmakefile
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_RUBY=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/swig/ruby

post-patch:
	@${REINPLACE_CMD} -e 's|Config::CONFIG|Rb&|' ${WRKSRC}/RubyMakefile.mk

do-configure:
	@${DO_NADA}

pre-build:
	${SED} -e '/^GDAL_ROOT/d' ${DATADIR}/GDALmake.opt > ${WRKSRC}/../../GDALmake.opt
	${CP} ${LOCALBASE}/include/cpl_config.h ${WRKSRC}/../../port/

.include <bsd.port.mk>
