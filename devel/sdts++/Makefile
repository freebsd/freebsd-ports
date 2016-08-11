# Created by: erik@habatech.no
# $FreeBSD$

PORTNAME=	sdts++
PORTVERSION=	1.5.1
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://thor-f5.er.usgs.gov/sdts/sdtsxx/ \
		http://lychnobite.org/sdts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for SDTS related development

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

DOS2UNIX_GLOB=	*.cpp
USES=		autoreconf bison dos2unix gmake libtool makeinfo
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

INFO=		sdts++

post-patch:
.for f in AUTHORS ChangeLog NEWS README
	@${TOUCH} ${WRKSRC}/sysutils/${f}
.endfor

.include <bsd.port.mk>
