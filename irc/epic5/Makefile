# New ports collection makefile for: 	epic4
# Date created:		11 November 1998
# Whom:			Ben Hutchinson <benhutch@xfiles.org.uk>
#
# $FreeBSD$
#

PORTNAME=	epic4
PORTVERSION=	1.0.1
# Make these variables overridable for slave ports
PORTREVISION?=	1
CATEGORIES?=	irc ipv6
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/%SUBDIR%/ \
		ftp://ftp.magenet.com/pub/epic/%SUBDIR%/ \
		ftp://ftp.icm.edu.pl/vol/rzm0/irc/EPIC/%SUBDIR%/ \
		ftp://ftp.archive.de.uu.net/pub/unix/irc/epic/%SUBDIR%/ \
		ftp://ftp.nl.uu.net/pub/unix/irc/epic/%SUBDIR%/ \
#		ftp://ftp.neato.org/pub/epic/%SUBDIR%/ \
#		ftp://totem.fix.no/pub/mirrors/epic/%SUBDIR%/ \
#		ftp://broken.com/pub/ircii/%SUBDIR%/
MASTER_SITE_SUBDIR=	EPIC4-PRODUCTION
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTFILE_HELP}
DIST_SUBDIR=	epic4
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=    http://www.t17.ds.pwr.wroc.pl/~misiek/ipv6/
PATCHFILES=     ${DISTNAME}-ipv6-20010418.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	anders@hack.org

USE_BZIP2=	yes
USE_AUTOCONF=	yes

DISTFILE_HELP=	${PORTNAME}pre2-help.tar.gz

MAN1=		epic.1

post-install:
	cd ${PREFIX}/share/epic && ${TAR} zxf ${_DISTDIR}/${DISTFILE_HELP}

.include <bsd.port.mk>
