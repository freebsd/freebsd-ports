PORTNAME=	wxguitar
PORTVERSION=	1.01
PORTREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple guitar tuning assistant

RUN_DEPENDS=	wavplay:audio/wavplay

USES=		compiler:c++11-lib
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes
USE_WX=		3.0
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}

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
