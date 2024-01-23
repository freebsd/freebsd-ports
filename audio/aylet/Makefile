PORTNAME=	aylet
DISTVERSION=	0.5
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://www.worldofspectrum.org/pub/sinclair/music/players-unix/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Aylet plays music files in the .ay format
WWW=		https://www.worldofspectrum.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext-runtime pkgconfig

ALL_TARGET=	aylet

PLIST_FILES=	%%GUI%%bin/xaylet \
		bin/aylet \
		share/man/man1/aylet.1.gz

OPTIONS_DEFINE=		GUI
OPTIONS_DEFAULT=	GUI
OPTIONS_SUB=		yes

GUI_USES=	gnome
GUI_USE=	GNOME=atk,cairo,gdkpixbuf2,glib20,gtk20,pango

GUI_ALL_TARGET=	xaylet

.include <bsd.port.mk>
