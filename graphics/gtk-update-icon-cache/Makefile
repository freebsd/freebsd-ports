# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/gtk-update-icon-cache/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gtk-update-icon-cache
PORTVERSION=	2.24.22
CATEGORIES=	graphics
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gtk-update-icon-cache utility from the Gtk+ toolkit

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS+=	${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info \
		${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_XZ=		yes
USES=		gettext gmake pathfix perl5 pkgconfig
USE_PERL5=	build
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	atk pango gdkpixbuf2 introspection:build ltverhack
USE_XORG=	xext xrender x11 xinerama xi xrandr xcursor xfixes xdamage \
		xcomposite
PATCHDIR=	${.CURDIR}/../../x11-toolkits/gtk20/files
CONFIGURE_ARGS=	--enable-static --with-xinput=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
BUILD_WRKSRC=	${WRKSRC}/gtk
ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/gtk-update-icon-cache \
		man/man1/gtk-update-icon-cache.1.gz

.include <bsd.port.pre.mk>

pre-configure:
.if !exists(${LOCALBASE}/libdata/pkgconfig/cairo-xlib.pc)
	@${ECHO_CMD} "${PKGNAME}: Needs cairo with X11 support enabled."
	@${FALSE}
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gtk/gtk-update-icon-cache \
		${STAGEDIR}${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/docs/reference/gtk/gtk-update-icon-cache.1 \
		${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.post.mk>
