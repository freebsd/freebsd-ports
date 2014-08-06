# Created by: roland.jesse@gmx.net
# $FreeBSD$

PORTNAME=	Coin
PORTVERSION=	3.1.3
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	https://bitbucket.org/Coin3D/coin/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ 3D graphics library based on the Open Inventor 2.1 API

LICENSE=	BSD

LIB_DEPENDS=	libsimage.so:${PORTSDIR}/graphics/simage

USE_GCC=	any
USES=		openal:al libtool
USE_GL=		yes
USE_XORG=	xt x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pthread=yes --enable-threadsafe	\
		--enable-3ds-import --enable-sound	\
		--enable-javascript-api --enable-debug=no
USE_LDCONFIG=	yes
MAKE_ENV=	LANG=C

post-patch:
	@${REINPLACE_CMD} -e 's|DATA install-data-local|DATA|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
