# New ports collection makefile for:	civ2 demo
# Date created:				19 October 2000
# Whom:					jameso@elwood.net
#
# $FreeBSD$
#

PORTNAME=	civ2demo
PORTVERSION=	1.0
CATEGORIES=	games linux
MASTER_SITES=	ftp://download.linuxlords.com/pub/demos/civctp/
DISTNAME=	civctp-demo-10251999
EXTRACT_ONLY=

MAINTAINER=	jameso@elwood.net
COMMENT=	The free demo of Civilization: Call to Power

ONLY_FOR_ARCHS=	i386

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	@${SH} ${FILESDIR}/do-install ${PREFIX} ${DISTDIR}

.include <bsd.port.mk>
