# $FreeBSD$

PORTNAME=	clipit
PORTVERSION=	1.4.2
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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
CONFIGURE_ARGS+=	--localedir=${LOCALBASE}/share/locale
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MXDOTOOL}
RUN_DEPENDS+=	xdotool:${PORTSDIR}/x11/xdotool
.endif

MAN1=	clipit.1

post-patch-script:
	@${REINPLACE_CMD} -e 's|^itlocaledir =.*|itlocaledir = $$(datarootdir)/locale|' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
