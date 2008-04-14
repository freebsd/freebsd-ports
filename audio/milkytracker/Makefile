# New ports collection makefile for:	milkytracker
# Date created:				13 Mar 2008
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	milkytracker
PORTVERSION=	0.90.80
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.milkytracker.net/files/ \
		CRITICAL
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}/${PORTREVISION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A free music creation tool inspired by Fast Tracker 2

LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_SDL=	sdl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--disable-alsatest

PLIST_FILES=	bin/milkytracker share/pixmaps/milkytracker.ico \
		share/pixmaps/milkytracker.png
PORTDOCS=	FAQ.html MilkyTracker.html ChangeLog.html
ICONS=		carton.ico carton.png

post-install:
.for f in ${ICONS}
	${INSTALL_DATA} ${WRKSRC}/resources/pictures/${f} \
		${LOCALBASE}/share/pixmaps/${f:C/carton/milkytracker/}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
