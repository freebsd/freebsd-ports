# New ports collection makefile for:	crrcsim
# Date created:		17 Jun 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	crrcsim
PORTVERSION=	0.9.10
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	BERLIOS

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Model-airplane flight simulation program

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	portaudio.2:${PORTSDIR}/audio/portaudio2 \
		jpeg.10:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GL=		gl glu
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib/portaudio2 -L${LOCALBASE}/lib"\
		CPPFLAGS="-I${LOCALBASE}/include/portaudio2 -I${LOCALBASE}/include"

PORTDOCS=	*

MAN1=		crrcsim.1

DESKTOP_ENTRIES="CRRCsim" \
		"Model-airplane flight simulation program" \
		"${DATADIR}/icons/crrcsim.png" \
		"crrcsim" \
		"Game;Simulation;" \
		false

post-patch:
	@${REINPLACE_CMD} -e '/portaudio/ s|==|=|' ${WRKSRC}/configure
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-pkgdataDATA||; \
		/^SUBDIRS =/ s|=.*|= man|' ${WRKSRC}/documentation/Makefile.in
.endif

.include <bsd.port.mk>
