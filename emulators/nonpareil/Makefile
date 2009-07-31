# New ports collection makefile for:   nonpareil
# Date created:                        24 Jul 2006
# Whom:                                trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	nonpareil
PORTVERSION=	0.78
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	http://nonpareil.brouhaha.com/download/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Simulator for many HP calculators

BUILD_DEPENDS=	pnmtopng:${PORTSDIR}/graphics/netpbm

USE_BISON=	build
USE_SCONS=	yes
USE_GNOME=	gtk20 libxml2
USE_SDL=	mixer

SCONS_ARGS+=	prefix="${PREFIX}"

PLIST_EXECS=	bin/uasm bin/nonpareil bin/modutil
PLIST_DATA=	lib/nonpareil/21.obj lib/nonpareil/25.obj \
		lib/nonpareil/32e.obj lib/nonpareil/33c.obj \
		lib/nonpareil/34c.obj lib/nonpareil/37e.obj \
		lib/nonpareil/38c.obj lib/nonpareil/38e.obj \
		lib/nonpareil/41cv.mod lib/nonpareil/41cx.mod \
		lib/nonpareil/82143a.mod lib/nonpareil/82182a.mod \
		lib/nonpareil/11c.obj lib/nonpareil/12c.obj \
		lib/nonpareil/15c.obj lib/nonpareil/16c.obj \
		lib/nonpareil/35.kml lib/nonpareil/45.kml \
		lib/nonpareil/55.kml lib/nonpareil/80.kml \
		lib/nonpareil/21.kml lib/nonpareil/25.kml \
		lib/nonpareil/32e.kml lib/nonpareil/33c.kml \
		lib/nonpareil/34c.kml lib/nonpareil/37e.kml \
		lib/nonpareil/38c.kml lib/nonpareil/38e.kml \
		lib/nonpareil/41cv.kml lib/nonpareil/41cx.kml \
		lib/nonpareil/11c.kml lib/nonpareil/12c.kml \
		lib/nonpareil/15c.kml lib/nonpareil/16c.kml \
		lib/nonpareil/35.png lib/nonpareil/45.png \
		lib/nonpareil/55.png lib/nonpareil/80.png \
		lib/nonpareil/21.png lib/nonpareil/25.png \
		lib/nonpareil/32e.png lib/nonpareil/33c.png \
		lib/nonpareil/34c.png lib/nonpareil/37e.png \
		lib/nonpareil/38c.png lib/nonpareil/41cv.png \
		lib/nonpareil/11c.png lib/nonpareil/12c.png \
		lib/nonpareil/15c.png lib/nonpareil/16c.png \
		lib/nonpareil/35.obj lib/nonpareil/35.lst \
		lib/nonpareil/45.obj lib/nonpareil/45.lst \
		lib/nonpareil/55.obj lib/nonpareil/55.lst \
		lib/nonpareil/80.obj lib/nonpareil/80.lst

PLIST_FILES=	${PLIST_EXECS} ${PLIST_DATA}
PLIST_DIRS=	lib/nonpareil
PORTDOCS=	CREDITS DEBUGGING README TODO

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,%%CFLAGS%%,${CFLAGS},' \
			  -e 's,%%CC%%,${CC},' \
		${WRKSRC}/src/SConscript
	@${REINPLACE_CMD} -E "s|('/usr/local')|\1,PathOption.PathAccept|" \
		${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's,<stdint.h>,<inttypes.h>,g' \
		${WRKSRC}/src/*.[cly]

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	${CHOWN} 0:0 ${PLIST_FILES:S|^|${PREFIX}/|}
	${TOUCH} ${PLIST_FILES:S|^|${PREFIX}/|}
	${CHMOD} 644 ${PLIST_DATA:S|^|${PREFIX}/|}
	${CHMOD} 755 ${PLIST_EXECS:S|^|${PREFIX}/|}

.include <bsd.port.post.mk>
