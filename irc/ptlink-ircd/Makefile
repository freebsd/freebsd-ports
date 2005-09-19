# New ports collection makefile for:   PTlink IRC daemon
# Date created:        22 October 2004
# Whom:                Dennis Cabooter <dennis@rootxs.org>
#
# $FreeBSD$
#

PORTNAME=	IRCd
PORTVERSION=	6.19.4
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.sunsite.dk/projects/ptlink/ircd/
PKGNAMEPREFIX=	PTlink-
DISTNAME=	PTlink${PORTVERSION}

MAINTAINER=	dennis@rootxs.org
COMMENT=	PTlink IRC daemon

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

USE_RC_SUBR=	ptlink-ircd.sh
SUB_FILES=	pkg-message

SYSCONFDIR=	${PREFIX}/etc/ptlink-ircd
LOGDIR=		${PREFIX}/var/log

CONFIGURE_ARGS=	--sysconfdir=${SYSCONFDIR} --with-pidfile=${SYSCONFDIR}/ircd.pid

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CHOWN} -R ircd:ircd ${SYSCONFDIR}
	@${CHOWN} -R ircd:ircd ${LOGDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
