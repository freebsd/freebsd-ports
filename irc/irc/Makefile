# New ports collection makefile for:	Irc Server
# Version required:	2.8.21
# Date created:		23 August 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.14 1996/12/30 21:26:52 max Exp $
#

DISTNAME=	irc2.9.1p16
PKGNAME=	irc-2.9.1.16
CATEGORIES=	net
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/servers/

MAINTAINER=	torstenb@FreeBSD.ORG

# the NOTE command is disabled by default
# ENABLE_NOTE=yes

# Syslog-Facility to use for logging
# default:
SYSLOG_FACILITY=LOG_LOCAL5

EXTRACT_SUFX=	.tgz
SCRIPTS_ENV=	SYSLOG_FACILITY="${SYSLOG_FACILITY}"

MAN8=		ircd.8

do-configure:
	@(cd ${WRKSRC} && make CONFIGARGS=--prefix=${PREFIX})

do-build:
	@(cd ${WRKSRC}/`${WRKSRC}/support/rev.sh` && make all)

do-install:
	@(cd ${WRKSRC}/`${WRKSRC}/support/rev.sh` && make install)

pre-install:
	@${MKDIR} ${PREFIX}/lib/ircd

.include <bsd.port.mk>
