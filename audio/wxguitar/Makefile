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

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=nls

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/wxguitar|${DATADIR}|' \
		${WRKSRC}/src/wxGuitarMain.cpp ${WRKSRC}/data/wxGuitar.desktop
	@${REINPLACE_CMD} -e 's|aplay|wavplay|' \
		${WRKSRC}/src/wxGuitarMain.cpp

.include <bsd.port.mk>
