# New ports collection makefile for:	Irc Server
# Version required:	2.8.21
# Date created:		23 August 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.17 1998/01/25 20:37:03 torstenb Exp $
#

DISTNAME=	irc2.9.4
PKGNAME=	irc-2.9.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.funet.fi/pub/networking/services/irc/server/

MAINTAINER=	torstenb@FreeBSD.ORG

# the NOTE command is disabled by default
# ENABLE_NOTE=yes

# Syslog-Facility to use for logging
# default:
SYSLOG_FACILITY=LOG_LOCAL5

EXTRACT_SUFX=	.tgz
SCRIPTS_ENV=	SYSLOG_FACILITY="${SYSLOG_FACILITY}"

MAN1=		irc.1
MAN8=		ircd.8

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--without-ncurses

do-build:
	@(cd ${WRKSRC}/`${WRKSRC}/support/config.guess` && make all)

do-install:
	@(cd ${WRKSRC}/`${WRKSRC}/support/config.guess` && make install)

pre-install:
	@${MKDIR} ${PREFIX}/lib/ircd
	@${TOUCH} ${PREFIX}/lib/ircd/users ${PREFIX}/lib/ircd/opers \
		${PREFIX}/lib/ircd/rejects

.include <bsd.port.mk>
