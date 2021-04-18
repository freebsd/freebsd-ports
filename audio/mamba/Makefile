PORTNAME=	mamba
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Virtual MIDI keyboard

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xxd:editors/vim-console
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfluidsynth.so:audio/fluidsynth \
		libjack.so:audio/jack \
		liblo.so:audio/liblo \
		libsmf.so:audio/libsmf

USES=		compiler:c++11-lang desktop-file-utils gmake gnome pkgconfig xorg
USE_GNOME=	cairo glib20 libsigc++20
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	Mamba
GH_TUPLE=	brummer10:libxputty:5c69824:libxputty/libxputty

PLIST_FILES=	bin/mamba \
		share/applications/Mamba.desktop \
		share/pixmaps/Mamba.svg

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mamba

.include <bsd.port.mk>
