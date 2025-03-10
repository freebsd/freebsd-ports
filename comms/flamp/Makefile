PORTNAME=	flamp
DISTVERSION=	2.2.14
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/files/flamp/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program for the Amateur Multicast Protocol
WWW=		http://www.w1hkj.com/ \
		https://sourceforge.net/projects/fldigi/

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
