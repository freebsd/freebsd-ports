# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	protracker
PORTVERSION=	2.3d.r${SVN_REV}
CATEGORIES=	audio
MASTER_SITES=	LOCAL/ehaupt
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-extras-1.tar.gz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Amiga ProTracker clone

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/src/COPYING.txt

USES=		localbase:ldflags sdl
USE_CSTD=	c99
USE_SDL=	sdl2

SVN_URL=	https://svn.code.sf.net/p/protracker/code/trunk
SVN_REV=	191

CFLAGS_i386+=	-msse2
LDFLAGS+=	-lSDL2 -lm

PLIST_FILES=	bin/protracker man/man1/protracker.1.gz \
		share/applications/protracker.desktop \
		share/pixmaps/protracker.png

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/src/*.c \
		${WRKSRC}/src/gfx/*.c -o ${WRKSRC}/protracker

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${MANPREFIX}/man/man1 \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}-extras-1/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-extras-1/*.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-extras-1/*.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

dist:
	svn checkout -r ${SVN_REV} ${SVN_URL} ${WRKSRC}
	${TAR} -C ${WRKDIR} -czpf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		--exclude .svn ${DISTNAME}

cklatest:
	@${ECHO_CMD} "We got: ${SVN_REV}"
	@${ECHO_CMD} -n "There is: "
	@svn info ${SVN_URL} | ${SED} -n 's|^Revision:\ \([0-9]*\)|\1|p'

.include <bsd.port.mk>
