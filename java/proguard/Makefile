# New ports collection makefile for:	proguard
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	proguard
PORTVERSION=	1.5.1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	alexs@snark.rinet.ru
COMMENT=	Java obfuseeKata

USE_JAVA=	1.1+
NO_BUILD=	yes

do-install:
	-@${MKDIR} ${PREFIX}/share/proguard
	@${CP} -PRpf ${WRKSRC}/lib ${PREFIX}/share/proguard
	@${CP} -PRpf ${WRKSRC}/docs ${PREFIX}/share/proguard
	@${CP} -PRpf ${WRKSRC}/examples ${PREFIX}/share/proguard

.include <bsd.port.mk>
