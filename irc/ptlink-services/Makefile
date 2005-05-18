# New ports collection makefile for:   PTlink IRC services
# Date created:        22 October 2004
# Whom:                Dennis Cabooter <dennis@rootxs.org>
#
# $FreeBSD$
#

PORTNAME=	Services
PORTVERSION=    2.26.1
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.sunsite.dk/projects/ptlink/services2/ \
		http://www.rootxs.org/pub/FreeBSD/distfiles/
PKGNAMEPREFIX=	PTlink-
DISTNAME=	PTlink.${PORTNAME}2.26-eol.1

PATCH_DIST_STRIP=	-p1

MAINTAINER=	dennis@rootxs.org
COMMENT=	PTlink IRC services

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

SYSCONFDIR=	${PREFIX}/etc/ptlink
CONFIGURE_ARGS=	--sysconfdir=${SYSCONFDIR}

post-install:
	@${INSTALL_DATA} ${FILESDIR}/*.sample ${SYSCONFDIR}
	@${SED} 's,%%SYSCONFDIR%%,${SYSCONFDIR},g' < ${PKGMESSAGE}

.include <bsd.port.mk>
