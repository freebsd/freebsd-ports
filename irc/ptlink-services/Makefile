# New ports collection makefile for:   PTlink IRC services
# Date created:        22 October 2004
# Whom:                Dennis Cabooter <dennis@rootxs.org>
#
# $FreeBSD$
#

PORTNAME=	Services
PORTVERSION=	3.9.2
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.sunsite.dk/projects/ptlink/ircsvs3/
PKGNAMEPREFIX=	PTlink-
DISTNAME=	PTlinkIRC.${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PTlink IRC services

DEPRECATED=	No upstream source, no distfile and no maintainer
EXPIRATION_DATE=2011-09-03

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_MYSQL=	yes

USERS=		ircd
GROUPS=		${USERS}

USE_RC_SUBR=	ptlink-services.sh
SUB_FILES=	pkg-message

SYSCONFDIR=	${PREFIX}/etc/ptlink-services

CONFIGURE_ARGS=	--sysconfdir=${SYSCONFDIR} --localstatedir=/var \
		--with-pidfile=/var/run/ircsvs.pid

post-install:
	@${CHOWN} -R ircd:ircd ${SYSCONFDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
