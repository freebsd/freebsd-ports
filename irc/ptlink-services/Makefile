# New ports collection makefile for:   PTlink IRC services
# Date created:        22 October 2004
# Whom:                Dennis Cabooter <dennis@rootxs.org>
#
# $FreeBSD$
#

PORTNAME=       Services
PORTVERSION=    2.25.1
CATEGORIES=     irc
MASTER_SITES=   ftp://ftp.sunsite.dk/projects/ptlink/services2/
PKGNAMEPREFIX=  PTlink-
DISTNAME=       PTlink.${PORTNAME}${PORTVERSION}

MAINTAINER=     dennis@rootxs.org
COMMENT=        PTlink IRC services

GNU_CONFIGURE=  yes
USE_GMAKE=      yes

post-install:
	@${MV} ${PREFIX}/etc/example.conf ${PREFIX}/etc/services.conf.sample
	@${SED} 's,%%PREFIX%%,${PREFIX},g' < ${PKGMESSAGE}

.include <bsd.port.mk>
