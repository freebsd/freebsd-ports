# New ports collection makefile for:	Irc Server
# Version required:	2.10.1
# Date created:		23 August 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.18 1998/01/26 10:44:18 asami Exp $
#

DISTNAME=	irc2.10.1
PKGNAME=	irc-2.10.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.funet.fi/pub/networking/services/irc/server/ \
		ftp://ftp.irc.org/irc/server/ \
		ftp://tau.ac.il/pub/unix/irc/server/ \
		ftp://ftp.ut.ee/pub/unix/irc/server/ \
		ftp://ftp.ntua.gr/pub/net/irc/server/

MAINTAINER=	torstenb@FreeBSD.ORG

# the NOTE command is disabled by default
# ENABLE_NOTE=yes

# Syslog-Facility to use for logging
# default:
SYSLOG_FACILITY=LOG_LOCAL5

EXTRACT_SUFX=	.tgz
SCRIPTS_ENV=	SYSLOG_FACILITY="${SYSLOG_FACILITY}"

MAN1=		irc.1
MAN5=		iauth.conf.5
MAN8=		ircd.8 iauth.8 ircdwatch.8

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
