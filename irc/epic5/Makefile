# New ports collection makefile for: 	epic4
# Version required:	4pre2.001-NR8
# Date created:		11 November 1998
# Whom:			Ben Hutchinson <benhutch@xfiles.org.uk>
#
# $Id$
#

DISTNAME=	ircii-EPIC4pre2.001-NR9
PKGNAME=	epic-4.pre2.001.nr9
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/ \
		ftp://ftp.acronet.net/pub/ircii/ \
		ftp://ftp.funet.fi/pub/unix/networking/irc/ircII/epic/ \
		ftp://ftp.pipex.net/pub/people/benhutch/distfiles/epic4/
DISTFILES=	epic4pre2.001-NR9.tar.gz epic4pre2-help.tar.gz

PATCH_SITES=	ftp://ftp.epicsol.org/pub/epic/ \
		ftp://ftp.acronet.net/pub/ircii/ \
		ftp://ftp.funet.fi/pub/unix/networking/irc/ircII/epic/ \
		ftp://ftp.pipex.net/pub/people/benhutch/distfiles/epic4/
PATCHFILES=	epic4pre2.001-NR9-patch1

MAINTAINER=	benhutch@xfiles.org.uk

EXTRACT_ONLY=	epic4pre2.001-NR9.tar.gz
GNU_CONFIGURE=	yes

do-install:
	cd ${WRKSRC} && make INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	INSTALL_DATA="${INSTALL_DATA}" install

post-install:
	cd ${PREFIX}/share/epic && tar zxf ${DISTDIR}/epic4pre2-help.tar.gz

.include <bsd.port.mk>
