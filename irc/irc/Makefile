# New ports collection makefile for:	Irc Server
# Version required:	2.8.20
# Date created:		23 August 1994
# Whom:			torstenb
#
# $Id:$
#

.if !defined(prefix)
prefix=		/usr/local
.endif

DISTNAME=	irc2.8.20
HOME_LOCATION=	ftp://cs-ftp.bu.edu/irc/servers/

pre-install:
	@if [ ! -d $(prefix)/bin ]; then \
	   mkdir -p $(prefix)/bin; \
	fi
	@if [ ! -d $(prefix)/lib/ircd ]; then \
	   mkdir -p $(prefix)/lib/ircd; \
	fi
	@if [ ! -d $(prefix)/man/man1 ]; then \
	   mkdir -p $(prefix)/man/man1; \
	fi
	@if [ ! -d $(prefix)/man/man8 ]; then \
	   mkdir -p $(prefix)/man/man8; \
	fi

.include <bsd.port.mk>
