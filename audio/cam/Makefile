# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME=	cam
PORTVERSION=	1.02
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/mixers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cpu's Audio Mixer [curses based]

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses tar:tgz

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		LIBS="${LDFLAGS} -lncurses" \
		BINDIR="${PREFIX}/bin" \
		MANDIR="${PREFIX}/share/man/man1" \
		XEFILE=""

PLIST_FILES=	bin/cam \
		share/man/man1/cam.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cam ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cam.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
