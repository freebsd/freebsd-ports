# Created by: Guillaume Paquet <amyfoub@gmail.com>
# $FreeBSD$

PORTNAME=	xpad
PORTVERSION=	3.1
PORTREVISION=	9
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpad.net/xpad/stable/${PORTVERSION}/+download/
PKGNAMESUFFIX=	3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual note-pad system for your X11 desktop

LICENSE=	GPLv3

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

CONFLICTS_INSTALL=	xpad-[0-9]*

USES=	pkgconfig gmake tar:bzip2
USE_XORG=	x11 sm ice
USE_GNOME=	gtk20 intltool cairo
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes

NLS_USES=		gettext
NLS_CPPFLAGS=		${CXXFLAGS} -I${LOCALBASE}/include
NLS_LDFLAGS=		-L${LOCALBASE}/lib
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|SUBDIRS = autopackage doc src images po|SUBDIRS = autopackage doc src images|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
