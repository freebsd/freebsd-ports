PORTNAME=	xbill
PORTVERSION=	2.1
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://www.xbill.org/download/

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Save your computers from the evil clutches of Bill
WWW=		http://www.xbill.org

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--localstatedir=${SCORES_DIR} --disable-gtk

SCORES_DIR?=	${DATADIR}/scores

DESKTOP_ENTRIES="xBill" \
		"Save your computers from the evil clutches of Bill" \
		"${DATADIR}/pixmaps/icon.xpm" \
		"xbill" \
		"Game;ArcadeGame;" \
		false

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man6/${PORTNAME}.6.gz

PORTDATA=	*

USES=		xorg
USE_XORG=	xt x11 sm ice xpm

OPTIONS_SINGLE=	WIDGETSET
OPTIONS_SINGLE_WIDGETSET=	ATHENA MOTIF
OPTIONS_DEFAULT=	ATHENA

ATHENA_DESC=	Athena widget set
MOTIF_DESC=	Motif widget set

ATHENA_CONFIGURE_ON=	--disable-motif
ATHENA_USES=	xorg
ATHENA_USE=	xorg=xaw,xmu

MOTIF_CONFIGURE_ON=	--disable-athena
MOTIF_USES=	motif

post-patch:
	@${REINPLACE_CMD} -e '/WIDGET_LIBS=/ s|-lXt|-lXt -lXpm|' \
		${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xbill

.include <bsd.port.mk>
