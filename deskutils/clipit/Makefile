PORTNAME=	clipit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.5
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Lightweight GTK clipboard manager forked from parcellite
WWW=		https://github.com/CristianHenzel/ClipIt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gettext gmake gnome pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	CristianHenzel
GH_PROJECT=	ClipIt
USE_GNOME=	gtk30 intltool
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk3

OPTIONS_DEFINE=	NLS XDOTOOL
OPTIONS_SUB=	yes

XDOTOOL_DESC=	Automatic paste functionality

NLS_CONFIGURE_ON=	localedir=${LOCALBASE}/share/locale
NLS_CONFIGURE_OFF=	--disable-nls
XDOTOOL_RUN_DEPENDS+=	xdotool:x11/xdotool

.include <bsd.port.mk>
