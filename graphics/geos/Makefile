# Created by: Leonardo Martins <lmartins@nepe.eee.ufg.br>
# $FreeBSD$

PORTNAME=	geos
PORTVERSION=	3.4.2
PORTREVISION=	1
CATEGORIES=	graphics geography
MASTER_SITES=	http://download.osgeo.org/geos/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GEOS implements all the OpenGIS "Simple Features for SQL"

LICENSE=	LGPL21

USE_AUTOTOOLS=	libtool
USES=		gmake tar:bzip2
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
USE_PHP=		yes
USE_PHP_BUILD=		yes
CONFIGURE_ARGS+=	--enable-php
.endif

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=		yes
CONFIGURE_ARGS+=	--enable-ruby
CONFIGURE_ENV+=		RUBY="${RUBY}"
.endif

post-install:
	@${LN} -s ${PREFIX}/lib/libgeos-${PORTVERSION}.so \
		${STAGEDIR}${PREFIX}/lib/libgeos.so.0

.include <bsd.port.mk>
