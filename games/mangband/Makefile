# New ports collection makefile for:   mangband
# Date created:        30 Dec 1998
# Whom: Adam Kranzel (adam@alameda.edu)
#
# $FreeBSD$
#

PORTNAME=	mangband
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://mangband.org/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	adam-ports@blacktabby.org
COMMENT=	Multiplayer rogue-like game with color, X11 support

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USE_XLIB=	yes
ALL_TARGET=	install

MALIB=		${PREFIX}/lib/mangband

do-install:
	${INSTALL_PROGRAM} -o root -g games -m 2550 \
		${WRKSRC}/mangband ${PREFIX}/bin
	${INSTALL_PROGRAM} -o root -g games -m 550 \
		${WRKSRC}/mangconsole ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mangclient ${PREFIX}/bin
	@${MKDIR} ${MALIB}/file
	@${TOUCH} ${MALIB}/file/wizards.txt
	cd ${WRKSRC}/../lib && ${PAX} -rw * ${MALIB}
	${CHMOD} 750 ${MALIB}/*
	${CHMOD} 755 ${MALIB}/user
	${CHOWN} -R root:games ${MALIB}/*
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${MALIB}

.include <bsd.port.mk>
