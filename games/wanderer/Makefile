# Created by: marina@surferz.net
# $FreeBSD$

PORTNAME=	wanderer
PORTVERSION=	3.2
CATEGORIES=	games
MASTER_SITES=	http://www.e271.net/~marina/ \
		http://www.steveshipway.org/software/wanderer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rogue like adventure game

LICENSE=	GPLv2+

USES=		ncurses
MAKE_ENV=	MKDIR="${MKDIR}"
CFLAGS+=	-Wno-return-type

post-patch:
	@${REINPLACE_CMD} -e \
		's|-o root -g games|| ; \
		 s|install -m 0755 -d|$${MKDIR}| ; \
		 s|install -m 0644|$${BSD_INSTALL_DATA}| ; \
		 s|install -m 2755|$${BSD_INSTALL_PROGRAM}| ; \
		 s|/usr/local|$${PREFIX}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
