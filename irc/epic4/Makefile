# New ports collection makefile for: 	epic-current
# Version required:	4pre2.001-NR8
# Date created:		11 November 1998
# Whom:			Ben Hutchinson <benhutch@xfiles.org.uk>
#
# $Id: Makefile,v 1.6 1998/11/15 21:27:19 mph Exp $
#

DISTNAME=	ircii-EPIC4pre2.001-NR8
PKGNAME=	epic-4.pre2.001.nr8
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/ \
		ftp://ftp.acronet.net/pub/ircii/
DISTFILES=	epic4pre2.001-NR8.tar.gz epic4pre2-help.tar.gz

MAINTAINER=	benhutch@xfiles.org.uk

EXTRACT_ONLY=	epic4pre2.001-NR8.tar.gz
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/ircii-EPIC4pre2.001-NR8

do-install:
		( cd ${WRKSRC} && make INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}" install )

post-install:
		( cd ${PREFIX}/lib/irc && tar zxf ${DISTDIR}/epic4pre2-help.tar.gz)

.include <bsd.port.mk>
