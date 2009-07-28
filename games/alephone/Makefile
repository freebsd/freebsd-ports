# New ports collection makefile for:	alephone
# Date created:		27 February 2001
# Whom:			Michael Alyn Miller <malyn@strangeGizmo.com>
#
# $FreeBSD$
#

PORTNAME=	alephone
PORTVERSION=	20080913
CATEGORIES=	games
MASTER_SITES=	SF/marathon
DISTNAME=	AlephOne-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	The open source version of Bungie's Marathon game

BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	speex.1:${PORTSDIR}/audio/speex

USE_BZIP2=	yes
USE_GL=		yes
USE_GNOME=	gnometarget
USE_LUA=	5.1
USE_SDL=	image net sdl sound
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LUA_INCDIR}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${LUA_LIBDIR}"

DATADIR=	${PREFIX}/share/AlephOne

MAN6=		alephone.6

PORTDOCS=	*

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README docs/* ${DOCSDIR}
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
