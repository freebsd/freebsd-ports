# New ports collection makefile for:    Neverwinter Nights Data
# Date created:				4 April 2003
# Whom:					Erik Olson <erikolson@olsonexpress.com>
#
# $FreeBSD$
#

PORTNAME=	nwndata
PORTVERSION=	1.29
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	ftp://jeuxlinux.com/bioware/Neverwinter_Nights/
DISTNAME=	nwresources${PORTVERSION:S/.//}

MAINTAINER=	des@FreeBSD.org
COMMENT=	Neverwinter Nights Data Files

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/nwn
NO_PACKAGE=	"Compressed package is in excess of 1 GB"

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${FIND} . -print | \
	    ${CPIO} -pdmuv -R${SHAREOWN}:${SHAREGRP} ${DATADIR})

.include <bsd.port.mk>
