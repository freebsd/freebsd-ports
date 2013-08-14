# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wxguitar
PORTVERSION=	1.01
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A simple guitar tuning assistant

RUN_DEPENDS=	wavplay:${PORTSDIR}/audio/wavplay

GNU_CONFIGURE=	yes
USE_WX=		2.8+
WX_UNICODE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/wxGuitar

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/wxguitar|${DATADIR}|' \
		${WRKSRC}/src/wxGuitarMain.cpp ${WRKSRC}/data/wxGuitar.desktop
	@${REINPLACE_CMD} -e 's|aplay|wavplay|' \
		${WRKSRC}/src/wxGuitarMain.cpp

.include <bsd.port.mk>
