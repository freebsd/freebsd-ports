# New ports collection makefile for:	cs
# Date created:				22 May 1997
# Whom:					Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cs
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.moria.de/~michael/cs/
DIST_SUBDIR=	cs/0.5-19990925

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	cs
MAN1=		cs.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cs.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cs
	${INSTALL_DATA} ${WRKSRC}/ANNOUNCE ${PREFIX}/share/doc/cs
.endif

.include <bsd.port.mk>
