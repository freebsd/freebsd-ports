PORTNAME=	clipit
PORTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	SF/gtkclipit/Version%201

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Lightweight GTK+ clipboard manager forked from parcellite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		gettext gmake gnome pkgconfig
USE_GNOME=	gtk20 intltool

OPTIONS_DEFINE=	NLS XDOTOOL
XDOTOOL_DESC=	Automatic paste functionality
OPTIONS_SUB=	yes

NLS_CONFIGURE_ON=	localedir=${LOCALBASE}/share/locale
NLS_CONFIGURE_OFF=	--disable-nls
XDOTOOL_RUN_DEPENDS+=	xdotool:x11/xdotool

post-patch:
	@${REINPLACE_CMD} -e 's|^itlocaledir =.*|itlocaledir = $$(datarootdir)/locale|' \
	${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
