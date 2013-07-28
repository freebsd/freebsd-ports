# Created by: rene
# $FreeBSD$

PORTNAME=	fuse-utils
PORTVERSION=	1.1.1
CATEGORIES=	emulators
MASTER_SITES=	SF/fuse-emulator/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Utilities from the Free Unix Spectrum Emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig

LIB_DEPENDS=	spectrum:${PORTSDIR}/emulators/libspectrum
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libspectrum-prefix=${LOCALBASE} \
		--with-local-prefix=${LOCALBASE}

MAN1=	createhdf.1 fmfconv.1 fuse-utils.1 listbasic.1 raw2hdf.1 rzxcheck.1 \
	rzxdump.1 rzxtool.1 scl2trd.1 snap2tzx.1 snapconv.1 tapeconv.1 \
	tzxlist.1 profile2map.1

OPTIONS_DEFINE=	AUDIOTOOLS DOCS
OPTIONS_DEFAULT=	AUDIOTOOLS

AUDIOTOOLS_DESC=	Build audio <-> tape utilities

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAUDIOTOOLS}
CONFIGURE_ARGS+=--with-audiofile
LIB_DEPENDS+=	audiofile:${PORTSDIR}/audio/libaudiofile
PLIST_SUB=	AUDIOTOOLS=""
MAN1+=		audio2tape.1 tape2wav.1
.else
CONFIGURE_ARGS+=--without-audiofile
PLIST_SUB=	AUDIOTOOLS="@comment "
.endif

# FIXME no way to specify ffmpeg1 paths to configure script
#.if ${PORT_OPTIONS:MFFMPEG}
#LIB_DEPENDS+=	avformat1:${PORTSDIR}/multimedia/ffmpeg1
#CONFIGURE_ARGS+=--with-ffmpeg
#.else
CONFIGURE_ARGS+=--without-ffmpeg
#.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README ${DOCSDIR}
.endif

.include <bsd.port.mk>
