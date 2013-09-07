# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdal
PORTVERSION=	1.10.1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://download.osgeo.org/gdal/ \
		ftp://ftp.remotesensing.org/pub/gdal/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding for GDAL

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/bin/swig2.0:${PORTSDIR}/devel/swig20
LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal

LIBTOOLFILES=	# empty
MAKE_ARGS=	USER_DEFS=-fPIC
MAKEFILE=	GNUmakefile
USE_AUTOTOOLS=	libtool
USE_RUBY=	yes
USES=		gmake
WRKSRC=		${WRKDIR}/${DISTNAME}/swig/ruby

post-patch:
	@${REINPLACE_CMD} -e '/^SWIG = swig/ s|$$|2.0|' ${WRKSRC}/../SWIGmake.base
	@${REINPLACE_CMD} -e 's|Config::CONFIG|Rb&|g' ${WRKSRC}/RubyMakefile.mk

do-configure:
	@${DO_NADA}

# include/cpl_config.h will only exist after graphics/gdal (build dependency) installed
pre-configure:
	@${SED} -e '/^GDAL_ROOT/d' ${DATADIR}/GDALmake.opt > ${WRKSRC}/../../GDALmake.opt
	@${CP} ${LOCALBASE}/include/cpl_config.h ${WRKSRC}/../../port/

.include <bsd.port.mk>
