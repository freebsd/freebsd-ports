# New ports collection makefile for: 	epic4
# Date created:		11 November 1998
# Whom:			Ben Hutchinson <benhutch@xfiles.org.uk>
#
# $FreeBSD$
#

PORTNAME=	epic4
PORTVERSION=	1.0
# Make CATEGORIES overridable for slave ports
CATEGORIES?=	irc
MASTER_SITES=	ftp://ftp.magenet.com/pub/epic/%SUBDIR%/ \
		ftp://ftp.icm.edu.pl/vol/rzm0/irc/EPIC/%SUBDIR%/ \
		ftp://ftp.archive.de.uu.net/pub/unix/irc/epic/%SUBDIR%/ \
		ftp://ftp.nl.uu.net/pub/unix/irc/epic/%SUBDIR%/ \
		${MASTER_SITE_LOCAL:S,%SUBDIR%,knu,}
#		ftp://ftp.epicsol.org/pub/epic/%SUBDIR%/ \
#		ftp://ftp.neato.org/pub/epic/%SUBDIR%/ \
#		ftp://totem.fix.no/pub/mirrors/epic/%SUBDIR%/ \
#		ftp://broken.com/pub/ircii/%SUBDIR%/
MASTER_SITE_SUBDIR=	EPIC4-PRODUCTION
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTFILE_HELP}
DIST_SUBDIR=	epic4
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

#PATCH_SITES=	${MASTER_SITES}
#PATCHFILES=	${DISTNAME}-patch1
#PATCH_DIST_STRIP=	-d ${WRKSRC}/source

MAINTAINER=	anders@codefactory.se

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

DISTFILE_HELP=	${PORTNAME}pre2-help.tar.gz

MAN1=		epic.1

post-install:
	cd ${PREFIX}/share/epic && ${TAR} zxf ${_DISTDIR}/${DISTFILE_HELP}

.include <bsd.port.mk>
