# Created by: asami
# $FreeBSD$

PORTNAME=	xbill
PORTVERSION=	2.1
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://www.xbill.org/download/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Save your computers from the evil clutches of Bill

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${SCORES_DIR}

SCORES_DIR?=	${DATADIR}/scores

DESKTOP_ENTRIES="xBill" \
		"Save your computers from the evil clutches of Bill" \
		"${DATADIR}/pixmaps/icon.xpm" \
		"xbill" \
		"Game;ArcadeGame;" \
		false

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz

PORTDATA=	*

OPTIONS_SINGLE=	WIDGETSET
OPTIONS_SINGLE_WIDGETSET=	ATHENA GTK MOTIF
OPTIONS_DEFAULT=	GTK

ATHENA_DESC=	Athena widget set
GTK_DESC=	GTK widget set
MOTIF_DESC=	Motif widget set

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATHENA}
CONFIGURE_ARGS+=	--disable-gtk --disable-motif
USE_XORG=	xaw xmu xt x11 sm ice
.elif ${PORT_OPTIONS:MMOTIF}
CONFIGURE_ARGS+=	--disable-athena --disable-gtk
USE_XORG=	xt x11 sm ice xpm
USES=		motif
.else # ${PORT_OPTIONS:MGTK}
CONFIGURE_ARGS+=	--disable-athena --disable-motif
USE_GNOME=	gtk12
USE_XORG=	sm ice
.endif

post-patch:
	@${REINPLACE_CMD} -e '/WIDGET_LIBS=/ s|-lXm"$$|-lXm -lXpm"|' \
		${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xbill

.include <bsd.port.mk>
