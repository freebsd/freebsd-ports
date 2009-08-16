# New ports collection makefile for:   PTlink IRC services
# Date created:        22 October 2004
# Whom:                Dennis Cabooter <dennis@rootxs.org>
#
# $FreeBSD$
#

PORTNAME=	Services
PORTVERSION=	3.9.2
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.sunsite.dk/projects/ptlink/ircsvs3/
PKGNAMEPREFIX=	PTlink-
DISTNAME=	PTlinkIRC.${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PTlink IRC services

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_MYSQL=	yes

USE_RC_SUBR=	ptlink-services.sh
SUB_FILES=	pkg-message

SYSCONFDIR=	${PREFIX}/etc/ptlink-services

CONFIGURE_ARGS=	--sysconfdir=${SYSCONFDIR} --localstatedir=/var \
		--with-pidfile=/var/run/ircsvs.pid

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CHOWN} -R ircd:ircd ${SYSCONFDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
