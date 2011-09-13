# New ports collection makefile for:	geos
# Date created:		19 December 2003
# Whom:		 	Leonardo Martins <lmartins@nepe.eee.ufg.br>
#
# $FreeBSD$
#

PORTNAME=	geos
PORTVERSION=	3.3.0
PORTREVISION=	2
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

OPTIONS=	PYTHON "Enable python bindings" off

.include <bsd.port.options.mk>

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
BUILD_DEPENDS+=	swig:${PORTSDIR}/devel/swig13
PKGNAMESUFFIX=	-python
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

post-install:
		@${LN} -s ${PREFIX}/lib/libgeos-${PORTVERSION}.so ${PREFIX}/lib/libgeos.so.0

.include <bsd.port.mk>
