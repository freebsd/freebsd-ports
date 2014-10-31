# $FreeBSD$

PORTNAME=	lordsawar
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Warlords II clone

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost-jam \
		${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libtar.so:${PORTSDIR}/devel/libtar \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libgnet-2.0.so:${PORTSDIR}/net/gnet2

USES=		gettext gmake pkgconfig
USE_GNOME=	gnomehier gtkmm24
USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost-includedir=${LOCALBASE}/include

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDATA=	*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
