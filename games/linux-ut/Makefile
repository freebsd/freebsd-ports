# Created by: Sean Farley <sean-freebsd@farley.org>
# $FreeBSD$

PORTNAME=	linux-ut
PORTVERSION=	${UTVERSION}
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	games linux
MASTER_SITES=	http://liflg.holarse-linuxgaming.de/files/final/:p436 \
		http://www.utpg.org/patches/:p451
DISTFILES=	${PATCH436FILES} \
		${PATCH451FILES}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	scf@FreeBSD.org
COMMENT=	Unreal Tournament for Linux

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs sdl12
NO_BUILD=	yes
NO_PACKAGE=	Distribution is 340MB; set FORCE_PACKAGE if you really want\
		to build this package
MANUAL_PACKAGE_BUILD=	Requires CD
RESTRICTED=	Redistribution is limited, see license
WRKSRC=		${WRKDIR}/${PKGNAME}

CONFLICTS_INSTALL=	exult-[0-9]* ucc-[0-9]*

# Patch files.
PATCH436FILES=	unreal.tournament_436-multilanguage.run:p436 \
		unreal.tournament.official.bonus.pack.collection.run:p436

CDDIRS=		Help Logs Maps Music Sounds System Textures Web

# Checks
#   - Verify path to CD content.
#   - Verify CD was correctly mounted by checking for incorrect NetGamesUSA.com.
#     -b option may be needed to mount it.
.if !defined(CDROM_MOUNT)
IGNORE= 	requires CDROM_MOUNT set to mount point of CD
.elif exists(${CDROM_MOUNT}/netgam~1.com)
IGNORE= 	requires CD mounting with -b option
.endif

# Anthology install.
.if exists(${CDROM_MOUNT}/Disk1/data1.cab)
ANTHOLOGY=	yes
RELEASE_MSG=	"Unreal Anthology"
CDDIRS+=	Manual
BUILD_DEPENDS+=	${LOCALBASE}/bin/unshield:archivers/unshield
UNSHIELD=	${LOCALBASE}/bin/unshield
PLIST_SUB+=	ANTHOLOGY="" ORIGINAL="@comment "
.else
RELEASE_MSG=	"original/GOTY"
PLIST_SUB+=	ANTHOLOGY="@comment " ORIGINAL=""
.endif

OPTIONS_DEFINE=	MAPS V451PATCH
OPTIONS_DEFAULT=MAPS
OPTIONS_SUB=	yes
MAPS_DES=	Install additional maps
V451PATCH=	With version 451 patch

.include <bsd.port.options.mk>

# Maps
.if ${PORT_OPTIONS:MMAPS}
MAPS_EXCLUDE=	# Empty
.else
MAPS_EXCLUDE=	--exclude 'AS*' --exclude 'CTF*' --exclude 'DM*'\
		--exclude 'DOM*' --exclude 'EOL*'
.endif

# Patch
.if ${PORT_OPTIONS:MV451PATCH}
PATCH451FILES=	UTPGPatch451.tar.bz2:p451
UTVERSION=	451
.else
PATCH451FILES=	# Empty
UTVERSION=	436
.endif

do-extract:
	@${CAT} ${PKGMESSAGE}
	@${MKDIR} ${WRKSRC}
.for file in ${PATCH436FILES:C/:.*//}
	@cd ${WRKSRC} &&\
		${SED} -e '1,/exit $$res/d' ${_DISTDIR}/${file} |\
			${GUNZIP_CMD} -q | ${TAR} xf -
.endfor
	@${MV} ${WRKSRC}/bin/Linux/x86/ucc ${WRKSRC}/bin/.

post-patch:
	@${REINPLACE_CMD} -e "s|\(UT_DATA_PATH=\).*|\1\"${DATADIR}/System\"|"\
		${WRKSRC}/bin/ucc
	@${REINPLACE_CMD} -e "s|^\(GAME_DIR=\).*|\1\"${DATADIR}\"|"\
		-e "/ll=/{N;d;}" ${WRKSRC}/bin/ut

# Installation steps performed:
#   - Copy desired content off of CD to drive.  Windows files left behind.
#   - Extract files from Linux patch minus various language files (necessary?).
#   - Extract bonus pack.
#   - Patch .ini file to also use absolute paths to content in addition to the
#     relative paths for user saved content.
#   - Apply Linux patches.
#   - Install scripts and README's.
#   - Set permissions on files and directories.
do-install:
	@${ECHO_CMD} "Detected ${RELEASE_MSG} release"
	@${ECHO_CMD} "Installing data from CD"
	@${MKDIR} ${STAGEDIR}${DATADIR}
####################################
# Anthology release CD
####################################
.if defined(ANTHOLOGY)
	@cd ${STAGEDIR}${DATADIR} && ${MKDIR} ${CDDIRS}

# We need to create a single directory with all the cab files so unshield can
# find them.
	@${MKDIR} ${WRKDIR}/cab ${WRKDIR}/unshield
	@${LN} -sf ${CDROM_MOUNT}/Disk*/data* ${WRKDIR}/cab/

# Extract the files.
.for group in Maps Manual_English Web Textures Music Sounds_English Sounds_All\
	System_All System_English Help
	@${UNSHIELD} -g 3_UnrealTournament_${group} -d ${WRKDIR}/unshield x\
		${WRKDIR}/cab/data1.cab

	@cd ${WRKDIR}/unshield/3_UnrealTournament_${group} &&\
		${TAR} c --exclude '*.ICD' --exclude '*.bat' --exclude '*.dll'\
			--exclude '*.est*' --exclude '*.[Ee][Xx][Ee]'\
			--exclude '*.frt*' --exclude '*.ico' --exclude '*.itt*'\
			--exclude '*.mpi' --exclude '*.url' --exclude 'D3D*'\
			--exclude 'mplay*' --exclude 'Splash*' ${MAPS_EXCLUDE}\
			--exclude 'edsplash.bmp' --exclude 'UnrealEd.ini'\
			--exclude 'editorres*' -f - . |\
		${TAR} x -C ${STAGEDIR}${DATADIR}/`${ECHO_CMD}\
			3_UnrealTournament_${group} | ${SED} -e\
			's/3_UnrealTournament_//; s/_All//; s/_English//;'` -f -
.endfor

	@cd ${STAGEDIR}${DATADIR}/System &&\
		${MV} -f epiccustommodels.u EpicCustomModels.u &&\
		${MV} -f multimesh.u MultiMesh.u &&\
		${MV} -f multimesh.int MultiMesh.int &&\
		${MV} -f relics.u Relics.u &&\
		${MV} -f relics.int Relics.int &&\
		${MV} -f relicsbindings.u RelicsBindings.u &&\
		${MV} -f relicsbindings.int RelicsBindings.int &&\
		${MV} -f tcowmeshskins.int TCowMeshSkins.int &&\
		${MV} -f tnalimeshskins.int TNaliMeshSkins.int &&\
		${MV} -f tskmskins.int TSkMSkins.int
	@cd ${STAGEDIR}${DATADIR}/Textures &&\
		${MV} -f tcowmeshskins.utx TCowMeshSkins.utx &&\
		${MV} -f tnalimeshskins.utx TNaliMeshSkins.utx &&\
		${MV} -f tskmskins.utx TSkMSkins.utx
####################################
# Original/GOTY release CD
####################################
.else
# Install the files from CD.
.for dir in ${CDDIRS}
	@cd ${CDROM_MOUNT} &&\
		${TAR} c --exclude '*.ICD' --exclude '*.bat' --exclude '*.dll'\
			--exclude '*.est*' --exclude '*.[Ee][Xx][Ee]'\
			--exclude '*.frt*' --exclude '*.ico' --exclude '*.itt*'\
			--exclude '*.mpi' --exclude '*.url' --exclude 'D3D*'\
			--exclude 'edsplash.bmp' --exclude 'UnrealEd.ini'\
			--exclude 'editorres*' --exclude 'mplay*'\
			${MAPS_EXCLUDE} -f - ${dir} |\
		${TAR} x -C ${STAGEDIR}${DATADIR} -f -
.endfor
	@${RM} ${STAGEDIR}${DATADIR}/Logs/delete_me.txt
	@${RMDIR} ${STAGEDIR}${DATADIR}/Logs
.endif
####################################
# End of CD release-specific install
####################################

# Install v436 Linux binaries.
	@${ECHO_CMD} "Installing v436 patch files"
.for tarfile in Credits OpenGL.ini data
	@${TAR} zox -C ${STAGEDIR}${DATADIR} --exclude '*.exe'\
		-f ${WRKSRC}/${tarfile}.tar.gz
.endfor

# Anthology does not need v436 patch applied.
.if !defined(ANTHOLOGY)
# Apply v436 files.
	@${ECHO_CMD} "Applying v436 patch"
	@${WRKSRC}/setup.data/bin/FreeBSD/x86/loki_patch\
		${WRKSRC}/setup.data/patch.dat ${STAGEDIR}${DATADIR}
.endif

# Adjust paths in configuration.
	@${SED} -i "" -e 's|\\|/|g'\
		-e "/^Paths=/{h;s|\(Paths=\)\.\./|\1${DATADIR}/|;x;p;x;}"\
		${STAGEDIR}${DATADIR}/System/UnrealTournament.ini
.for script in ucc ut
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${script} ${STAGEDIR}${PREFIX}/bin/
.endfor

# Install bonus packs
	@${ECHO_CMD} "Installing bonus packs"
.for ndx in 1 2 3 4
.if defined(WITHOUT_MAPS)
	@${TAR} jx -C ${STAGEDIR}${DATADIR} --exclude '*.unr' -f ${WRKSRC}/bp${ndx}.tar.bz2
.else
	@${TAR} jx -C ${STAGEDIR}${DATADIR} -f ${WRKSRC}/bp${ndx}.tar.bz2
.endif
.endfor

# Install bonus packs.
.for datafile in README README.Loki README.bonus.pack.collection
	@${INSTALL_DATA} ${WRKSRC}/${datafile} ${STAGEDIR}${DATADIR}
.endfor

# Install 451 Patch
.if defined(WITH_451PATCH)
	@${ECHO_CMD} "Installing v${UTVERSION} patch files"
	@${TAR} jx -C ${STAGEDIR}${DATADIR} --exclude 'checkfiles.sh'\
		--exclude 'patch.md5' --exclude 'd3ddrv.int'\
		--exclude 'edsplash.bmp' --exclude 'UnrealEd.ini'\
		--exclude 'editorres*' -f ${_DISTDIR}/${PATCH451FILES:C/:.*//}
	@cd ${STAGEDIR}${DATADIR}/System &&\
		${MV} -f glidedrv.int GlideDrv.int &&\
		${MV} -f softdrv.int SoftDrv.int &&\
		${MV} -f opengldrv.int OpenGlDrv.int &&\
		${MV} -f galaxy.int Galaxy.int &&\
		${MV} -f editor.int Editor.int &&\
		${MV} -f windrv.int WinDrv.int
.endif

# Replace older libSDL included with UT; it has issues with the Nvidia driver
# when using Fedora 10 at the base.
	@${LN} -sf ${LINUXBASE}/usr/lib/libSDL-1.2.so.0\
		${STAGEDIR}${DATADIR}/System/libSDL-1.1.so.0

# Remove /usr/local from ut-bin lib search path
	@${ECHO_CMD} "Removing /usr/local from ut-bin's library search path"
	@UTBIN=${STAGEDIR}${DATADIR}/System/ut-bin &&\
		FILESIZE=`${STAT} -f "%z" $${UTBIN}` &&\
		${MV} $${UTBIN} $${UTBIN}.orig &&\
		${SED} -Ee 's|:/usr/local|:/USR-LOCAL|' $${UTBIN}.orig |\
		${HEAD} -c $${FILESIZE} > $${UTBIN} &&\
		${RM} $${UTBIN}.orig

# Set file permissions
	@${ECHO_CMD} "Setting permissions"
	@${FIND} ${STAGEDIR}${DATADIR} -print0 |\
		${XARGS} -0 ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${STAGEDIR}${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}
	@${FIND} ${STAGEDIR}${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${NOBINMODE}
	@${FIND} ${STAGEDIR}${DATADIR} \( -name "*.so" -o -name "lib*.so*" \) -print0 |\
		${XARGS} -0 ${CHMOD} ${BINMODE}
.for exec in ucc-bin ut-bin
	@${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/System/${exec}
.endfor

	@${TOUCH} ${STAGEDIR}${DATADIR}/Help/ReleaseNotes.htm
	@${ECHO_CMD} "Install complete"

.include <bsd.port.mk>
