# Created by: Jaosn Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpad
PORTVERSION=	4.4.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/4.4/+download/
PKGNAMESUFFIX=	-current

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Virtual note-pad system for your X11 desktop

LICENSE=	GPLv3

RUN_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

CONFLICTS_INSTALL=	xpad-[0-9]*
USE_XORG=	x11 sm
USE_GNOME=	gtk30 intltool gtksourceview3
USES=	pkgconfig gmake tar:bzip2 autoreconf
INSTALLS_ICONS=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|glib/glist.h|glib.h|g' \
		${WRKSRC}/src/xpad-undo.c

.include <bsd.port.mk>
