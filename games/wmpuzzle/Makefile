# New ports collection makefile for:	wmpuzzle
# Date created:			15 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmpuzzle
PORTVERSION=	0.5.1
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://people.debian.org/~godisch/wmpuzzle/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockable puzzle game for WindowMaker and AfterStep

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_XORG=	xpm
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN6=		wmpuzzle.6
PLIST_FILES=	bin/wmpuzzle

CPPFLAGS+=	-I${LOCALBASE}/include -DBSD
LDFLAGS+=	-L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmpuzzle ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmpuzzle.6 ${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
