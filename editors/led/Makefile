# New ports collection makefile for:	led
# Date created:				6 June 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	led
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}-editor

MAINTAINER=	fracture@allusion.net

GNU_CONFIGURE=	yes

MAN1=		led.1
MANCOMPRESSED=	yes

.if !defined(NOPORTDOCS)
PKGMESSAGE=	${WRKDIR}/pkg-message
.else
PKGMESSAGE=	/nonexistant
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.ledrc ${DOCSDIR}
	@${SED} 's|%%DOCSDIR%%|${DOCSDIR}|g' ${PKGDIR}/pkg-message > \
		${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
