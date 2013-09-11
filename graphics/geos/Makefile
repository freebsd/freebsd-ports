# Created by: Leonardo Martins <lmartins@nepe.eee.ufg.br>
# $FreeBSD$

PORTNAME=	geos
PORTVERSION=	3.4.1
CATEGORIES=	graphics geography
MASTER_SITES=	http://download.osgeo.org/geos/

MAINTAINER=	konstantin@saurbier.net
COMMENT=	GEOS implements all the OpenGIS "Simple Features for SQL"

LICENSE=	LGPL21

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		gmake
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	PHP PYTHON RUBY

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPHP} || ${PORT_OPTIONS:MPYTHON} || ${PORT_OPTIONS:MRUBY}
BUILD_DEPENDS+=	swig1.3:${PORTSDIR}/devel/swig13
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=		yes
CONFIGURE_ARGS+=	--enable-python
.endif

.if ${PORT_OPTIONS:MPHP}
BUILD_DEPENDS+=		${LOCALBASE}/bin/php-config:${PORTSDIR}/lang/php5
CONFIGURE_ARGS+=	--enable-php
.endif

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=		yes
CONFIGURE_ARGS+=	--enable-ruby
CONFIGURE_ENV+=		RUBY="${RUBY}"
.endif

post-install:
	@${LN} -s ${PREFIX}/lib/libgeos-${PORTVERSION}.so ${PREFIX}/lib/libgeos.so.0

.include <bsd.port.mk>
