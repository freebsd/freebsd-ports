# New ports collection makefile for:	hp48cc
# Date created:				Sun Aug 12 04:33:37 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	hp48cc
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	http://www.sigala.it/sandro/files/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	C-like compiler that translates input code to the HP48 RPN language

USE_BISON=	yes
GNU_CONFIGURE=	yes

MAN1=	${PORTNAME}.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/examples/* \
		${PREFIX}/share/examples/${PORTNAME}
.endif #NOPORTDOCS

.include <bsd.port.mk>
