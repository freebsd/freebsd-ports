# Created by: rene
# $FreeBSD$

PORTNAME=	fuse-utils
PORTVERSION=	1.2.0
CATEGORIES=	emulators
MASTER_SITES=	SF/fuse-emulator/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Utilities from the Free Unix Spectrum Emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		libgcrypt.so:security/libgcrypt \
		libspectrum.so:emulators/libspectrum

USES=		gettext iconv pkgconfig
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libspectrum-prefix=${LOCALBASE} \
		--with-local-prefix=${LOCALBASE}

# FIXME no way to specify ffmpeg1 paths to configure script
#FFMPEG_LIB_DEPENDS=	libavformat1.so:multimedia/ffmpeg1
#FFMPEG_CONFIGURE_WITH=	ffmpeg

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
