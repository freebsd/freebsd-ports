# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	numptyphysics
DISTVERSION=	0.3.r20090104
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		ftp://ftp.openbsd.org/pub/OpenBSD/distfiles/ \
		ftp://ftp3.usa.openbsd.org/pub/OpenBSD/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Drawing physics-based puzzle game

USES=		tar:bzip2 desktop-file-utils
GNU_CONFIGURE=	yes
USE_SDL=	sdl image
INSTALLS_ICONS=	yes

CONFIGURE_ENV=	AUTOMAKE="${TRUE}" ACLOCAL="${TRUE}" MISSING="${TRUE}"
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-I${LOCALBASE}/include -DINSTALL_BASE_PATH=\"\\\"${DATADIR}\\\"\"

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	MOREFPS
OPTIONS_DEFAULT=MOREFPS
MOREFPS_DESC=	Smoother graphics support

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MMOREFPS}
	@${REINPLACE_CMD} -e '/define RENDER_RATE/ s|20|60|' \
		${WRKSRC}/Config.h
.endif
	@${CHMOD} a+x ${WRKSRC}/install-sh
	@${REINPLACE_CMD} -e 's|\(desktopentrydir=\).*|\1${PREFIX}/share/applications|' \
		${WRKSRC}/configure ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|^Exec=.*|Exec=${PORTNAME}|; /^X-Icon-Path/ d' \
		${WRKSRC}/data/${PORTNAME}.desktop

post-build:
	${STRIP_CMD} ${WRKSRC}/${PORTNAME}

.include <bsd.port.mk>
