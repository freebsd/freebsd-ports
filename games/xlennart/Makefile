# $FreeBSD$

PORTNAME=	xlennart
PORTVERSION=	1.1.1
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XBill Modification

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${SCORES_DIR}

SCORES_DIR?=	${DATADIR}/scores

DESKTOP_ENTRIES="xLennart" \
		"Save your computers from the evil clutches of Lennart" \
		"${DATADIR}/pixmaps/icon.xpm" \
		"xlennart" \
		"Game;ArcadeGame;" \
		false

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz

PORTDATA=	*

OPTIONS_SINGLE=			WIDGETSET
OPTIONS_SINGLE_WIDGETSET=	ATHENA GTK MOTIF
OPTIONS_DEFAULT=		GTK

ATHENA_DESC=	Athena widget set
GTK_DESC=	GTK widget set
MOTIF_DESC=	Motif widget set

USE_GITHUB=	yes
GH_ACCOUNT=	Xylemon

USES=		pkgconfig

ATHENA_CONFIGURE_ON=	--disable-gtk --disable-motif
ATHENA_USES=		xorg
ATHENA_USE=		XORG=xaw,xmu,xt,x11,sm,ice

MOTIF_CONFIGURE_ON=	--disable-athena --disable-gtk
MOTIF_USE=		XORG=xt,x11,sm,ice,xpm
MOTIF_USES=		motif xorg

GTK_USES=		gnome xorg
GTK_CONFIGURE_ON=	--disable-athena --disable-motif
GTK_USE=		GNOME=gtk20 XORG=sm,ice

post-patch:
	@${REINPLACE_CMD} -e '/WIDGET_LIBS=/ s|-lXm"$$|-lXm -lXpm"|' \
		${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xlennart

.include <bsd.port.mk>
