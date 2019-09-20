# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	rottdc
DISTVERSION=	1.0-2
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/sdl-dc/${PORTNAME}/1.0-2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apogee's Rise Of The Triad source port

USES=		compiler:c11 gmake tar:bzip2
USE_SDL=	sdl mixer
PATCH_WRKSRC=	${WRKSRC}/rott
# Crashes when compiling with -O2 or greater, so downgrade to -O1.
CFLAGS:=	${CFLAGS:C/-O[2-9]/-O1/}

OPTIONS_DEFINE=	DOCS

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

do-install:
.for f in rott rott-sw
	${INSTALL_PROGRAM} ${WRKSRC}/${f}/rott ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/rott && ${INSTALL_DATA} cheats.txt cmdline.txt \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
