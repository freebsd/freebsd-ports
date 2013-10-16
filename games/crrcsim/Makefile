# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	crrcsim
PORTVERSION=	0.9.11
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	BERLIOS

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Model-airplane flight simulation program

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	libportaudio.so.2:${PORTSDIR}/audio/portaudio2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
USES=		gmake
USE_SDL=	sdl
USE_GL=		gl glu

CPPFLAGS+=	-I${LOCALBASE}/include/portaudio2 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/portaudio2 -L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="CRRCsim" \
		"Model-airplane flight simulation program" \
		"${DATADIR}/icons/crrcsim.png" \
		"crrcsim" \
		"Game;Simulation;" \
		""

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

post-patch:
	@${REINPLACE_CMD} -e '/portaudio/ s|==|=|' ${WRKSRC}/configure

.include <bsd.port.mk>
