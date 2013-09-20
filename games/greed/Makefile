# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	greed
PORTVERSION=	3.8
CATEGORIES=	games
MASTER_SITES=	http://catb.org/~esr/greed/ CENKES
PKGNAMESUFFIX=	-game

MAINTAINER=	culot@FreeBSD.org
COMMENT=	A text puzzle game with the aim of clearing the game field

MAN6=		greed.6
PLIST_FILES=	bin/greed
SCOREFILE?=	/var/games/greed.hs
CFLAGS+=	-DSCOREFILE=\"${SCOREFILE}\" -DNOTBSD -DRELEASE=\"${PORTVERSION}\"
LDFLAGS+=	-lcurses

NO_STAGE=	yes
do-build:
	@cd ${WRKSRC}&&${CC} ${CFLAGS} -o greed greed.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} -m 2555 -o root -g games ${WRKSRC}/greed ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/greed.6 ${MAN6PREFIX}/man/man6/
	@a=${SCOREFILE};[ -f $$a ]||:>$$a&&${CHOWN} root:games $$a&&${CHMOD} 664 $$a
	@${ECHO_CMD} '@exec a=${SCOREFILE};[ -f $$a ]||:>$$a&&\
		${CHOWN} root:games $$a&&${CHMOD} 664 $$a' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec a=${SCOREFILE};[ -s $$a ]||${RM} -f $$a' >> ${TMPPLIST}

.include <bsd.port.mk>
