# New ports collection makefile for: 	epic4
# Version required:	4pre2.001-NR14
# Date created:		11 November 1998
# Whom:			Ben Hutchinson <benhutch@xfiles.org.uk>
#
# $Id: Makefile,v 1.9 1999/02/12 07:46:58 flathill Exp $
#

DISTNAME=	ircii-EPIC4pre2.001-NR14
PKGNAME=	epic-4.pre2.001.nr14
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-ALPHA/ \
		ftp://totem.fix.no/pub/mirrors/epic/EPIC4-ALPHA/ \
		ftp://ftp.funet.fi/pub/unix/networking/irc/ircII/epic/ \
		ftp://ftp.pipex.net/pub/people/benhutch/distfiles/epic4/
DISTFILES=	epic4pre2.001-NR14.tar.gz epic4pre2-help.tar.gz

MAINTAINER=	benhutch@xfiles.org.uk

DIST_SUBDIR=	epic4

EXTRACT_ONLY=	epic4pre2.001-NR14.tar.gz
GNU_CONFIGURE=	yes

do-install:
	cd ${WRKSRC} && make INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	INSTALL_DATA="${INSTALL_DATA}" install

post-install:
	cd ${PREFIX}/share/epic && tar zxf ${DISTDIR}/${DIST_SUBDIR}/epic4pre2-help.tar.gz

.include <bsd.port.mk>
