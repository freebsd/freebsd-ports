# New ports collection makefile for:	Blackened IRC client
# Version required:	1.6.2
# Date created:		11 Jun 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $Id$
#

DISTNAME=	blackened-1.6.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.blackened.com/pub/irc/blackened/ \
		http://www.cana.net/~acme/blackened/ \
		http://www.psn.net/~andrews/blackened/

MAINTAINER=	andrews@technologist.com

GNU_CONFIGURE=	YES
WRKSRC=		${WRKDIR}/${PKGNAME}

# blackened's ircserv/ircflush/wserv might conflict with those of
# other clients... also want to change the symlink...
do-build:
	@(cd ${WRKSRC} && make prefix="${PREFIX}" \
	INSTALL_IRCSERV="${PREFIX}/bin/blackened-ircserv" \
	INSTALL_IRCFLUSH="${PREFIX}/bin/blackened-ircflush" \
	INSTALL_WSERV="${PREFIX}/bin/blackened-wserv" \
	INSTALL_LINK="${PREFIX}/bin/blackened" \
	IRCLIB="${PREFIX}/bin/blackened")

do-install:
	@(cd ${WRKSRC} && make prefix="${PREFIX}" \
	INSTALL_IRCSERV="${PREFIX}/bin/blackened-ircserv" \
	INSTALL_IRCFLUSH="${PREFIX}/bin/blackened-ircflush" \
	INSTALL_WSERV="${PREFIX}/bin/blackened-wserv" \
	INSTALL_LINK="${PREFIX}/bin/blackened" \
	IRCLIB="${PREFIX}/blackened" \
	install)

.include <bsd.port.mk>
