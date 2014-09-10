# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	nonpareil
PORTVERSION=	0.79
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://nonpareil.brouhaha.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simulator for many HP calculators

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USES=		bison pkgconfig scons
USE_GNOME=	gtk20 libxml2
USE_SDL=	sdl

PLIST_EXECS=	bin/modutil bin/nonpareil bin/uasm
PLIST_DATA=	lib/nonpareil/21.kml lib/nonpareil/21.obj \
		lib/nonpareil/21.png lib/nonpareil/25.kml \
		lib/nonpareil/25.obj lib/nonpareil/25.png \
		lib/nonpareil/32e.kml lib/nonpareil/32e.obj \
		lib/nonpareil/32e.png lib/nonpareil/33c.kml \
		lib/nonpareil/33c.obj lib/nonpareil/33c.png \
		lib/nonpareil/34c.kml lib/nonpareil/34c.obj \
		lib/nonpareil/34c.png lib/nonpareil/35.kml \
		lib/nonpareil/35.lst lib/nonpareil/35.obj \
		lib/nonpareil/35.png lib/nonpareil/37e.kml \
		lib/nonpareil/37e.obj lib/nonpareil/37e.png \
		lib/nonpareil/38c.kml lib/nonpareil/38c.obj \
		lib/nonpareil/38c.png lib/nonpareil/38e.kml \
		lib/nonpareil/38e.obj lib/nonpareil/41cv.kml \
		lib/nonpareil/41cv.mod lib/nonpareil/41cv.png \
		lib/nonpareil/41cx.kml lib/nonpareil/41cx.mod \
		lib/nonpareil/45.kml lib/nonpareil/45.lst \
		lib/nonpareil/45.obj lib/nonpareil/45.png \
		lib/nonpareil/55.kml lib/nonpareil/55.lst \
		lib/nonpareil/55.obj lib/nonpareil/55.png \
		lib/nonpareil/80.kml lib/nonpareil/80.lst \
		lib/nonpareil/80.obj lib/nonpareil/80.png \
		lib/nonpareil/82143a.mod lib/nonpareil/82182a.mod

PLIST_FILES=	${PLIST_EXECS} ${PLIST_DATA}
PLIST_DIRS=	lib/nonpareil
PORTDOCS=	CREDITS DEBUGGING README TODO

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%CFLAGS%%|${CFLAGS}| ; \
		 s|%%CC%%|${CC}|' ${WRKSRC}/src/SConscript
	@${REINPLACE_CMD} -E \
		"s|('/usr/local')|\1,PathOption.PathAccept|" ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e \
		's|<stdint.h>|<inttypes.h>|g' ${WRKSRC}/src/*.[cly]

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	-${CHOWN} ${BINOWN}:${BINGRP} ${PLIST_FILES:S|^|${STAGEDIR}${PREFIX}/|}
	-${TOUCH} ${PLIST_FILES:S|^|${STAGEDIR}${PREFIX}/|}
	-${CHMOD} ${SHAREMODE} ${PLIST_DATA:S|^|${STAGEDIR}${PREFIX}/|}
	-${CHMOD} ${BINMODE} ${PLIST_EXECS:S|^|${STAGEDIR}${PREFIX}/|}

.include <bsd.port.mk>
