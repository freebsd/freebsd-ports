# New ports collection makefile for:   PTlink IRC daemon
# Date created:        22 October 2004
# Whom:                Dennis Cabooter <dennis@rootxs.org>
#
# $FreeBSD$
#

PORTNAME=      	IRCd
PORTVERSION=    6.18.2
CATEGORIES=     irc
MASTER_SITES=   ftp://ftp.sunsite.dk/projects/ptlink/ircd/
PKGNAMEPREFIX=	PTlink-
DISTNAME=       PTlink${PORTVERSION}

MAINTAINER=     dennis@rootxs.org
COMMENT=        PTlink IRC daemon

GNU_CONFIGURE=  yes
USE_GMAKE=      yes

post-install:
.for f in ircd.conf ircd.motd kline.conf main.dconf network.dconf opers.motd
	@${MV} ${PREFIX}/etc/${f} ${PREFIX}/etc/${f}.sample
.endfor
	@${SED} 's,%%PREFIX%%,${PREFIX},g' < ${PKGMESSAGE}

.include <bsd.port.mk>
