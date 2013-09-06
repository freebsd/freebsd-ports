# $FreeBSD$

PORTNAME=	lordsawar
PORTVERSION=	0.2.0
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Warlords II clone

LICENSE=	GPLv3

BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost-jam \
		${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	tar:${PORTSDIR}/devel/libtar \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		gnet-2:${PORTSDIR}/net/gnet2

USES=		gettext gmake pkgconfig
USE_GNOME=	gnomehier gtkmm24
USE_SDL=	sdl image mixer
USE_GCC=	any
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost-includedir=${LOCALBASE}/include

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
