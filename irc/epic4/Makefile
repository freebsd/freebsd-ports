# New ports collection makefile for: 	epic4
# Date created:		11 November 1998
# Whom:			Ben Hutchinson <benhutch@xfiles.org.uk>
#
# $FreeBSD$
#

PORTNAME=	epic4
PORTVERSION=	0.9.1
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-BETA/ \
		ftp://ftp.sanyusan.se/pub/epic/EPIC4-BETA/ \
		ftp://totem.fix.no/pub/mirrors/epic/EPIC4-BETA/
DISTFILES=	epic4-0.9.1.tar.gz epic4pre2-help.tar.gz

MAINTAINER=	anders@codefactory.se

DIST_SUBDIR=	epic4

EXTRACT_ONLY=	epic4-0.9.1.tar.gz
WRKSRC=         ${WRKDIR}/epic4-0.9.1
GNU_CONFIGURE=	yes

MAN1=		epic.1

do-install:
	cd ${WRKSRC} && make INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	INSTALL_DATA="${INSTALL_DATA}" install

post-install:
	cd ${PREFIX}/share/epic && tar zxf ${DISTDIR}/${DIST_SUBDIR}/epic4pre2-help.tar.gz

.include <bsd.port.mk>
