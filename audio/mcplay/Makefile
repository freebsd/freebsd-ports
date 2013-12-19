# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	mcplay
DISTVERSION=	0.3i
CATEGORIES=	audio
MASTER_SITES=	http://www.yahuxo.de/${PORTNAME}/ \
		http://www.sourcefiles.org/Multimedia/MP3/Front_End/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses based front-end to various audio players

LICENSE=	GPLv2

USES=		ncurses
USE_GNOME=	glib12

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

post-patch:
.for i in mcplay.c screen.c
	@${REINPLACE_CMD} -e \
		's|<sys/termios.h>|<termios.h>|' ${WRKSRC}/${i}
.endfor

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${FILESDIR} && ${INSTALL_MAN} ${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1)

.include <bsd.port.mk>
