# ex:ts=8
# New ports collection makefile for:	walker
# Date created:			May 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	walker
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	http://josefsson.org/walker/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/bin/dig:${PORTSDIR}/net/bind9

USE_REINPLACE=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,`dig,`${LOCALBASE}/bin/dig,g' ${WRKSRC}/walker

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/walker ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/walker
	${INSTALL_DATA} ${WRKSRC}/walker.html ${PREFIX}/share/doc/walker
.endif

.include <bsd.port.mk>
