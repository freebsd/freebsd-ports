PORTNAME=	xroar
DISTVERSION=	1.12.1
CATEGORIES=	emulators
MASTER_SITES=	https://www.6809.org.uk/xroar/dl/
MAINTAINER=	juhani@krekela.fi

COMMENT=	MC6809-based Dragon and Colour Computer (CoCo) emulator
WWW=		https://www.6809.org.uk/xroar/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

LIB_DEPENDS=	libpng16.so:graphics/png \
		libSDL3.so:devel/sdl3 \
		libsndfile.so:audio/libsndfile

USES=		gettext-runtime gl gmake gnome pkgconfig xorg
USE_GL+=	gl
USE_GNOME+=	gtk30
USE_XORG+=	ice sm x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-evdev \
			--without-gtk2 \
			--without-jack \
			--without-pulse \
			--without-sdl2

INFO=		xroar
PLIST_FILES=	bin/xroar \
		share/man/man1/xroar.1.gz

.include <bsd.port.mk>
