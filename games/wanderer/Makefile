# Created by: marina@surferz.net
# $FreeBSD$

PORTNAME=	wanderer
PORTVERSION=	3.2
CATEGORIES=	games
MASTER_SITES=	http://www.e271.net/~marina/ \
		http://www.surferz.net/~marina/

MAINTAINER=	marina@surferz.net
COMMENT=	Rogue like adventure game

MAN6=		wanderer.6
WRKSRC=		${WRKDIR}/wanderer-3.2
ALL_TARGET=	all
MAKE_ENV+=	DOCSDIR="${DOCSDIR}" MKDIR="${MKDIR}" CHOWN="${CHOWN}" \
		CHGRP="${CHGRP}" CHMOD="${CHMOD}" TOUCH="${TOUCH}"

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
