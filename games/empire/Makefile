# New ports collection makefile for:	empire
# Date created:				13 May 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	empire
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	http://www.tuxedo.org/~esr/vms-empire/
DISTNAME=	vms-empire-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

MAN6=		empire.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vms-empire ${PREFIX}/bin/empire
	${INSTALL_MAN} ${WRKSRC}/vms-empire.6 ${MANPREFIX}/man/man6/empire.6
.if !defined(NOPORTDOCS)
.for file in BUGS READ.ME
	@${MKDIR} ${PREFIX}/share/doc/empire
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/empire
.endfor
.endif

.include <bsd.port.mk>
