# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	blue
PORTVERSION=	2.11
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/bluemoon/
DISTNAME=	bluemoon-${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Blue Moon card solitaire

LICENSE=	BSD

USE_GMAKE=	yes
ALL_TARGET=	bluemoon

PLIST_FILES=	bin/blue \
		bin/bluemoon

MAN6=		bluemoon.6
MLINKS=		bluemoon.6 blue.6

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS?=|g ; \
		 s|cc |$${CC} |g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bluemoon ${PREFIX}/bin
	@${LN} -sf bluemoon ${PREFIX}/bin/blue
	${INSTALL_MAN} ${MAN6:S|^|${WRKSRC}/|} ${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
