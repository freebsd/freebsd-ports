# New ports collection makefile for:	wmpuzzle
# Date created:			15 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmpuzzle
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://www.godisch.de/debian/wmpuzzle/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockable puzzle game for WindowMaker and AfterStep

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_XORG=	xpm
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN6=		wmpuzzle.6
PLIST_FILES=	bin/wmpuzzle

CPPFLAGS=	-I${LOCALBASE}/include -DBSD
LDFLAGS=	-L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmpuzzle ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmpuzzle.6 ${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
