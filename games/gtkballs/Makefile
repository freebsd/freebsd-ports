# New ports collection makefile for:	gtkballs
# Date created:				11 November 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gtkballs
PORTVERSION=	1.04
CATEGORIES=	games
MASTER_SITES=	http://gtkballs.antex.ru/dist/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=	ports@FreeBSD.org

USE_GTK=	yes

MAN6=		gtkballs.6

do-install:
	${INSTALL_PROGRAM} -m 2755 -o root -g games ${WRKSRC}/gtkballs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gtkballs.6 ${PREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/gtkballs
	${INSTALL_DATA} ${WRKSRC}/gtkballs-data/*.xpm ${PREFIX}/share/gtkballs
	${INSTALL_DATA} ${WRKSRC}/score ${PREFIX}/share/gtkballs/score
	@${CHMOD} g+rw ${PREFIX}/share/gtkballs/score
	@${CHOWN} root:games ${PREFIX}/share/gtkballs/score
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gtkballs
.for file in README README.russian TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gtkballs
.endfor
.endif

.include <bsd.port.mk>
