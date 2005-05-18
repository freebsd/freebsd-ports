# New ports collection makefile for:   PTlink IRC daemon
# Date created:        22 October 2004
# Whom:                Dennis Cabooter <dennis@rootxs.org>
#
# $FreeBSD$
#

PORTNAME=	IRCd
PORTVERSION=	6.19.3
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.sunsite.dk/projects/ptlink/ircd/ \
		http://www.rootxs.org/pub/FreeBSD/distfiles/
PKGNAMEPREFIX=	PTlink-
DISTNAME=	PTlink${PORTVERSION}

PATCH_DIST_STRIP=	-p1

MAINTAINER=	dennis@rootxs.org
COMMENT=	PTlink IRC daemon

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

SYSCONFDIR=	${PREFIX}/etc/ptlink
CONFIGURE_ARGS=	--sysconfdir=${SYSCONFDIR}

post-install:
	@${INSTALL_DATA} ${FILESDIR}/*.sample ${SYSCONFDIR}
	@${SED} 's,%%SYSCONFDIR%%,${SYSCONFDIR},g' < ${PKGMESSAGE}

.include <bsd.port.mk>
