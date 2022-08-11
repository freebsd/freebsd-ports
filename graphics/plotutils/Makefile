PORTNAME=	plotutils
PORTVERSION=	2.6
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GNU

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Plotting library and toolkit

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake libtool xorg	# parallel builds are broken with bmake(1)
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-libplotter --enable-libxmi
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xaw xext xmu xt
TEST_TARGET=	check

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		libxmi plotutils

.include <bsd.port.mk>
