PORTNAME=	gxmessage
PORTVERSION=	3.4.3
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	GNU \
		LOCAL/martymac

MAINTAINER=	avg@FreeBSD.org
COMMENT=	GTK3 substitute for xmessage
WWW=		http://homepages.ihug.co.nz/~trmusson/programs.html #gxmessage

USE_GNOME=	gtk30 gnomeprefix intltool
USES=		gmake gnome pkgconfig
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

MAKE_ARGS+=	INSTALL="${INSTALL_PROGRAM}"

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

INFO=		${PORTNAME}

.include <bsd.port.mk>
