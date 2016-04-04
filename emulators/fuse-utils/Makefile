# Created by: rene
# $FreeBSD$

PORTNAME=	fuse-utils
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	SF/fuse-emulator/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Utilities from the Free Unix Spectrum Emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig

LIB_DEPENDS=	libspectrum.so:emulators/libspectrum
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libspectrum-prefix=${LOCALBASE} \
		--with-local-prefix=${LOCALBASE}

OPTIONS_DEFINE=	AUDIOTOOLS DOCS
OPTIONS_DEFAULT=	AUDIOTOOLS

AUDIOTOOLS_DESC=	Build audio <-> tape utilities

OPTIONS_SUB=	yes

AUDIOTOOLS_CONFIGURE_WITH=	audiofile
AUDIOTOOLS_LIB_DEPENDS=		libaudiofile.so:audio/libaudiofile

# FIXME no way to specify ffmpeg1 paths to configure script
#FFMPEG_LIB_DEPENDS=	libavformat1.so:multimedia/ffmpeg1
#FFMPEG_CONFIGURE_WITH=	ffmpeg

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
