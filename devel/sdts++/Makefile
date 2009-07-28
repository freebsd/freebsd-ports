# New ports collection makefile for:	sdts++
# Date created:         08 Feb 2000
# Whom:                 erik@habatech.no
#
# $FreeBSD$
#

PORTNAME=	sdts++
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://thor-f5.er.usgs.gov/sdts/sdtsxx/ \
		http://lychnobite.org/sdts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for SDTS related development

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include
MAKE_ARGS=	CXX="${CXX}"

INFO=		sdts++

.include <bsd.port.mk>
