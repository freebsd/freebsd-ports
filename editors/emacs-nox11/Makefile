# Created by: phoffman@proper.com
# $FreeBSD$

PKGNAMESUFFIX=	-nox11

PORTREVISION=	13

OPTIONS_EXCLUDE=GCONF GIF JPEG OTF M17N PNG SVG TIFF SYNC_INPUT GTK2 GTK3 \
		SCROLLBARS XFT XIM XPM MAGICK GSETTINGS X11 CANNA \
		XAW XAW3D MOTIF

EMACS_NO_X11_SLAVE=	yes
PLIST_DIRSTRY=	share/icons/hicolor/128x128/apps \
		share/icons/hicolor/128x128 \
		share/icons/hicolor/16x16/apps \
		share/icons/hicolor/16x16 \
		share/icons/hicolor/24x24/apps \
		share/icons/hicolor/24x24 \
		share/icons/hicolor/32x32/apps \
		share/icons/hicolor/32x32 \
		share/icons/hicolor/48x48/apps \
		share/icons/hicolor/48x48 \
		share/icons/hicolor/scalable/apps \
		share/icons/hicolor/scalable/mimetypes \
		share/icons/hicolor/scalable \
		share/icons/hicolor \
		share/icons

MASTERDIR=	${.CURDIR}/../emacs
LATEST_LINK=	emacs-nox11

.include "${MASTERDIR}/Makefile"
