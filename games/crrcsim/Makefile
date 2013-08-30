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
LIB_DEPENDS=	portaudio.2:${PORTSDIR}/audio/portaudio2 \
		jpeg:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GL=		gl glu

CPPFLAGS+=	-I${LOCALBASE}/include/portaudio2 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/portaudio2 -L${LOCALBASE}/lib

PORTDOCS=	*

MAN1=		crrcsim.1

DESKTOP_ENTRIES="CRRCsim" \
		"Model-airplane flight simulation program" \
		"${DATADIR}/icons/crrcsim.png" \
		"crrcsim" \
		"Game;Simulation;" \
		false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/portaudio/ s|==|=|' ${WRKSRC}/configure
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-pkgdataDATA||; \
		/^SUBDIRS =/ s|=.*|= man|' ${WRKSRC}/documentation/Makefile.in
.endif

.include <bsd.port.mk>
