# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	unrealgold
PORTVERSION=	436
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://icculus.org/~ravage/unreal/${PORTNAME}/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-install-${PORTVERSION}
EXTRACT_SUFX=	.run
DIST_SUBDIR=	linux-ut

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unreal Gold for Linux

BUILD_DEPENDS=	ut:games/linux-ut
RUN_DEPENDS=	ut:games/linux-ut

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
NO_BUILD=	yes
RESTRICTED=	Redistribution is limited, see license

PLIST_SUB+=	UT="" UG=""
SUB_FILES=	pkg-message
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
HELPFILES=	README ReadMe.htm ReadMe.txt ReadMe220.htm ReadMe222.htm ReadMe223.htm ReadMe224.htm
MANUALFILES=	"Unreal NaPali Manual.pdf" "Unreal manual.pdf"
PORTDOCS=	${HELPFILES}
OPTIONS_DEFINE=	DOCS

CDDIRS=		Help Maps Maps/UPak Music Sounds Sounds/int System Textures

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

UT_DATADIR!=	cd ${PORTSDIR}/games/linux-ut && ${MAKE} -V DATADIR

# Anthology DVD
.if exists(${CDROM_MOUNT}/Disk1/data1.cab)
ANTHOLOGY=	yes
RELEASE_MSG=	"Unreal Anthology"
MANUALFILES=	Manual.pdf
PORTDOCS+=	${MANUALFILES}
EXTRACT_DEPENDS+=	unshield:archivers/unshield
PATCH_DEPENDS+=	xdelta:misc/xdelta
# Original CD
.elif exists(${CDROM_MOUNT}/SYSTEM/UPak.u)
ORIGINAL=	yes
RELEASE_MSG=	"original"
PORTDOCS+=	${MANUALFILES}
PATCH_DEPENDS+=	xdelta:misc/xdelta
# TheSINHumanHead CD
.elif exists(${CDROM_MOUNT}/System-int.tar.bz2)
RAVAGE=		yes
RELEASE_MSG=	"TheSINHumanHead"
MANUALFILES+=	Readme.OpenGL.txt
PORTDOCS=	README ${MANUALFILES}
TARFILES=	Maps Music Sounds-int Sounds System Textures
.endif

do-extract:
	@${MKDIR} ${WRKSRC}/Data
	@cd ${WRKSRC} && ${SED} -e '1,/exit $$res/d' ${_DISTDIR}/${DISTFILES} | \
		${GUNZIP_CMD} -q | ${TAR} xf -
	@${TAR} x -C ${WRKSRC}/Data -f ${WRKSRC}/data.tar.gz
	@${CP} ${WRKSRC}/bin/Linux/x86/glibc-2.1/${PORTNAME} ${WRKSRC}/${PORTNAME}
.if !defined(CDROM_MOUNT)
	@${ECHO_CMD} "${PKGNAME} requires CDROM_MOUNT set to mount point of CD"
	@${FALSE}
.endif
.if !defined(RELEASE_MSG)
	@${ECHO_CMD} "${PKGNAME} requires CD/DVD with Unreal Gold"
	@${FALSE}
.endif
	@${ECHO_CMD} "Detected ${RELEASE_MSG} release"
	@${MKDIR} ${WRKDIR}/source/System
	@${ECHO_CMD} "Please wait while extracting files from CD"
# Anthology release CD
.if defined(ANTHOLOGY)
# We need to create a single directory with all the cab files so unshield can
# find them.
	@${MKDIR} ${WRKDIR}/cab
	@${LN} -sf ${CDROM_MOUNT}/Disk*/data* ${WRKDIR}/cab/
# Extract the files.
.for group in System_English Help Manual_English Maps MapsUPak Textures Music Sounds_All \
	Sounds_English System_All
	@${ECHO_CMD} "Extracting files from ${group}"
	@${LOCALBASE}/bin/unshield -g 1_UnrealGold_${group} -d ${WRKDIR}/source x \
		${WRKDIR}/cab/data1.cab > /dev/null
	@if [ -e ${WRKDIR}/source/1_UnrealGold_${group} ]; then \
	    ${MV} ${WRKDIR}/source/1_UnrealGold_${group} ${WRKDIR}/source/${group}; \
	fi
.endfor
.for group in System_English Sounds_All System_All Manual_English
	@${CP} -Rp ${WRKDIR}/source/${group}/ \
		${WRKDIR}/source/${group:S,_English,,:S,_All,,}
	@${RM} -rf ${WRKDIR}/source/${group}
.endfor
	@${MV} ${WRKDIR}/source/Sounds_English ${WRKDIR}/source/Sounds/int
# Original CD
.elif defined(ORIGINAL)
.for dir in ${CDDIRS:NSystem:NMaps/UPak:NSounds/int} Manuals
	@${LN} -sf ${CDROM_MOUNT}/${dir:tu} ${WRKDIR}/source/${dir}
.endfor
.for _file in UDSDemo.u UPak.u
	@${CP} ${CDROM_MOUNT}/SYSTEM/${_file} ${WRKDIR}/source/System
.endfor
	@${MV} ${WRKDIR}/source/Manuals ${WRKDIR}/source/Manual
# TheSINHumanHead CD
.elif defined(RAVAGE)
# Create file list for tar
	@${GREP} -E "%%UG%%%%DATADIR%%/|DM-" ${PLIST} | \
		${SED} -e 's|\(.*\)/|*|' > ${WRKSRC}/extfiles
.for _file in ${MANUALFILES}
	@${ECHO} Help/${_file} >> ${WRKSRC}/extfiles
.endfor
.for _file in ${TARFILES}
	@${ECHO_CMD} "Extracting files from ${_file}"
	@${TAR} x -C ${WRKDIR}/source -f ${CDROM_MOUNT}/${_file}.tar.bz2 -T ${WRKSRC}/extfiles
.endfor
	@${MV} ${WRKDIR}/source/int ${WRKDIR}/source/Sounds/
	@${LN} -sf ${WRKDIR}/source/Help ${WRKDIR}/source/Manual
	@${CP} ${CDROM_MOUNT}/Readme.OpenGL.txt ${WRKDIR}/source/Help
	@${FIND} ${WRKDIR}/source/Maps -name DM-\*.unr | \
		${SED} 's/\(.*\)\(DM-\)\(.*\)/${LN:S,/,\\/,g} -sf & \1Dm\3/' | ${SH}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|" ${WRKSRC}/${PORTNAME}
# Remove /usr/local from ut-bin lib search path
	@UBIN=${WRKSRC}/Data/System/unreal-bin && \
		FILESIZE=`/usr/bin/stat -f "%z" $${UBIN}` && \
		${MV} $${UBIN} $${UBIN}.orig && \
		${SED} -Ee 's|:/usr/local|:/USR-LOCAL|' $${UBIN}.orig | \
		${HEAD} -c $${FILESIZE} > $${UBIN} && \
		${RM} $${UBIN}.orig
# Apply UPak.u.0 patch
.if !defined(RAVAGE)
	@${LOCALBASE}/bin/xdelta patch ${WRKSRC}/setup.data/data/System/UPak.u.0 \
		${WRKDIR}/source/System/UPak.u ${WRKSRC}/UPak.new
	@${MV} ${WRKSRC}/UPak.new ${WRKDIR}/source/System/UPak.u
.endif

do-install:
	@if [ -n "`${PKG_INFO} -E 'linux-ut-451*' 2> /dev/null`" ]; then \
	    ${ECHO_CMD} "${PKGNAME} requires linux-ut with 436 version."; \
	    ${FALSE}; \
	fi
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${STAGEDIR}${DATADIR} && ${MKDIR} ${CDDIRS}
.for dir in Music Sounds Textures System
	@${ECHO_CMD} "Linking UT ${dir}"
	@${GREP} "%%UT%%%%DATADIR%%/${dir}" ${PLIST} | \
		${SED} -e 's|%%UT%%%%DATADIR%%|${UT_DATADIR}|' | \
			${XARGS} -J % ${LN} -sf % ${STAGEDIR}${DATADIR}/${dir}
.endfor
	${INSTALL_DATA} ${WRKSRC}/Data/Help/Logo.xpm ${STAGEDIR}${DATADIR}/Help
	${INSTALL_DATA} ${WRKSRC}/Data/System/*.ini ${STAGEDIR}${DATADIR}/System
	${INSTALL_DATA} ${WRKSRC}/Data/System/*.int ${STAGEDIR}${DATADIR}/System
	${INSTALL_DATA} ${WRKSRC}/Data/System/*.u ${STAGEDIR}${DATADIR}/System
	${INSTALL_PROGRAM} ${WRKSRC}/Data/System/*-bin ${STAGEDIR}${DATADIR}/System
	@${BRANDELF} -t Linux ${STAGEDIR}${DATADIR}/System/*-bin
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
# Install the files
	@${ECHO_CMD} "Installing files from CD"
.for dir in ${CDDIRS}
	@${GREP} -e "%%UG%%%%DATADIR%%/${dir}/[^/]*$$" ${PLIST} | \
		${SED} -e 's|%%UG%%%%DATADIR%%|${WRKDIR}/source|' | \
			${XARGS} -J % ${INSTALL_DATA} % ${STAGEDIR}${DATADIR}/${dir}
.endfor
# Rename DM maps so UT can see them
	@${FIND} ${STAGEDIR}${DATADIR}/Maps -name Dm\*.unr | \
		${SED} 's/\(.*\)\(Dm\)\(.*\)/${LN:S,/,\\/,g} -sf & \1DM-\3/' | ${SH}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.if !defined(RAVAGE)
.for i in ${HELPFILES:NREADME}
	${INSTALL_DATA} ${WRKDIR}/source/Help/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
.for i in ${MANUALFILES}
	${INSTALL_DATA} ${WRKDIR}/source/Manual/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
