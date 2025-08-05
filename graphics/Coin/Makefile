PORTNAME=	Coin
PORTVERSION=	4.0.5
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	C++ 3D graphics library based on the Open Inventor API
WWW=		https://github.com/coin3d

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libsimage.so:graphics/simage

USES=		cmake gl openal:al libtool pathfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	coin3d
GH_PROJECT=	coin

USE_GL=		gl glu
USE_XORG=	ice sm x11 xext xt
CMAKE_ARGS+=	-DCOIN_BUILD_SHARED_LIBS="ON" \
		-DCOIN_THREADSAFE="ON" \
		-DCOIN_HAVE_JAVASCRIPT="ON" \
		-DHAVE_SOUND="ON" \
		-DHAVE_3DS_IMPORT_CAPABILITIES="ON" \
		-DUSE_EXTERNAL_EXPAT="ON"
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

pre-configure:
	@${REINPLACE_CMD} -e 's|DATA install-data-local|DATA|g' \
		${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} \( -name \*.cpp -o -name \*.h -a \! \
		-name expat.h \) -a -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} 's/<stdlib.h>/<cstdlib>/g'

.include <bsd.port.mk>
