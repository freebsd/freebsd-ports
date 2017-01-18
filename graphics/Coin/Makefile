# Created by: roland.jesse@gmx.net
# $FreeBSD$

PORTNAME=	Coin
PORTVERSION=	3.1.3
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	https://bitbucket.org/Coin3D/coin/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ 3D graphics library based on the Open Inventor 2.1 API

LICENSE=	GPLv2

LIB_DEPENDS=	libsimage.so:graphics/simage

USES=		openal:al libtool pathfix
USE_GL=		yes
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
	${REINPLACE_CMD} -e '/^ldflags=/s|-R|-Wl,-rpath,|' \
		${WRKSRC}/coin-default.cfg

.include <bsd.port.mk>
