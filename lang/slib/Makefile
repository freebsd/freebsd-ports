# New ports collection makefile for:   slib
# Date created:        01 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	slib
PORTVERSION=	2d1
CATEGORIES=	lang
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/
DISTNAME=	slib2d1

MAINTAINER=	nakai@FreeBSD.org

WRKSRC=		${WRKDIR}/slib

USE_ZIP=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/share/slib
	${INSTALL_DATA} ${WRKSRC}/*.scm ${PREFIX}/share/slib

.include <bsd.port.mk>
