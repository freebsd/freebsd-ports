# New ports collection makefile for:	IrcII Client
# Version required:	2.8.2
# Date created:		02 May 1996
# Whom:			Masafumi
#
# $Id: Makefile,v 1.7 1996/12/03 13:08:09 obrien Exp $
#

DISTNAME=	ircii-2.8.2
PKGNAME=	ja-ircii-2.8.2
CATEGORIES=	japanese net
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/clients/ \
		ftp://ftp.kyoto.wide.ad.jp/IRC/ircII/
DISTFILES=	ircii-2.8.2.tar.gz ircii-2.8help.tar.gz

PATCH_SITES=	ftp://ftp.kyoto.wide.ad.jp/IRC/ircII/
PATCHFILES=	ircii-2.8.2-jp.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	max@FreeBSD.ORG

GNU_CONFIGURE=	yes
MAN1=		irc.1

post-install:
	${CP} -R ${WRKDIR}/help ${PREFIX}/lib/irc/
	${INSTALL_MAN} ${WRKSRC}/doc/ircII.1 ${PREFIX}/man/man1/irc.1

.include <bsd.port.mk>
