PORTNAME=	wanderer
DISTVERSION=	3.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.e271.net/~marina/ \
		http://www.steveshipway.org/software/wanderer/

MAINTAINER=	catskillmarina@gmail.com
COMMENT=	Rogue like adventure game
WWW=		https://www.steveshipway.org/software/wanderer/f_wanderer.html

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
		 s|man/man6|share/man/man6| ; \
		 s|/usr/local|$${PREFIX}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
