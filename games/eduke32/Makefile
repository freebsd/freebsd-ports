# Created by: alepulver
# $FreeBSD$

PORTNAME=	eduke32
PORTVERSION=	20160103
CATEGORIES=	games
MASTER_SITES=	http://dukeworld.duke4.net/eduke32/synthesis/${PORTVERSION}-${SVNREVISION}/:eduke32
DISTFILES=	${PORTNAME}_src_${PORTVERSION}-${SVNREVISION}${EXTRACT_SUFX}:eduke32
EXTRACT_ONLY=	${PORTNAME}_src_${PORTVERSION}-${SVNREVISION}${EXTRACT_SUFX}

MAINTAINER=	pkubaj@riseup.net
COMMENT=	Duke Nukem 3D Port based on JFDuke and EDuke

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/source/gpl-2.0.txt

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libvpx.so:multimedia/libvpx

USES=		execinfo gmake tar:xz
USE_GCC=	any
USE_GL=		gl glu
USE_GNOME=	gtk20
USE_SDL=	sdl2 mixer2
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}-${SVNREVISION}
SVNREVISION=	5506
DATADIR=	${LOCALBASE}/share/duke3d
SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR}

PLIST_FILES=	bin/eduke32 bin/mapster32
PORTDOCS=	*
PORTEXAMPLES=	*

BROKEN_sparc64=	does not compile on sparc64

OPTIONS_DEFINE=	DOCS EXAMPLES HRP OFFENSIVE SHAREWARE
OPTIONS_RADIO=	MIDI
OPTIONS_RADIO_MIDI=	TIMIDITY TIMIDITYPLUS
OPTIONS_DEFAULT=TIMIDITY
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_i386=	ASM

ASM_BUILD_DEPENDS=	nasm:devel/nasm
HRP_DESC=	Install High Resolution Pack
MIDI_DESC=	MIDI music support
OFFENSIVE_DESC=	Install full XXX Pack
OFFENSIVE_IMPLIES=	HRP
SHAREWARE_DESC=	Install shareware game data version 1.3
TIMIDITY_DESC=	Use Timidity for music support
TIMIDITY_RUN_DEPENDS=	timidity:audio/timidity
TIMIDITYPLUS_DESC=	Use Timidity++ for music support
TIMIDITYPLUS_RUN_DEPENDS=	timidity:audio/timidity++

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHRP}
DISTFILES+=	duke3d_hrp.zip:hrp
PLIST_SUB+=	HRP=""
PLIST_FILES+=	${DATADIR}/duke3d_hrp.zip
MASTER_SITES+=	http://www.duke4.org/files/nightfright/hrp/:hrp
.else
PLIST_SUB+=	HRP="@comment "
.endif

.if ${PORT_OPTIONS:MOFFENSIVE}
DISTFILES+=	duke3d_xxx.zip:xxx
PLIST_SUB+=	OFFENSIVE=""
PLIST_FILES+=	 ${DATADIR}/duke3d_xxx.zip
MASTER_SITES+=	http://www.duke4.org/files/nightfright/:xxx
.else
PLIST_SUB+=	XXX="@comment "
.endif

.if ${PORT_OPTIONS:MSHAREWARE}
EXTRACT_ONLY+=	3dduke13.zip
DISTFILES+=	3dduke13.zip:shareware
PLIST_SUB+=	SHAREWARE=""
PLIST_FILES+=	${DATADIR}/duke3d.grp
MASTER_SITES+=	ftp://ftp.3drealms.com/share/:shareware
.else
PLIST_SUB+=	SHAREWARE="@comment "
.endif

post-extract-SHAREWARE-on:
	@cd ${WRKDIR} && ${UNZIP_NATIVE_CMD} -qo DN3DSW13.SHR

post-patch:
	@${REINPLACE_CMD} -e '/^CC=/s|gcc|${CC}|' -e '/^CXX=/s|g++|${CXX}|' \
		${WRKSRC}/Makefile.common
	@${REINPLACE_CMD} 's|/usr/share/games/eduke32|${DN3DDIR}|' \
		${WRKSRC}/source/game.c ${WRKSRC}/source/astub.c

post-patch-ASM-off:
	@${REINPLACE_CMD} '/^NOASM =/s/0/1/' ${WRKSRC}/Makefile.common

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eduke32 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mapster32 ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/package/sdk/samples/*.sample ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/package/sdk/samples/*.map ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/package/sdk/samples/*.m32 ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/package/sdk/*.cfg ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/package/sdk/samples/*.txt ${STAGEDIR}${EXAMPLESDIR}

do-install-HRP-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/duke3d_hrp.zip ${STAGEDIR}${DATADIR}/duke3d_hrp.zip

do-install-OFFENSIVE-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/duke3d_xxx.zip ${STAGEDIR}${DATADIR}/duke3d_xxx.zip

do-install-SHAREWARE-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/DUKE3D.GRP ${STAGEDIR}${DATADIR}/duke3d.grp

.include <bsd.port.mk>
