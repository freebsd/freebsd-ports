PORTNAME=	gimmage
PORTVERSION=	0.2.3
PORTREVISION=	19
CATEGORIES=	graphics
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple image viewer
WWW=		https://sourceforge.net/projects/gimmage.berlios/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Last release in 2007, depends on legacy libraries such as GTK2. Consider using graphics/geeqie or graphics/imv
EXPIRATION_DATE=2024-02-29

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang desktop-file-utils gettext gnome pkgconfig
USE_GNOME=	gtkmm24 gdkpixbuf2
GNU_CONFIGURE=	yes
USE_CXXSTD=	c++11

OPTIONS_DEFINE=		NLS
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	gettext

CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}

.include <bsd.port.pre.mk>

.if ! ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-Wc++11-extensions -Wc++11-long-long \
		-Wunused-command-line-argument -Wreturn-type \
		-Wwritable-strings -Wlogical-op-parentheses
.endif

.include <bsd.port.post.mk>
