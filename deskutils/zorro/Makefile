# New ports collection makefile for:	zorro
# Date created:         03 Aug 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $FreeBSD$
#

PORTNAME=	zorro
PORTVERSION=	1.1.8
CATEGORIES=	deskutils tk82
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/ \
		ftp://totem.fix.no/pub/mirrors/misc/

DISTNAME=	${PORTNAME}-1.1p8

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple to-do list manager

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/zorro

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zorro ${PREFIX}/bin/zorro
	${MKDIR} ${PREFIX}/share/zorro
	${INSTALL_DATA} ${WRKSRC}/DOTzorrorc ${PREFIX}/share/zorro
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Take a look at ${PREFIX}/share/zorro/DOTzorrorc"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
