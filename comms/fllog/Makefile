PORTNAME=	fllog
DISTVERSION=	1.2.9
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/fldigi/${PORTNAME}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Ham Radio logging program
WWW=		https://www.w1hkj.org/fllog-help/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng16.so:graphics/png

USES=		desktop-file-utils gmake jpeg xorg
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"

PLIST_FILES=	bin/fllog \
		share/applications/fllog.desktop \
		share/pixmaps/fllog.xpm

.include <bsd.port.mk>
