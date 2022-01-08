# Created by: Erik Olson <erikolson@olsonexpress.com>

PORTNAME=	nwndata
PORTVERSION=	${NWNVER}
PORTREVISION=	${NWNREV}
CATEGORIES=	games
MASTER_SITES=	http://na.llnet.bioware.cdn.ea.com/u/f/eagames/bioware/neverwinternights/updates/linux/ \
		http://lvlt.bioware.cdn.ea.com/bioware/u/f/eagames/bioware/neverwinternights/updates/linux/
DISTNAME=	${NWRESOURCES}
.if defined(CDROM_MOUNT) && exists(${CDROM_MOUNT}/KingmakerSetup.exe)
DISTFILES=
.endif

MAINTAINER=	scf@FreeBSD.org
COMMENT=	Neverwinter Nights Data Files

LICENSE=	Proprietary
LICENSE_NAME=	Proprietary
LICENSE_TEXT=	Distribution not allowed
LICENSE_PERMS=	auto-accept

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	binary distribution for x86 only

# Setup port based upon whether this is the Diamond edition or straight NWN.
.if defined(CDROM_MOUNT) && exists(${CDROM_MOUNT}/KingmakerSetup.exe)
NWNVER=		1.61
NWNREV=		0
NWN_DIAMOND=	yes

USES=		7z:7-zip zip

PLIST_SUB+=	DIAMOND="" ORIGINAL="@comment "
.else
NWNVER=		1.29
NWNREV=		3
NWRESOURCES=	nwresources${PORTVERSION:S/.//}

PLIST_SUB+=	DIAMOND="@comment " ORIGINAL=""
.endif

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/nwn

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
.if defined(NWN_DIAMOND)
	${LOCALBASE}/bin/${7-ZIP_CMD} e -y -x'r!*.dll' -x'r!*.exe'\
		-o${WRKSRC}/Kingmaker ${CDROM_MOUNT}/KingmakerSetup.exe
.for zipfile in Data_Shared.zip Data_linux.zip data/XP1.zip data/XP2.zip
	(cd ${STAGEDIR}${DATADIR} && ${UNZIP_NATIVE_CMD}\
		-o ${CDROM_MOUNT}/${zipfile})
.endfor
.else
	(cd ${WRKSRC} && ${FIND} . -print | \
	    ${CPIO} -pdmuv -R${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR})
.endif

.include <bsd.port.mk>
