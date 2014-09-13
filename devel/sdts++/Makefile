# Created by: erik@habatech.no
# $FreeBSD$

PORTNAME=	sdts++
PORTVERSION=	1.5.1
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://thor-f5.er.usgs.gov/sdts/sdtsxx/ \
		http://lychnobite.org/sdts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for SDTS related development

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs

DOS2UNIX_FILES=	sdts++/io/sio_Utils.cpp
USES=		bison dos2unix gmake libtool makeinfo
USE_AUTOTOOLS=	libtoolize aclocal automake autoconf
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing --copy --foreign
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

INFO=		sdts++

.include <bsd.port.mk>
