# Created by: Guillaume Paquet <amyfoub@gmail.com>
# $FreeBSD$

PORTNAME=	xpad
PORTVERSION=	3.1
PORTREVISION=	9
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpad.net/xpad/stable/${PORTVERSION}/+download/
PKGNAMESUFFIX=	3

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Virtual note-pad system for your X11 desktop

LICENSE=	GPLv3

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=	pkgconfig gmake tar:bzip2 xorg gnome

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

CONFLICTS_INSTALL=	xpad-[0-9]*

USE_XORG=	x11 sm ice
USE_GNOME=	gtk20 intltool cairo
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes

NLS_USES=		gettext
NLS_CPPFLAGS=		${CXXFLAGS} -I${LOCALBASE}/include
NLS_LDFLAGS=		-L${LOCALBASE}/lib
NLS_CONFIGURE_ENABLE=	nls
NLS_PLIST_FILES=	\
share/locale/af/LC_MESSAGES/xpad.mo \
share/locale/bg/LC_MESSAGES/xpad.mo \
share/locale/cs/LC_MESSAGES/xpad.mo \
share/locale/da/LC_MESSAGES/xpad.mo \
share/locale/en_GB/LC_MESSAGES/xpad.mo \
share/locale/es/LC_MESSAGES/xpad.mo \
share/locale/fi/LC_MESSAGES/xpad.mo \
share/locale/fr/LC_MESSAGES/xpad.mo \
share/locale/ga/LC_MESSAGES/xpad.mo \
share/locale/hu/LC_MESSAGES/xpad.mo \
share/locale/it/LC_MESSAGES/xpad.mo \
share/locale/ja/LC_MESSAGES/xpad.mo \
share/locale/ko/LC_MESSAGES/xpad.mo \
share/locale/lv/LC_MESSAGES/xpad.mo \
share/locale/nl/LC_MESSAGES/xpad.mo \
share/locale/ro/LC_MESSAGES/xpad.mo \
share/locale/ru/LC_MESSAGES/xpad.mo \
share/locale/rw/LC_MESSAGES/xpad.mo \
share/locale/sv/LC_MESSAGES/xpad.mo \
share/locale/vi/LC_MESSAGES/xpad.mo \
share/locale/zh_CN/LC_MESSAGES/xpad.mo \
share/locale/zh_TW/LC_MESSAGES/xpad.mo

PLIST_FILES=	\
bin/xpad \
man/man1/xpad.1.gz \
share/applications/xpad.desktop \
share/icons/hicolor/scalable/apps/xpad.svg

.include <bsd.port.options.mk>

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|SUBDIRS = autopackage doc src images po|SUBDIRS = autopackage doc src images|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
