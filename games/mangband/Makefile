# New ports collection makefile for:   mangband
# Date created:        30 Dec 1998
#
# $FreeBSD$
#

PORTNAME=	mangband
PORTVERSION=	0.7.0
CATEGORIES=	games
MASTER_SITES=	http://mangband.org/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org

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
	cd ${WRKSRC}/../lib && pax -rw * ${MALIB}
	${CHMOD} 750 ${MALIB}/*
	${CHMOD} 755 ${MALIB}/user
	${CHOWN} -R root.games ${MALIB}/*
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${MALIB}

.include <bsd.port.mk>
