# New ports collection makefile for:	gtkballs
# Version required:			1.04
# Date created:				11 November 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	gtkballs-1.04
CATEGORIES=	games
MASTER_SITES=	ftp://lucifer.dorms.spbu.ru/pub/Linux/games/ \
		http://lucifer.dorms.spbu.ru/gtkballs/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
MAN6=		gtkballs.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtkballs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gtkballs.6 ${PREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/gtkballs
	${INSTALL_DATA} ${WRKSRC}/gtkballs-data/*.xpm ${PREFIX}/share/gtkballs
	${INSTALL_DATA} ${WRKSRC}/score ${PREFIX}/share/gtkballs/score
	@${CHMOD} a+rw ${PREFIX}/share/gtkballs/score
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gtkballs
.for file in README README.russian TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gtkballs
.endfor
.endif

.include <bsd.port.mk>
