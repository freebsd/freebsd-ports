# New ports collection makefile for:	battleball
# Date created:				18 December 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	battleball
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://freebsd.aeternal.net/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D single/multiplayer military soccer game for X Window System

USE_GL=		glu gl
USE_XORG=	xmu xi
WRKSRC=		${WRKDIR}/battleball-2.1-src
CFLAGS+=	-Wno-deprecated ${PTHREAD_CFLAGS}
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"	\
		XLIBS="-L${LOCALBASE}/lib -lX11"		\
		LIBS="-lm ${XLIBS} ${PTHREAD_LIBS}"	\
		GLINCS="-I${LOCALBASE}/include"		\
		GLLIBS="-lXi -lXmu -lXext -L${LOCALBASE}/lib -lGL"

PLIST_FILES=	bin/battleball
.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGELOG README
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64 or sparc64
.endif

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/battleball ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
