# New ports collection makefile for: 	epic4
# Version required:	4pre2.001-NR8
# Date created:		11 November 1998
# Whom:			Ben Hutchinson <benhutch@xfiles.org.uk>
#
# $Id: Makefile,v 1.8 1998/12/13 12:39:59 jseger Exp $
#

DISTNAME=	ircii-EPIC4pre2.001-NR13
PKGNAME=	epic-4.pre2.001.nr13
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-ALPHA/ \
		ftp://totem.fix.no/pub/mirrors/epic/EPIC4-ALPHA/ \
		ftp://ftp.funet.fi/pub/unix/networking/irc/ircII/epic/ \
		ftp://ftp.pipex.net/pub/people/benhutch/distfiles/epic4/
DISTFILES=	epic4pre2.001-NR13.tar.gz epic4pre2-help.tar.gz

PATCH_SITES=	ftp://ftp.pipex.net/people/benhutch/distfiles/epic4/
PATCHFILES=	epic4pre2.001-NR13-patch1 epic4pre2.001-NR13-patch2

MAINTAINER=	benhutch@xfiles.org.uk

DIST_SUBDIR=	epic4

EXTRACT_ONLY=	epic4pre2.001-NR13.tar.gz
GNU_CONFIGURE=	yes

do-install:
	cd ${WRKSRC} && make INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	INSTALL_DATA="${INSTALL_DATA}" install

post-install:
	cd ${PREFIX}/share/epic && tar zxf ${DISTDIR}/${DIST_SUBDIR}/epic4pre2-help.tar.gz

.include <bsd.port.mk>
