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

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs

DOS2UNIX_FILES=	sdts++/io/sio_Utils.cpp
USES=		bison dos2unix gmake
USE_AUTOTOOLS=	libtoolize aclocal automake autoconf
LIBTOOLIZE_ARGS=--copy --force
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing --copy --foreign
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include
USE_LDCONFIG=	yes

INFO=		sdts++

NO_STAGE=	yes
.include <bsd.port.mk>
