# New ports collection makefile for:	alephone
# Date created:		27 February 2001
# Whom:			Michael Alyn Miller <malyn@strangeGizmo.com>
#
# $FreeBSD$
#

PORTNAME=	alephone
PORTVERSION=	20061202
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	marathon
DISTNAME=	AlephOne-${PORTVERSION}

MAINTAINER=	ray@cultofray.net
COMMENT=	The open source version of Bungie's Marathon game

BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:${PORTSDIR}/devel/boost
LIB_DEPENDS=	speex.1:${PORTSDIR}/audio/speex

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
USE_GNOME=	gnometarget
USE_LUA=	5.0
USE_SDL=	image net sdl sound
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include -I${LUA_INCDIR}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -L${LUA_LIBDIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
CXXFLAGS+=	-ftemplate-depth-30
.endif

.if ${OSVERSION} < 500000
BROKEN=		does not compile
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
