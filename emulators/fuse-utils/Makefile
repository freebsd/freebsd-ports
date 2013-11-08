# Created by: rene
# $FreeBSD$

PORTNAME=	fuse-utils
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/fuse-emulator/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Utilities from the Free Unix Spectrum Emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig

LIB_DEPENDS=	libspectrum.so:${PORTSDIR}/emulators/libspectrum
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libspectrum-prefix=${LOCALBASE} \
		--with-local-prefix=${LOCALBASE}

OPTIONS_DEFINE=	AUDIOTOOLS DOCS
OPTIONS_DEFAULT=	AUDIOTOOLS

AUDIOTOOLS_DESC=	Build audio <-> tape utilities

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAUDIOTOOLS}
CONFIGURE_ARGS+=--with-audiofile
LIB_DEPENDS+=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile
PLIST_SUB=	AUDIOTOOLS=""
.else
CONFIGURE_ARGS+=--without-audiofile
PLIST_SUB=	AUDIOTOOLS="@comment "
.endif

# FIXME no way to specify ffmpeg1 paths to configure script
#.if ${PORT_OPTIONS:MFFMPEG}
#LIB_DEPENDS+=	libavformat1.so:${PORTSDIR}/multimedia/ffmpeg1
#CONFIGURE_ARGS+=--with-ffmpeg
#.else
CONFIGURE_ARGS+=--without-ffmpeg
#.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
