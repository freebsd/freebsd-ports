PORTNAME=	flcluster
PORTVERSION=	1.0.4
PORTREVISION=	3
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/fldigi/${PORTNAME}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Management tool for accessing dxcluster nodes

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:graphics/png \
		libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig

USES=		autoreconf compiler:c++11-lib gmake pkgconfig xorg
USE_CXXSTD=	gnu++0x
GNU_CONFIGURE=	yes
USE_XORG=	x11 xft xext xfixes xcursor xinerama
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config" \
		    EXTRA_LIBS="-lexecinfo"

PLIST_FILES=	bin/flcluster share/applications/flcluster.desktop \
			share/pixmaps/flcluster.xpm
.include <bsd.port.mk>
