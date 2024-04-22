PORTNAME=	plotutils
PORTVERSION=	2.6
PORTREVISION=	10
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GNU

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Plotting library and toolkit
WWW=		https://www.gnu.org/software/plotutils/plotutils.html

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake libtool localbase:ldflags xorg	# parallel builds are broken with bmake(1)
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xaw xext xmu xt

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-libplotter --enable-libxmi

TEST_TARGET=	check

INFO=		libxmi plotutils

.include <bsd.port.mk>
