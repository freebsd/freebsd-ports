# Created by: Erik Olson <erikolson@olsonexpress.com>
# $FreeBSD$

PORTNAME=	nwndata
PORTVERSION=	${NWNVER}
PORTREVISION=	${NWNREV}
CATEGORIES=	games
MASTER_SITES=	http://files.bioware.com/neverwinternights/updates/linux/ \
		http://nwdownloads.bioware.com/neverwinternights/linux/129/ \
		http://lvlt.bioware.cdn.ea.com/bioware/u/f/eagames/bioware/neverwinternights/updates/linux/
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

EXTRACT_DEPENDS+=	7z:archivers/p7zip

PLIST_SUB+=	DIAMOND="" ORIGINAL="@comment "
.else
NWNVER=		1.29
NWNREV=		3
NWRESOURCES=	nwresources${PORTVERSION:S/.//}

PLIST_SUB+=	DIAMOND="@comment " ORIGINAL=""
.endif

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/nwn
RESTRICTED=	Distribution not allowed

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	Binary Distribution on x86 only

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
.if defined(NWN_DIAMOND)
	7z e -y -x'r!*.dll' -x'r!*.exe' -o${WRKSRC}/Kingmaker\
		${CDROM_MOUNT}/KingmakerSetup.exe
.for zipfile in Data_Shared.zip Data_linux.zip data/XP1.zip data/XP2.zip
	(cd ${STAGEDIR}${DATADIR} && ${UNZIP_CMD} -o ${CDROM_MOUNT}/${zipfile})
.endfor
.else
	(cd ${WRKSRC} && ${FIND} . -print | \
	    ${CPIO} -pdmuv -R${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR})
.endif

.include <bsd.port.mk>
