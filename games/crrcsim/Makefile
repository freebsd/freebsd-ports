# New ports collection makefile for:	crrcsim
# Date created:		17 Jun 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	crrcsim
PORTVERSION=	0.9.9
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Model-airplane flight simulation program

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GL=		gl glu

PORTDOCS=	*

OPTIONS=	PORTAUDIO19 "Use portaudio19 instead of portaudio18" off

.include <bsd.port.pre.mk>

.if defined(WITH_PORTAUDIO19)
LIB_DEPENDS+=	portaudio.2:${PORTSDIR}/audio/portaudio2
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib/portaudio2 -L${LOCALBASE}/lib"\
	       	CPPFLAGS="-I${LOCALBASE}/include/portaudio2 -I${LOCALBASE}/include"
.else
LIB_DEPENDS+=	portaudio.0:${PORTSDIR}/audio/portaudio
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
.endif

post-patch:
	@${REINPLACE_CMD} -e '/portaudio/ s|==|=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local/share/games|${PREFIX}/share|' \
		${WRKSRC}/config.cpp
	@cd ${WRKSRC} && ${FIND} . -name Makefile.in -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|share/games|share|; \
		s|$$(datadir)/games|$$(datadir)|'
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/SUBDIRS/ s|documentation||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
