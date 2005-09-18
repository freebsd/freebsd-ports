# New ports collection makefile for:   PTlink IRC services
# Date created:        22 October 2004
# Whom:                Dennis Cabooter <dennis@rootxs.org>
#
# $FreeBSD$
#

PORTNAME=	Services
PORTVERSION=	3.4.1
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.sunsite.dk/projects/ptlink/ircsvs3/
PKGNAMEPREFIX=	PTlink-
DISTNAME=	PTlinkIRC.${PORTNAME}${PORTVERSION}

MAINTAINER=	dennis@rootxs.org
COMMENT=	PTlink IRC services

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_MYSQL=	yes

USE_RC_SUBR=	ptlink-services.sh
SUB_FILES=	pkg-message

SYSCONFDIR=	${PREFIX}/etc/ptlink-services

CONFIGURE_ARGS=	--sysconfdir=${SYSCONFDIR}

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CHOWN} -R ${USER}:${GROUP} ${SYSCONFDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
