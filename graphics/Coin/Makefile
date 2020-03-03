# Created by: roland.jesse@gmx.net
# $FreeBSD$

PORTNAME=	Coin
PORTVERSION=	4.0.0
DISTVERSIONPREFIX=	Coin-
CATEGORIES=	graphics

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	C++ 3D graphics library based on the Open Inventor API

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libsimage.so:graphics/simage

USES=		gl openal:al libtool pathfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	coin3d
GH_PROJECT=	coin

USE_GL=		gl
USE_XORG=	ice sm x11 xext xt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pthread=yes --enable-threadsafe	\
		--enable-3ds-import --enable-sound	\
		--enable-javascript-api --enable-debug=no
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

pre-configure:
	@${REINPLACE_CMD} -e 's|DATA install-data-local|DATA|g' \
		${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} \( -name \*.cpp -o -name \*.h -a \! \
		-name expat.h \) -a -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} 's/<stdlib.h>/<cstdlib>/g'

post-build:
	@${REINPLACE_CMD} -e '/^ldflags=/s|-R|-Wl,-rpath,|' \
		${WRKSRC}/coin-default.cfg

.include <bsd.port.mk>
