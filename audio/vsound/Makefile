# New ports collection makefile for:   linux-vsound
# Date created:        13 June 2002
# Whom:                Rahul Siddharthan <rsidd@online.fr>
#
# $FreeBSD$
#

PORTNAME=	vsound
PORTVERSION=	0.5
CATEGORIES=	audio
MASTER_SITES=	http://rsidd.online.fr/

MAINTAINER=	rsidd@online.fr

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox

USE_LIBTOOL=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
