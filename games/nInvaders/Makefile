# ex:ts=8
# Ports collection makefile for:	nInvaders
# Date created:			Tue Jul 09, 2002
# Whom:				Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	nInvaders
PORTVERSION=	0.0.9
CATEGORIES=	games
MASTER_SITES=	http://dettus.dyndns.org/ninvaders/

MAINTAINER=	mich@freebsdcluster.org

USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" \
	-e "s|^CFLAGS|#CFLAGS|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
