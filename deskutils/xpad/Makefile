# Created by: Guillaume Paquet <amyfoub@gmail.com>
# $FreeBSD$

PORTNAME=	xpad
PORTVERSION=	3.1
PORTREVISION=	8
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpad.net/xpad/stable/${PORTVERSION}/+download/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Virtual note-pad system for your X11 desktop

LICENSE=	GPLv3

OPTIONS_DEFINE=	NLS

CONFLICTS_INSTALL=	xpad-current-[0-9]*

USE_BZIP2=	yes
USE_XORG=	x11 sm
USE_GNOME=	gtk20 gnomehier intltool
USES=	pkgconfig gmake
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch-script:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|SUBDIRS = autopackage doc src images po|SUBDIRS = autopackage doc src images|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
