# New ports collection makefile for:    Neverwinter Nights Data
# Date created:				4 April 2003
# Whom:					Erik Olson <erikolson@olsonexpress.com>
#
# $FreeBSD$
#

PORTNAME=	nwndata
PORTVERSION=	1.29
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://jeuxlinux.com/bioware/Neverwinter_Nights/
DISTNAME=	nwresources${PORTVERSION:S/.//}

MAINTAINER=	des@FreeBSD.org
COMMENT=	Neverwinter Nights Data Files

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/nwn
TOLOWER=	${TR} '[:upper:]' '[:lower:]'

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${FIND} * -type d | while read d ; do \
		${MKDIR} "${DATADIR}/$${d}" ; \
	done)
	(cd ${WRKSRC} && ${FIND} * -type f -or -type l | while read f ; do \
		${CP} -v "$${f}" "${DATADIR}/$$(echo $${f} | ${TOLOWER})" ; \
	done)

.include <bsd.port.mk>
