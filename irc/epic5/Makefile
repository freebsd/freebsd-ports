# New ports collection makefile for:	IrcII-EPIC Client
# Version required:	2.8.2-EPIC3.004
# Date created:		19 June 1997
# Whom:			Matthew Hunt <mph@pobox.com>
#
# $Id: Makefile,v 1.2 1997/10/31 08:52:24 tg Exp $
#

DISTNAME=	ircii2.8.2-EPIC3.004
PKGNAME=	ircii-2.8.2-epic3.004
CATEGORIES=	net
MASTER_SITES=	http://www.min.net/~douglas/ircii/
DISTFILES=	ircii2.8.2-EPIC3.004.tar.gz ircii2.8.2-EPIC3.help.tar.gz

MAINTAINER=	mph@freebsd.org

EXTRACT_ONLY=	ircii2.8.2-EPIC3.004.tar.gz
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/ircii-EPIC3.004

do-install:
		(cd ${WRKSRC} && make INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_DATA="${INSTALL_DATA}" install)

post-install:
		(cd $(PREFIX)/lib/irc && tar xzf $(DISTDIR)/ircii2.8.2-EPIC3.help.tar.gz)
		# Distfile has wrong permissions for...
		chmod 644 $(PREFIX)/lib/irc/help/ON/SILENCE

.include <bsd.port.mk>
