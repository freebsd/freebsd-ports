# New ports collection makefile for:    Neverwinter Nights Data
# Date created:				4 April 2003
# Whom:					Erik Olson <erikolson@olsonexpress.com>
#
# $FreeBSD$
#

PORTNAME=	nwndata
PORTVERSION=	${NWNVER}
PORTREVISION=	${NWNREV}
CATEGORIES=	games
MASTER_SITES=	http://files.bioware.com/neverwinternights/updates/linux/ \
		http://bioware.vo.llnwd.net/o1/neverwinternights/updates/linux/
# Also at:	http://www.fileshack.com/file.x?fid=2508
DISTNAME=	${NWRESOURCES}
.if defined(CDROM_MOUNT) && exists(${CDROM_MOUNT}/KingmakerSetup.exe)
DISTFILES=
.endif

MAINTAINER=	scf@FreeBSD.org
COMMENT=	Neverwinter Nights Data Files

# Setup port based upon whether this is the Diamond edition or straight NWN.
.if defined(CDROM_MOUNT) && exists(${CDROM_MOUNT}/KingmakerSetup.exe)
NWNVER=		1.61
NWNREV=		0
NWN_DIAMOND=	yes

EXTRACT_DEPENDS+=	7z:${PORTSDIR}/archivers/p7zip

PLIST_SUB+=	DIAMOND="" ORIGINAL="@comment "
.else
NWNVER=		1.29
NWNREV=		3
NWRESOURCES=	nwresources${PORTVERSION:S/.//}

PLIST_SUB+=	DIAMOND="@comment " ORIGINAL=""
.endif

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/nwn
NO_PACKAGE=	Compressed package is in excess of 1 GB

do-install:
	${MKDIR} ${DATADIR}
.if defined(NWN_DIAMOND)
	7z e -y -x'r!*.dll' -x'r!*.exe' -o${WRKSRC}/Kingmaker\
		${CDROM_MOUNT}/KingmakerSetup.exe
.for zipfile in Data_Shared.zip Data_linux.zip data/XP1.zip data/XP2.zip
	(cd ${DATADIR} && ${UNZIP_CMD} -o ${CDROM_MOUNT}/${zipfile})
.endfor
.else
	(cd ${WRKSRC} && ${FIND} . -print | \
	    ${CPIO} -pdmuv -R${SHAREOWN}:${SHAREGRP} ${DATADIR})
.endif

.include <bsd.port.mk>
