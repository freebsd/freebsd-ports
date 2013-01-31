# Created by: erik@habatech.no
# $FreeBSD$

PORTNAME=	sdts++
PORTVERSION=	1.5.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://thor-f5.er.usgs.gov/sdts/sdtsxx/ \
		http://lychnobite.org/sdts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for SDTS related development

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs

USE_DOS2UNIX=	sdts++/io/sio_Utils.cpp
USE_BISON=	build
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtoolize aclocal automake autoconf
LIBTOOLIZE_ARGS=--copy --force
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing --copy --foreign
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

INFO=		sdts++

.include <bsd.port.mk>
