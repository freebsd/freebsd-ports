# New ports collection makefile for:   PTlink IRC daemon
# Date created:        22 October 2004
# Whom:                Dennis Cabooter <dennis@rootxs.org>
#
# $FreeBSD$
#

PORTNAME=	IRCd
PORTVERSION=	6.19.6
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.sunsite.dk/projects/ptlink/ircd/
PKGNAMEPREFIX=	PTlink-
DISTNAME=	PTlink${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PTlink IRC daemon

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

USE_RC_SUBR=	ptlink-ircd.sh
SUB_FILES=	pkg-message

SYSCONFDIR=	${PREFIX}/etc/ptlink-ircd

CONFIGURE_ARGS=	--sysconfdir=${SYSCONFDIR} --localstatedir=/var \
		--with-pidfile=/var/run/ircd.pid

OPTIONS=	OPENSSL "Build with OpenSSL" Off

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL)
CONFIGURE_ARGS+=--with-ssl=openssl
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CHOWN} -R ircd:ircd ${SYSCONFDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
