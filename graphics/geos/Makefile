# Created by: Leonardo Martins <lmartins@nepe.eee.ufg.br>
# $FreeBSD$

PORTNAME=	geos
PORTVERSION=	3.8.1
CATEGORIES=	graphics geography
MASTER_SITES=	https://download.osgeo.org/geos/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geometry Engine, Open Source

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	RUBY
OPTIONS_SUB=	yes

USES=		compiler:c++11-lang gmake libtool tar:bzip2

CONFIGURE_ARGS=	ac_cv_path_SWIG=${LOCALBASE}/bin/swig3.0
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

RUBY_BUILD_DEPENDS=	swig3.0:devel/swig30
RUBY_CONFIGURE_ENABLE=	ruby
RUBY_CONFIGURE_ENV=	RUBY="${RUBY}"
RUBY_USE=		RUBY=yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++||' ${WRKSRC}/tests/geostest/Makefile.in ${WRKSRC}/tests/thread/Makefile.in

post-configure:
	@${FIND} ${WRKSRC} -name Makefile -exec ${REINPLACE_CMD} -e '/CXXFLAGS = / s| -O2||' {} +

.include <bsd.port.mk>
