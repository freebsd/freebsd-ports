PORTNAME=	eduke32
PORTVERSION=	20260807
CATEGORIES=	games
MASTER_SITES=	http://dukeworld.com/eduke32/synthesis/${PORTVERSION}-${GITREVISION}/:eduke32 \
		LOCAL/pkubaj/:erp \
		http://www.duke4.org/files/nightfright/related/:related \
		http://dukeworld.com/classic%20dukeworld/share/:shareware \
		https://image.dosgamesarchive.com/games/:shareware \
		https://www.quaddicted.com/files/idgames2/planetquake/planetduke/:shareware \
		https://ftp.swin.edu.au/gentoo/distfiles/:shareware \
		ftp://ftp.3drealms.com/share/:shareware
DISTFILES=	${PORTNAME}_src_${PORTVERSION}-${GITREVISION}${EXTRACT_SUFX}:eduke32
EXTRACT_ONLY=	${PORTNAME}_src_${PORTVERSION}-${GITREVISION}${EXTRACT_SUFX}

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Duke Nukem 3D Port based on JFDuke and EDuke
WWW=		https://eduke32.com/

LICENSE=	GPLv2 BUILDLIC
LICENSE_COMB=	multi
LICENSE_NAME_BUILDLIC=	BUILD SOURCE CODE LICENSE
LICENSE_FILE_BUILDLIC=	${WRKSRC}/source/build/buildlic.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/source/duke3d/gpl-2.0.txt
LICENSE_PERMS_BUILDLIC=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libvpx.so:multimedia/libvpx

USES=		compiler:c11 dos2unix gl gmake gnome localbase pkgconfig sdl tar:xz
USE_GL=		gl glu
USE_GNOME=	gdkpixbufextra gtk20
USE_SDL=	sdl2
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}-${GITREVISION}
GITREVISION=	10669-ec5824db8
DATADIR=	${PREFIX}/share/duke3d
SUB_FILES=	pkg-message
MAKEFILE=	GNUmakefile
MAKE_ARGS=	CC=${CC} CXX=${CXX} CLANG=1 PRETTY_OUTPUT=0 USE_MIMALLOC=0
ALL_TARGET=	duke3d

PLIST_FILES=	bin/eduke32 bin/mapster32
PORTEXAMPLES=	*

OPTIONS_DEFINE=		ERP EXAMPLES FURY OFFENSIVE SW
OPTIONS_DEFAULT=	FURY SW
OPTIONS_RADIO=		GAMEDATA
OPTIONS_RADIO_GAMEDATA=	SHAREWARE FULL

ERP_DESC=		Install Enhanced Resource Pack
ERP_DISTFILES=		duke-erp-210701.zip:erp
ERP_PLIST_FILES=	${DATADIR}/duke-erp-210701.zip
FURY_DESC=		Build Ion Fury engine (game data not included)
FURY_PLIST_FILES=	bin/fury
OFFENSIVE_DESC=		Install Full XXX Pack
OFFENSIVE_IMPLIES=	ERP
OFFENSIVE_DISTFILES=	duke3d_xxx.zip:related
OFFENSIVE_PLIST_FILES=	${DATADIR}/duke3d_xxx.zip
SHAREWARE_DESC=		Install shareware game data version 1.3
SHAREWARE_EXTRACT_ONLY=	3dduke13.zip
SHAREWARE_DISTFILES=	3dduke13.zip:shareware
SHAREWARE_PLIST_FILES=	${DATADIR}/duke3d.grp ${DATADIR}/duke.rts
FULL_DESC=		Install duke3d.grp and duke.rts from $${DISTDIR}/duke3d
FULL_DISTFILES=		duke3d/duke3d.grp duke3d/duke.rts
FULL_PLIST_FILES=	${DATADIR}/duke3d.grp ${DATADIR}/duke.rts
SW_DESC=		Build VoidSW (Shadow Warrior) and Wangulator editor
SW_ALL_TARGET=		sw
SW_PLIST_FILES=		bin/voidsw bin/wangulator

.include <bsd.port.options.mk>

.if ${ARCH} == i386
BUILD_DEPENDS+=	nasm:devel/nasm
.elif ${ARCH} == riscv64
MAKE_ARGS+=	LTO=0
.endif

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

post-extract-SHAREWARE-on:
	@cd ${WRKDIR} && ${UNZIP_NATIVE_CMD} -qo DN3DSW13.SHR

post-patch:
	@${REINPLACE_CMD} \
		-e 's|"/usr/local/share/games/" APPBASENAME|"${DATADIR}"|' \
		-e 's|"/usr/share/games/" APPBASENAME|"${PREFIX}/share/" APPBASENAME|' \
		${WRKSRC}/source/duke3d/src/common.cpp
	@${REINPLACE_CMD} 's|/usr/local/share/games/|${PREFIX}/share/|' \
		${WRKSRC}/source/sw/src/common.cpp

# Ion Fury is a build profile of the Duke3D game with different engine
# features compiled in, so it needs its own object directory.
post-build-FURY-on:
	@(cd ${BUILD_WRKSRC}; ${DO_MAKE_BUILD} FURY=1 SDL_STATIC=0 obj=obj-fury fury)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eduke32 ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/mapster32 ${STAGEDIR}${PREFIX}/bin/

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/package/sdk/tiles.cfg ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/package/sdk/samples/* ${STAGEDIR}${EXAMPLESDIR}/

do-install-ERP-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/duke-erp-210701.zip ${STAGEDIR}${DATADIR}/

do-install-FURY-on:
	${INSTALL_PROGRAM} ${WRKSRC}/fury ${STAGEDIR}${PREFIX}/bin/

do-install-OFFENSIVE-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/duke3d_xxx.zip ${STAGEDIR}${DATADIR}/

do-install-SHAREWARE-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/DUKE3D.GRP ${STAGEDIR}${DATADIR}/duke3d.grp
	${INSTALL_DATA} ${WRKDIR}/DUKE.RTS ${STAGEDIR}${DATADIR}/duke.rts

do-install-FULL-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/duke3d/duke3d.grp ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${DISTDIR}/duke3d/duke.rts ${STAGEDIR}${DATADIR}/

do-install-SW-on:
	${INSTALL_PROGRAM} ${WRKSRC}/voidsw ${WRKSRC}/wangulator \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
