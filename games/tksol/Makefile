# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tksol
PORTVERSION=	1.8.4
PORTREVISION=	2
CATEGORIES=	games tk
MASTER_SITES=	SUNSITE/games/solitaires

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Version of the card game solitaire

LICENSE=	GPLv2

RUN_DEPENDS=	wish8.4:x11-toolkits/tk84

USES=		shebangfix tar:tgz
SHEBANG_FILES=	pictures/generate_mini_pictures
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#/bin/sh|#!/bin/sh| ; \
		 s|/usr/local/lib/tksol|${DATADIR}| ; \
		 s|wish|wish8.4|' ${WRKSRC}/tksol

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tksol ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tksol.6 ${STAGEDIR}${MANPREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.xbm ${STAGEDIR}${DATADIR}
.for dir in cardbacks cards pictures
	${TAR} -C ${WRKSRC} --exclude ".xvpics" -cf - ${dir} | \
		${TAR} -C ${STAGEDIR}${DATADIR} --unlink -xf -
.endfor

.include <bsd.port.mk>
