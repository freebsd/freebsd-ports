# Created by: Jaosn Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpad
PORTVERSION=	4.4.0
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/4.4/+download/
PKGNAMESUFFIX=	-current

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Virtual note-pad system for your X11 desktop

LICENSE=	GPLv3

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

CONFLICTS_INSTALL=	xpad-[0-9]*
USE_XORG=	x11 sm
USE_GNOME=	gtk30 gnomehier intltool gtksourceview3
USES=	pkgconfig gmake tar:bzip2
INSTALLS_ICONS=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
NEED_ROOT=yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

RUN_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|SUBDIRS = autopackage doc src images po|SUBDIRS = autopackage doc src images|' \
		${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|glib/glist.h|glib.h|g' \
		${WRKSRC}/src/xpad-undo.c

.include <bsd.port.mk>
