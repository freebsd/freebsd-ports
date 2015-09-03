# Created by: alepulver
# $FreeBSD$

PORTNAME=	eduke32
PORTVERSION=	20150830
CATEGORIES=	games
MASTER_SITES=	http://dukeworld.duke4.net/eduke32/synthesis/${PORTVERSION}-${SVNREVISION}/ \
		http://dukeworld.duke4.net/eduke32/synthesis/old/${PORTVERSION}-${SVNREVISION}/
DISTNAME=	${PORTNAME}_src_${PORTVERSION}-${SVNREVISION}

MAINTAINER=	pkubaj@riseup.net
COMMENT=	Duke Nukem 3D Port based on JFDuke and EDuke

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/source/gpl-2.0.txt

LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libogg.so:${PORTSDIR}/audio/libogg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libvpx.so:${PORTSDIR}/multimedia/libvpx

USES=		execinfo gmake tar:xz
USE_GCC=	any
USE_GL=		gl glu
USE_GNOME=	gtk20
USE_SDL=	sdl2 mixer2
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}-${SVNREVISION}
SVNREVISION=	5338

PLIST_FILES=	bin/eduke32 bin/mapster32
PORTDOCS=	*
PORTEXAMPLES=	*

BROKEN_sparc64=	does not compile on sparc64

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_RADIO=	MIDI
OPTIONS_RADIO_MIDI=	TIMIDITY TIMIDITYPLUS
OPTIONS_DEFAULT=TIMIDITY
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_i386=	ASM

ASM_BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
MIDI_DESC=	MIDI music support
TIMIDITY_DESC=	Use Timidity for music support
TIMIDITY_RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity
TIMIDITYPLUS_DESC=	Use Timidity++ for music support
TIMIDITYPLUS_RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity++

.include "${.CURDIR}/../duke3d-data/Makefile.include"

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

.include <bsd.port.mk>
