PORTNAME=	xlennart
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XBill Modification
WWW=		https://github.com/Xylemon/xlennart

LICENSE=	GPLv2

USES=		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	Xylemon

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--localstatedir=${SCORES_DIR}

DESKTOP_ENTRIES="xLennart" \
		"Save your computers from the evil clutches of Lennart" \
		"${DATADIR}/pixmaps/icon.xpm" \
		"xlennart" \
		"Game;ArcadeGame;" \
		false

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man6/${PORTNAME}.6.gz
PORTDATA=	*

OPTIONS_DEFAULT=		GTK
OPTIONS_SINGLE=			WIDGETSET
OPTIONS_SINGLE_WIDGETSET=	ATHENA GTK MOTIF

ATHENA_DESC=	Athena widget set
GTK_DESC=	GTK widget set
MOTIF_DESC=	Motif widget set

ATHENA_USES=		xorg
ATHENA_USE=		XORG=xaw,xmu,xt,x11,sm,ice
ATHENA_CONFIGURE_ON=	--disable-gtk --disable-motif

MOTIF_USES=		motif xorg
MOTIF_USE=		XORG=xt,x11,sm,ice,xpm
MOTIF_CONFIGURE_ON=	--disable-athena --disable-gtk

GTK_USES=		gnome xorg
GTK_USE=		GNOME=gtk20 XORG=sm,ice
GTK_CONFIGURE_ON=	--disable-athena --disable-motif

SCORES_DIR?=	${DATADIR}/scores

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e '/WIDGET_LIBS=/ s|-lXm"$$|-lXm -lXpm"|' \
		${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xlennart

.include <bsd.port.mk>
