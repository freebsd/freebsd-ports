# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	milkytracker
PORTVERSION=	0.90.85
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.milkytracker.org/files/ \
		CRITICAL/${PORTNAME}/${PORTVERSION}/${PORTREVISION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A free music creation tool inspired by Fast Tracker 2

LICENSE=	GPLv3

LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack \
		zzip:${PORTSDIR}/devel/zziplib

GNU_CONFIGURE=	yes
USE_SDL=	sdl
MAKE_JOBS_SAFE=	yes
USE_PKGCONFIG=	build

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=	--disable-alsatest --without-alsa

PLIST_FILES=	bin/milkytracker share/pixmaps/milkytracker.ico \
		share/pixmaps/milkytracker.png
PORTDOCS=	FAQ.html MilkyTracker.html ChangeLog.html
ICONS=		carton.ico carton.png

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.for f in ${ICONS}
	${INSTALL_DATA} ${WRKSRC}/resources/pictures/${f} \
		${LOCALBASE}/share/pixmaps/${f:C/carton/milkytracker/}
.endfor

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc: fails in assembler
.endif

.include <bsd.port.mk>
