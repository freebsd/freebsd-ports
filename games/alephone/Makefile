# New ports collection makefile for:	alephone
# Date created:		27 February 2001
# Whom:			Michael Alyn Miller <malyn@strangeGizmo.com>
#
# $FreeBSD$
#

PORTNAME=	alephone
PORTVERSION=	20100424
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/marathon/Aleph%20One/2010-04-24
DISTNAME=	AlephOne-${PORTVERSION}

MAINTAINER=	fiziologus@gmail.com
COMMENT=	The open source version of Bungie's Marathon game

LIB_DEPENDS=	speex.1:${PORTSDIR}/audio/speex
BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:${PORTSDIR}/devel/boost-libs \
		${LOCALBASE}/include/zzip/lib.h:${PORTSDIR}/devel/zziplib

USE_BZIP2=	yes
USE_GL=		yes
USE_LUA=	5.1
USE_SDL=	image ttf net sdl sound
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LUA_INCDIR}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${LUA_LIBDIR}"

DATADIR=	${PREFIX}/share/AlephOne

MAN6=		alephone.6

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README ${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.html ${DOCSDIR}
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
