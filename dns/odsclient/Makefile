# New ports collection makefile for:   odsclient
# Date created:         Jul 22, 2001
# Whom:                 geniusj@ods.org
#
# $FreeBSD$
#

PORTNAME=	odsclient
PORTVERSION=	1.02
CATEGORIES=	dns
MASTER_SITES=	http://www.ods.org/

MAINTAINER=	geniusj@ods.org
COMMENT=	ODS Dynamic DNS Client

USE_REINPLACE=	yes
ALL_TARGET=	odsclient

post-patch:
	@${REINPLACE_CMD} -e "s/^(CC|CFLAGS).+//g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/odsclient ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
