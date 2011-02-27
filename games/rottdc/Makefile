# New ports collection makefile for:	rottdc
# Date created:				18 Feb 2004
# Whom:					Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	rottdc
DISTVERSION=	1.0-2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/sdl-dc/${PORTNAME}/1.0-2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apogee's Rise Of The Triad source port

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer
PATCH_WRKSRC=	${WRKSRC}/rott
# Crashes when compiling with -O2 or greater, so downgrade to -O1.
CFLAGS:=	${CFLAGS:C/-O[2-9]/-O1/}

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

do-install:
.for f in rott rott-sw
	${INSTALL_PROGRAM} ${WRKSRC}/${f}/rott ${PREFIX}/bin/${f}
.endfor
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.for i in cheats cmdline
	${INSTALL_DATA} ${WRKSRC}/rott/${i}.txt ${DOCSDIR}
.endfor
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
