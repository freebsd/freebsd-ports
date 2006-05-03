# New ports collection makefile for:	alephone
# Date created:		27 February 2001
# Whom:			Michael Alyn Miller <malyn@strangeGizmo.com>
#
# $FreeBSD$
#

PORTNAME=	alephone
PORTVERSION=	20051119
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	marathon
DISTNAME=	AlephOne-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The open source version of Bungie's Marathon game

BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:${PORTSDIR}/devel/boost
LIB_DEPENDS=	speex.3:${PORTSDIR}/audio/speex \
		lua.5:${PORTSDIR}/lang/lua50

USE_X_PREFIX=	yes
USE_GNOME=	gnometarget
USE_SDL=	image net sdl sound
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
		
CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
CXXFLAGS+=	-ftemplate-depth-30
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|<SDL/SDL|<SDL|g' \
		${WRKSRC}/Source_Files/Misc/thread_priority_sdl_posix.cpp
.if ${OSVERSION} < 500035
	@${REINPLACE_CMD} -e 's|streambuf>|streambuf\.h>|' \
		${WRKSRC}/Source_Files/CSeries/snprintf.h
	@${REINPLACE_CMD} -e 's|m_buffer\.clear()|m_buffer.resize(0)|g ; \
		 s|m_displayBuffer\.clear()|m_displayBuffer.resize(0)|g' \
		${WRKSRC}/Source_Files/Misc/Console.cpp
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
