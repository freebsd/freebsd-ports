# New ports collection makefile for:	geos
# Date created:		19 December 2003
# Whom:		 	Leonardo Martins <lmartins@nepe.eee.ufg.br>
#
# $FreeBSD$
#

PORTNAME=	geos
PORTVERSION=	3.3.1
CATEGORIES=	graphics geography
MASTER_SITES=	http://download.osgeo.org/geos/

MAINTAINER=	konstantin@saurbier.net
COMMENT=	GEOS implements all the OpenGIS "Simple Features for SQL"

LICENSE=	LGPL21

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

OPTIONS=	PYTHON "Enable python bindings" off \
		PHP    "Enable php bindings" off \
		RUBY   "Enable ruby bindings" off

.include <bsd.port.options.mk>

.if defined(WITH_PHP) || defined(WITH_PYTHON) || defined(WITH_RUBY)
BUILD_DEPENDS+=	swig1.3:${PORTSDIR}/devel/swig13
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=		yes
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=		WITH_PYTHON=""
.else
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if defined(WITH_PHP)
BUILD_DEPENDS+=		${LOCALBASE}/bin/php-config:${PORTSDIR}/lang/php5
CONFIGURE_ARGS+=	--enable-php
PLIST_SUB+=		WITH_PHP=""
.else
PLIST_SUB+=		WITH_PHP="@comment "
.endif

.if defined(WITH_RUBY)
USE_RUBY=		yes
CONFIGURE_ARGS+=	--enable-ruby
CONFIGURE_ENV+=		RUBY="${RUBY}"
PLIST_SUB+=		WITH_RUBY=""
.else
PLIST_SUB+=		WITH_RUBY="@comment "
.endif

post-install:
		@${LN} -s ${PREFIX}/lib/libgeos-${PORTVERSION}.so ${PREFIX}/lib/libgeos.so.0

.include <bsd.port.mk>
