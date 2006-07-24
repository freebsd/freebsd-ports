# New ports collection makefile for:	linux-ut
# Date created:		7 Jan 2006
# Whom:			Sean Farley <sean-freebsd@farley.org>
#
# $FreeBSD$
#

PORTNAME=	linux-ut
PORTVERSION=	451
CATEGORIES=	games linux
MASTER_SITES=	http://liflg.org/?what=dl\&catid=6\&gameid=51\&filename=/:p436 \
		http://www.utpg.org/patches/:p451
DISTFILES=	${PATCH436FILES} \
		${PATCH451FILES}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	sean-freebsd@farley.org
COMMENT=	Unreal Tournament for Linux

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12

# A redirect will occur, so have fetch save the file with the correct name.
FETCH_CMD=	/usr/bin/fetch -Rr
FETCH_BEFORE_ARGS=	-o $${file}

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_XLIB=	yes
NO_BUILD=	yes
NO_PACKAGE=	Distribution is 340MB; set FORCE_PACKAGE if you really want\
		to build this package
RESTRICTED=	Redistribution is limited, see license
IS_INTERACTIVE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

PATCH436FILES=	unreal.tournament_436-multilanguage.run:p436 \
		unreal.tournament.official.bonus.pack.collection.run:p436
PATCH451FILES=	UTPGPatch451.tar.bz2:p451

do-extract:
	@${MKDIR} ${WRKSRC}
.for file in ${PATCH436FILES:C/:.*//}
	@cd ${WRKSRC} &&\
		${SED} -e '1,/exit $$res/d' ${_DISTDIR}/${file} | ${TAR} zxf -
.endfor
	@${MV} ${WRKSRC}/bin/Linux/x86/ucc ${WRKSRC}/bin/.

post-patch:
	@${REINPLACE_CMD} -e "s|\(UT_DATA_PATH=\).*|\1\"${DATADIR}/System\"|"\
		${WRKSRC}/bin/ucc
	@${REINPLACE_CMD} -e "s|^\(GAME_DIR=\).*|\1\"${DATADIR}\"|"\
		-e "/ll=/{N;d;}" ${WRKSRC}/bin/ut

# Installation steps performed:
#   - Verify path to CD content.
#   - Verify CD was correctly mounted.  -b option may be needed to mount it.
#   - Copy desired content off of CD to drive.  Windows files left behind.
#   - Extract files from Linux patch minus various language files (necessary?).
#   - Extract bonus pack.
#   - Patch .ini file to also use absolute paths to content in addition to the
#     relative paths for user saved content.
#   - Apply Linux patches.
#   - Install scripts and README's.
#   - Set permissions on files and directories.
do-install:
.if !defined(CDROM_MOUNT)
	@${ECHO_CMD} "${PKGNAME} requires CDROM_MOUNT set to mount point of CD"
	@${FALSE}
.endif
.if !exists(${CDROM_MOUNT}/NetGamesUSA.com)
	@${ECHO_CMD} \
		"NetGamesUSA.com not found on CD; try mounting with -b option"
	@${FALSE}
.endif
	@${ECHO_CMD} "Installing data from CD"
	@${MKDIR} ${DATADIR}
.for dir in Help Logs Maps Music NetGamesUSA.com Sounds System Textures Web
	@cd ${CDROM_MOUNT} &&\
		${TAR} c --exclude '*.ICD' --exclude '*.bat' --exclude '*.dll'\
			--exclude '*.est*' --exclude '*.[Ee][Xx][Ee]'\
			--exclude '*.frt*' --exclude '*.ico' --exclude '*.itt*'\
			--exclude '*.mpi' --exclude '*.url' --exclude 'D3D*'\
			--exclude 'mplay*' -f - ${dir} |\
		${TAR} x -C ${DATADIR} -f -
.endfor
	@${RM} ${DATADIR}/Logs/delete_me.txt
	@${ECHO_CMD} "Installing v436 patch files"
.for tarfile in Credits NetGamesUSA.com OpenGL.ini data
	@${TAR} zox -C ${DATADIR} --exclude '*.exe'\
		-f ${WRKSRC}/${tarfile}.tar.gz
.endfor
	@${ECHO_CMD} "Installing bonus pack"
.for ndx in 1 2 3 4
	@${TAR} jx -C ${DATADIR} -f ${WRKSRC}/bp${ndx}.tar.bz2
.endfor
	@${SED} -i "" -e 's|\\|/|g'\
		-e "/^Paths=/{h;s|\(Paths=\)\.\./|\1${DATADIR}/|;x;p;x;}"\
		${DATADIR}/System/UnrealTournament.ini
	@${ECHO_CMD} "Applying v436 patch"
	@${WRKSRC}/setup.data/bin/FreeBSD/x86/loki_patch\
		${WRKSRC}/setup.data/patch.dat ${DATADIR}
.for script in ucc ut
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${script} ${PREFIX}/bin/
.endfor
.for datafile in README README.Loki README.bonus.pack.collection
	@${INSTALL_DATA} ${WRKSRC}/${datafile} ${DATADIR}
.endfor
	@${ECHO_CMD} "Installing v${PORTVERSION} patch files"
	@${TAR} jx -C ${DATADIR} --exclude 'checkfiles.sh'\
		--exclude 'patch.md5' --exclude 'd3ddrv.int'\
		-f ${_DISTDIR}/${PATCH451FILES:C/:.*//}
	@cd ${DATADIR}/System &&\
		${MV} -f glidedrv.int GlideDrv.int &&\
		${MV} -f softdrv.int SoftDrv.int &&\
		${MV} -f opengldrv.int OpenGlDrv.int &&\
		${MV} -f galaxy.int Galaxy.int &&\
		${MV} -f editor.int Editor.int &&\
		${MV} -f windrv.int WinDrv.int
	@${ECHO_CMD} "Setting permissions"
	@${FIND} ${DATADIR} -print0 |\
		${XARGS} -0 ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}
	@${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${NOBINMODE}
	@${FIND} ${DATADIR} \( -name "*.so" -o -name "lib*.so*" \) -print0 |\
		${XARGS} -0 ${CHMOD} ${BINMODE}
.for exec in ucc-bin ut-bin
	@${CHMOD} ${BINMODE} ${DATADIR}/System/${exec}
.endfor
	@${ECHO_CMD} "Install complete"

.include <bsd.port.mk>
