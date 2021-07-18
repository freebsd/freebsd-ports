PORTNAME=	flmsg
DISTVERSION=	4.0.17
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/files/${PORTNAME}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Forms management editor for Amateur Radio standard message formats

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png
RUN_DEPENDS=	fldigi:comms/fldigi

USES=		gmake jpeg pkgconfig xorg
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/flmsg \
		share/applications/flmsg.desktop \
		share/pixmaps/flmsg.xpm

.include <bsd.port.mk>
