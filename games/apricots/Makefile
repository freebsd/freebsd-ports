# New ports collection makefile for:	apricots
# Date created:		07 Jan 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	apricots
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.fishies.org.uk/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fly a little plane around and shoot things and drop bombs

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"

PORTDOCS=	README

DESKTOP_ENTRIES="Apricots" \
		"Fly a little plane around and shoot things and drop bombs" \
		"" \
		"apricots" \
		"Game;ArcadeGame;" \
		false

OPTIONS=	OPENAL	"Enable OpenAL audio" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OPENAL)
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut
.endif

post-patch:
.if defined(WITHOUT_OPENAL)
	@${REINPLACE_CMD} -e 's|-DAP_AUDIO_OPENAL||' ${WRKSRC}/configure
.else
	@${REINPLACE_CMD} -e '/^LIBS = / s|$$| -lopenal -lalut|' \
		${WRKSRC}/apricots/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
