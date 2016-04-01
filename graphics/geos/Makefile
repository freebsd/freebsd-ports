# Created by: Leonardo Martins <lmartins@nepe.eee.ufg.br>
# $FreeBSD$

PORTNAME=	geos
PORTVERSION=	3.5.0
CATEGORIES=	graphics geography
MASTER_SITES=	http://download.osgeo.org/geos/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GEOS implements all the OpenGIS "Simple Features for SQL"

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	PHP PYTHON RUBY
OPTIONS_SUB=	yes

CONFIGURE_ARGS=	ac_cv_path_SWIG=${LOCALBASE}/bin/swig3.0
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		gmake libtool tar:bzip2

PLIST_SUB=	PORTVERSION=${PORTVERSION}

PHP_BUILD_DEPENDS=	swig3.0:devel/swig30
PHP_CONFIGURE_ENABLE=	php
PHP_USE=		PHP=yes PHP_BUILD=yes
PYTHON_BUILD_DEPENDS=	swig3.0:devel/swig30
PYTHON_CONFIGURE_ENABLE=python
PYTHON_USES=		python:2
RUBY_BUILD_DEPENDS=	swig3.0:devel/swig30
RUBY_CONFIGURE_ENABLE=	ruby
RUBY_CONFIGURE_ENV=	RUBY="${RUBY}"
RUBY_USE=		RUBY=yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++||' ${WRKSRC}/tests/geostest/Makefile.in ${WRKSRC}/tests/thread/Makefile.in

.include <bsd.port.mk>
