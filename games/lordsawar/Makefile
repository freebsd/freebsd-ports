# $FreeBSD$

PORTNAME=	lordsawar
PORTVERSION=	0.1.9
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Warlords II clone

LICENSE=	GPLv3

LIB_DEPENDS=	glademm-2:${PORTSDIR}/devel/libglademm24 \
		gnet-2:${PORTSDIR}/net/gnet2 \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		tar:${PORTSDIR}/devel/libtar
BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost-jam \
		${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

USES=		gettext
USE_GMAKE=	yes
USE_GNOME=	intltool
USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS+=--disable-nls \
		--with-boost-includedir=${LOCALBASE}/include/

CONFIGURE_ENV+=	LIBS="${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
