# Created by: minter@lunenburg.org
# $FreeBSD$

PORTNAME=	tornado
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	https://kiza.eu/media/software/tornado/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ccurses-based game of weather destruction

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake ncurses

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

post-patch:
.for i in Makefile Makefile.inc
	@${REINPLACE_CMD} -e \
		'/^CC/s| =| ?=| ; \
		 /^MAKE/s| =| ?=| ; \
		 /^LDFLAGS/s| =| +=| ; \
		 /^PREFIX/s| =| ?=| ; \
		 /^LOCALEPATH/s|/usr/local|$$(PREFIX)| ; \
		 /^CFLAGS/s| =| +=| ; \
		 s|-O2||' ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e \
		's|/usr/local|PREFIX|' ${WRKSRC}/doc/man/tornado.6.in
.for i in de fr it nl no ru
	@${REINPLACE_CMD} -e \
		's|/usr/local|PREFIX|' ${WRKSRC}/doc/man/${i}/tornado.6.${i}.in
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tornado \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man/tornado.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6
.for i in de fr it nl no ru
	@${MKDIR} ${STAGEDIR}${MAN6PREFIX}/man/${i}/man6
	${INSTALL_MAN} ${WRKSRC}/doc/man/${i}/tornado.6 \
		${STAGEDIR}${MAN6PREFIX}/man/${i}/man6
.endfor
.for i in de es fr it nl no pt ru
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${i}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES/tornado.mo
.endfor
	@${MKDIR} ${STAGEDIR}/var/games
	${INSTALL_DATA} ${WRKSRC}/tornado.scores \
		${STAGEDIR}/var/games/tornado.scores.sample

.include <bsd.port.mk>
