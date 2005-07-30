# New ports collection makefile for:	battleball
# Date created:				18 December 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	battleball
PORTVERSION=	2.1
CATEGORIES=	games
MASTER_SITES=	http://home.austin.rr.com/pah/
DISTNAME=	${PORTNAME}.${PORTVERSION:S/.//}.src

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-08-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D single/multiplayer military soccer game for X Window System

USE_X_PREFIX=	yes
USE_GL=		yes
WRKSRC=		${WRKDIR}/battleball-2.1-src
CFLAGS+=	-Wno-deprecated ${PTHREAD_CFLAGS}
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"	\
		XLIBS="-L${X11BASE}/lib -lX11"		\
		LIBS="-lm ${XLIBS} ${PTHREAD_LIBS}"	\
		GLINCS="-I${X11BASE}/include"		\
		GLLIBS="-lXi -lXmu -lXext -L${X11BASE}/lib -lGL"

PLIST_FILES=	bin/battleball
.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGELOG README
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		"Does not compile on ia64 or sparc64"
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
