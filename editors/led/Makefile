# New ports collection makefile for:	led
# Date created:				6 June 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	led
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}-editor

MAINTAINER=	fracture@allusion.net

GNU_CONFIGURE=	yes

MAN1=		led.1
MANCOMPRESSED=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

post-install:
	${MKDIR} ${PREFIX}/share/led
	${INSTALL_DATA} ${WRKSRC}/sample.ledrc ${PREFIX}/share/led/dot.ledrc
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message > \
		${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
