PORTNAME=	notekit
PORTVERSION=	0.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Hierarchical markdown note-taking application
WWW=		https://github.com/blackhole89/notekit

LICENSE=	GPLv3+

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz \
		libjsoncpp.so:devel/jsoncpp

USES=		cmake compiler:c++17-lang gnome pkgconfig
USE_GNOME=	gdkpixbuf2 gtkmm30 gtksourceviewmm3
USE_GITHUB=	yes
GH_ACCOUNT=	blackhole89

PORTSCOUT=	skipv:latest,latest-deb

post-patch:
	@${REINPLACE_CMD} -e '/workaround for old jsoncpp/d' \
		${WRKSRC}/mainwindow.cpp

.include <bsd.port.mk>
