# ex:ts=8
# Ports collection makefile for:	qfsm
# Date created:			Mar 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qfsm
PORTVERSION=	0.40
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_QT_VER=	3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/*.fsm ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
