# ex:ts=8
# Ports collection makefile for:	axelq
# Date created:			Oct 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	axelq
PORTVERSION=	0.70
CATEGORIES=	ftp
MASTER_SITES=	http://elektron.its.tudelft.nl/~hemmin98/axelq_releases/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A queue manager for the download accelerator axel

RUN_DEPENDS=	axel:${PORTSDIR}/ftp/axel \
		bash:${PORTSDIR}/shells/bash2

USE_REINPLACE=	yes
NO_BUILD=	yes

MAN1=	axelq.1

post-patch:
	@${REINPLACE_CMD} -e "s|/bin/sh|${LOCALBASE}/bin/bash|g" ${WRKSRC}/axelq
	@${CAT} ${FILESDIR}/axelq.rc | ${SED} -e "s|%%PREFIX%%|${PREFIX}|" >> \
		${WRKSRC}/axelq.rc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/axelq ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/axelq.rc ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/axelq.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
