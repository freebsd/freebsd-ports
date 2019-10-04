# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	wmpuzzle
PORTVERSION=	0.5.2
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://people.debian.org/~godisch/wmpuzzle/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Dockable puzzle game for WindowMaker and AfterStep

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		gmake localbase:ldflags xorg
USE_XORG=	x11 xext xpm
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	bin/wmpuzzle man/man6/wmpuzzle.6.gz

CPPFLAGS+=	-DBSD

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmpuzzle ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmpuzzle.6 ${STAGEDIR}${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
