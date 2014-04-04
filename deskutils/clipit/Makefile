# $FreeBSD$

PORTNAME=	clipit
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/gtkclipit/Version%201

MAINTAINER=	jrm@ftfl.ca
COMMENT=	Lightweight GTK+ clipboard manager forked from parcellite

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		gmake pkgconfig
USE_GNOME=	gtk20

OPTIONS_DEFINE=	NLS XDOTOOL
XDOTOOL_DESC=	Automatic paste functionality
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ON=	localedir=${LOCALBASE}/share/locale
NLS_CONFIGURE_OFF=	--disable-nls
XDOTOOL_RUN_DEPENDS+=	xdotool:${PORTSDIR}/x11/xdotool

post-patch:
	@${REINPLACE_CMD} -e 's|^itlocaledir =.*|itlocaledir = $$(datarootdir)/locale|' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
