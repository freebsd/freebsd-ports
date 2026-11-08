PORTNAME=	mamba
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6
CATEGORIES=	audio
MASTER_SITES=	https://github.com/brummer10/Mamba/releases/download/v${DISTVERSION}/
DISTFILES=	Mamba_${DISTVERSION}.tar.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Virtual MIDI keyboard
WWW=		https://github.com/brummer10/Mamba

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xxd:editors/vim
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfluidsynth.so:audio/fluidsynth \
		libjack.so:audio/jack \
		liblo.so:audio/liblo \
		libsmf.so:audio/libsmf

USES=		compiler:c++11-lang desktop-file-utils gmake gnome pkgconfig xorg
USE_GNOME=	cairo glib20 libsigc++20
USE_XORG=	x11

WRKSRC=		${WRKDIR}/Mamba_${DISTVERSION}

# libxputty does not recognize FreeBSD via uname -s
MAKE_ARGS=	TARGET=Linux

PLIST_FILES=	bin/mamba \
		share/applications/Mamba.desktop \
		share/pixmaps/Mamba.svg

post-patch:
	# libxputty selects its X11 code path via __linux__; avoid defining that macro
	@${FIND} ${WRKSRC}/libxputty/xputty -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e 's/__linux__/__FreeBSD__/g'

pre-build:
	${DO_MAKE_BUILD} -C ${WRKSRC}/libxputty

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mamba

.include <bsd.port.mk>
