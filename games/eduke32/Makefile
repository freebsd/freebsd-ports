# Created by: alepulver
# $FreeBSD$

PORTNAME=	eduke32
PORTVERSION=	20200404
CATEGORIES=	games
MASTER_SITES=	http://dukeworld.duke4.net/eduke32/synthesis/${PORTVERSION}-${SVNREVISION}/:eduke32 \
		http://www.duke4.org/files/nightfright/hrp/:hrp \
		http://burnbit.com/download/447717/:hrp \
		http://www.duke4.org/files/nightfright/related/:related \
		http://dukeworld.duke4.net/classic%20dukeworld/share/:shareware \
		https://image.dosgamesarchive.com/games/:shareware \
		https://www.quaddicted.com/files/idgames2/planetquake/planetduke/:shareware \
		https://ftp.swin.edu.au/gentoo/distfiles/:shareware \
		ftp://ftp.3drealms.com/share/:shareware \
		https://anongoth.pl/:voxel
DISTFILES=	${PORTNAME}_src_${PORTVERSION}-${SVNREVISION}${EXTRACT_SUFX}:eduke32
EXTRACT_ONLY=	${PORTNAME}_src_${PORTVERSION}-${SVNREVISION}${EXTRACT_SUFX}

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Duke Nukem 3D Port based on JFDuke and EDuke

LICENSE=	GPLv2 BUILDLIC
LICENSE_COMB=	multi
LICENSE_NAME_BUILDLIC=	BUILD SOURCE CODE LICENSE
LICENSE_FILE_BUILDLIC=	${WRKSRC}/source/build/buildlic.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/source/duke3d/gpl-2.0.txt
LICENSE_PERMS_BUILDLIC=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libvpx.so:multimedia/libvpx \
		libpng.so:graphics/png

USES=		dos2unix gl gmake gnome pkgconfig sdl tar:xz
USE_GL=		gl glu
USE_GNOME=	gtk20
USE_SDL=	sdl2 mixer2
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}-${SVNREVISION}
SVNREVISION=	8798
DATADIR=	${PREFIX}/share/duke3d
SUB_FILES=	pkg-message
MAKEFILE=	GNUmakefile
MAKE_ARGS=	CC=${CC} CXX=${CXX}

PLIST_FILES=	bin/eduke32 bin/mapster32
PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES GCC HRP OFFENSIVE VOXEL
OPTIONS_RADIO=		GAMEDATA
OPTIONS_RADIO_GAMEDATA=	SHAREWARE FULL
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_i386=	ASM
OPTIONS_DEFAULT_amd64=	GCC
OPTIONS_DEFAULT_powerpc=	GCC
OPTIONS_DEFAULT_powerpcspe=	GCC
OPTIONS_DEFAULT_powerpc64=	GCC
OPTIONS_DEFAULT_sparc64=	GCC

ASM_BUILD_DEPENDS=	nasm:devel/nasm
ASM_MAKE_ARGS_OFF=	NOASM=1
GCC_MAKE_ARGS_OFF=	CLANG=1 LTO=0
GCC_USE=		gcc=yes
HRP_DESC=		Install High Resolution Pack
HRP_DISTFILES=		duke3d_hrp.zip:hrp
HRP_PLIST_FILES=	${DATADIR}/duke3d_hrp.zip
OFFENSIVE_DESC=		Install Full XXX Pack
OFFENSIVE_IMPLIES=	HRP
OFFENSIVE_DISTFILES=	duke3d_xxx.zip:related
OFFENSIVE_PLIST_FILES=	${DATADIR}/duke3d_xxx.zip
SHAREWARE_DESC=		Install shareware game data version 1.3
SHAREWARE_EXTRACT_ONLY=	3dduke13.zip
SHAREWARE_DISTFILES=	3dduke13.zip:shareware
SHAREWARE_PLIST_FILES=	${DATADIR}/duke3d.grp ${DATADIR}/duke.rts
VOXEL_DESC=		Install Voxel Pack
VOXEL_DISTFILES=	duke3d_voxels.zip:voxel
VOXEL_PLIST_FILES=	${DATADIR}/duke3d_voxels.zip
FULL_DESC=		Install duke3d.grp and duke.rts from $${DISTDIR}/duke3d
FULL_DISTFILES=		duke3d/duke3d.grp duke3d/duke.rts
FULL_PLIST_FILES=	${DATADIR}/duke3d.grp ${DATADIR}/duke.rts

post-extract-SHAREWARE-on:
	@cd ${WRKDIR} && ${UNZIP_NATIVE_CMD} -qo DN3DSW13.SHR

post-patch:
	@${REINPLACE_CMD} 's|/usr/share/games/eduke32|${DATADIR}|' \
		${WRKSRC}/source/duke3d/src/common.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eduke32 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mapster32 ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/package/sdk/tiles.cfg ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/package/sdk/samples/* ${STAGEDIR}${EXAMPLESDIR}

do-install-HRP-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/duke3d_hrp.zip ${STAGEDIR}${DATADIR}/duke3d_hrp.zip

do-install-OFFENSIVE-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/duke3d_xxx.zip ${STAGEDIR}${DATADIR}/duke3d_xxx.zip

do-install-SHAREWARE-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/DUKE3D.GRP ${STAGEDIR}${DATADIR}/duke3d.grp
	${INSTALL_DATA} ${WRKDIR}/DUKE.RTS ${STAGEDIR}${DATADIR}/duke.rts

do-install-VOXEL-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/duke3d_voxels.zip ${STAGEDIR}${DATADIR}/duke3d_voxels.zip

do-install-FULL-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/duke3d/duke3d.grp ${STAGEDIR}${DATADIR}/duke3d.grp
	${INSTALL_DATA} ${DISTDIR}/duke3d/duke.rts ${STAGEDIR}${DATADIR}/duke.rts

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFULL}

# Avoid checksumming original (commercial) game data files: A variety of
# editions exist with the same file names and they should all work.
# This is a hack that would break when bsd.port.mk changes or DIST_SUBDIR
# is set.
_CKSUMFILES=	${ALLFILES:Nduke3d/duke*}

.if !exists(${DISTDIR}/duke3d/duke3d.grp) || !exists(${DISTDIR}/duke3d/duke.rts)
IGNORE=	option FULL selected, but duke3d.grp or duke.rts not found in ${DISTDIR}/duke3d
.endif

.endif

.include <bsd.port.mk>
