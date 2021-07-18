PORTNAME=	flamp
DISTVERSION=	2.2.05
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/fldigi/flamp/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program for the Amateur Multicast Protocol

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png
RUN_DEPENDS=	fldigi:comms/fldigi

USES=		compiler:c++11-lang gmake jpeg pkgconfig xorg
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/flamp \
		share/applications/flamp.desktop \
		share/pixmaps/flamp.xpm

.include <bsd.port.mk>
