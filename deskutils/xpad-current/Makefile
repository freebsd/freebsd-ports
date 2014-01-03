# Created by: Jaosn Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpad
PORTVERSION=	4.1
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
PKGNAMESUFFIX=	-current

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Virtual note-pad system for your X11 desktop

LICENSE=	GPLv3

OPTIONS_DEFINE=	NLS

CONFLICTS_INSTALL=	xpad-[0-9]*
USE_BZIP2=	yes
USE_XORG=	x11 sm
USE_GNOME=	gtk20 gnomehier intltool
USES=	pkgconfig gmake
INSTALLS_ICONS=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

#code currently doesn't properly handle --disable-nls (in next upstream milestone)
.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch-script:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|SUBDIRS = autopackage doc src images po|SUBDIRS = autopackage doc src images|' \
		${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|glib/glist.h|glib.h|g' \
		${WRKSRC}/src/xpad-undo.c

.include <bsd.port.mk>
