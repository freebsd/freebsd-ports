# Created by: ijliao
# $FreeBSD$

PORTNAME=	libsndfile
PORTVERSION=	1.0.28
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/libsndfile/files/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF)

LICENSE=	LGPL21

USES=		cpe gmake libtool localbase pkgconfig
CPE_VENDOR=	${CPE_PRODUCT}_project
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gcc-pipe \
		--disable-sqlite \
		--disable-alsa \
		--disable-octave \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
USE_LDCONFIG=	yes
TEST_TARGET=	check
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	CPU_CLIP EXTERNAL DOCS
OPTIONS_DEFAULT=	EXTERNAL
CPU_CLIP_DESC=	Allow machine-dependent clipping
EXTERNAL_DESC=	Enable FLAC and Ogg Vorbis support

CPU_CLIP_VARS=	MANUAL_PACKAGE_BUILD="WITH_CPU_CLIP may customize the package for the build machine"
CPU_CLIP_CONFIGURE_OFF=	--disable-cpu-clip

EXTERNAL_LIB_DEPENDS=	libFLAC.so:audio/flac \
			libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis
EXTERNAL_CONFIGURE_OFF=	--disable-external-libs

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/ doc / /g' ${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${TAR} -C ${WRKSRC}/doc --exclude "*Makefile*" --exclude "*.in" \
		-cf - . | ${TAR} -C ${STAGEDIR}${DOCSDIR} --unlink -xf -

.include <bsd.port.mk>
