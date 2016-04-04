# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	guiloader-c++
PORTVERSION=	2.19.0
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ binding to the GuiLoader library

BUILD_DEPENDS=	${LOCALBASE}/include/boost/format.hpp:devel/boost-libs
LIB_DEPENDS=	libguiloader.so:devel/guiloader \
		libgtkmm-2.4.so:x11-toolkits/gtkmm24

PROJECTHOST=	nothing-personal
USES=		gettext libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-hidden-visibility
USE_LDCONFIG=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libguiloader-c++.so.1

.include <bsd.port.mk>
