# New ports collection makefile for:	Irc Server
# Version required:	2.8.21
# Date created:		23 August 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.15 1997/03/11 23:47:08 torstenb Exp $
#

DISTNAME=	irc2.9.2p3
PKGNAME=	irc-2.9.2.3
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
