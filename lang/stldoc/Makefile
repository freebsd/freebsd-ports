# New ports collection makefile for:	stldoc
# Date created:		26 Mar 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	stldoc
PORTVERSION=	1.0
CATEGORIES=	lang devel
MASTER_SITES=	http://www.sgi.com/tech/stl/
DISTNAME=	STL_doc

MAINTAINER=	corecode@corecode.ath.cx

NO_BUILD=	yes

do-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/* ${DOCSDIR}

.include <bsd.port.mk>
