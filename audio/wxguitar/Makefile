# New ports collection makefile for:	wxguitar
# Date created:		19 Aug 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wxguitar
PORTVERSION=	1.01
PORTREVISION=	3
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
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/wxGuitar

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
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
