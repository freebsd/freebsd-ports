# New ports collection makefile for:	checkdns
# Date created:				9 May 2005
# Whom:					Ozkan KIRIK <ozkan@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	checkdns
PORTVERSION=	0.5
CATEGORIES=	dns
MASTER_SITES=	http://www.enderunix.org/checkdns/

MAINTAINER=	ozkan@enderunix.org
COMMENT=	A domain name server analysis and reporting tool

USE_REINPLACE=	yes

SUB_FILES=	pkg-message
PKG_MESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/main.c \
		${WRKSRC}/INSTALL ${WRKSRC}/README ${WRKSRC}/checkdns.conf-dist

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
