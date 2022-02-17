# Created by: alepulver

PORTNAME=	eduke32
PORTVERSION=	20220204
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

USES=		compiler:c11 dos2unix gl gmake gnome localbase pkgconfig sdl tar:xz
USE_GL=		gl glu
USE_GNOME=	gtk20
USE_SDL=	sdl2 mixer2
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}-${GITREVISION}
GITREVISION=	9957-6df591a07
DATADIR=	${PREFIX}/share/duke3d
SUB_FILES=	pkg-message
MAKEFILE=	GNUmakefile
MAKE_ARGS=	CC=${CC} CXX=${CXX}

PLIST_FILES=	bin/eduke32 bin/mapster32
PORTEXAMPLES=	*

OPTIONS_DEFINE=		ERP EXAMPLES OFFENSIVE
OPTIONS_RADIO=		GAMEDATA
OPTIONS_RADIO_GAMEDATA=	SHAREWARE FULL
OPTIONS_DEFINE_amd64=	ASM
OPTIONS_DEFAULT_amd64=	ASM
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_i386=	ASM

ASM_BUILD_DEPENDS=	nasm:devel/nasm
ASM_MAKE_ARGS_OFF=	NOASM=1
ERP_DESC=		Install Enhanced Resource Pack
ERP_DISTFILES=		duke-erp-210701.zip:erp
ERP_PLIST_FILES=	${DATADIR}/duke-erp-210701.zip
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

.include <bsd.port.options.mk>

.if ${ARCH} == i386 || ${ARCH} == powerpc64 || ${ARCH} == riscv64
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
	@${REINPLACE_CMD} 's|/usr/share/games/eduke32|${DATADIR}|' \
		${WRKSRC}/source/duke3d/src/common.cpp

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

.include <bsd.port.mk>
