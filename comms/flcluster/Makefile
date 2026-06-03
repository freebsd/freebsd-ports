PORTNAME=	flcluster
DISTVERSION=	1.1.01
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/fldigi/${PORTNAME}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Management tool for accessing dxcluster nodes
WWW=		https://www.w1hkj.org/flcluster-help/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng16.so:graphics/png

USES=		autoreconf compiler:c++11-lib gmake jpeg pkgconfig xorg
USE_CXXSTD=	gnu++0x
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	EXTRA_LIBS="-lexecinfo" \
		FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"

PLIST_FILES=	bin/flcluster \
		share/applications/flcluster.desktop \
		share/pixmaps/flcluster.xpm

.include <bsd.port.mk>
