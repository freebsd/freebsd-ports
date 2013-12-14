# Created by: ijliao
# $FreeBSD$

PORTNAME=	libsndfile
PORTVERSION=	1.0.25
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/libsndfile/files/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF)

LICENSE=	LGPL21

USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gcc-pipe \
		--disable-sqlite \
		--disable-alsa \
		--disable-octave
CPPFLAGS+=	-isystem /usr/include -isystem ${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README libsndfile.css \
		new_file_type.HOWTO libsndfile.jpg *.html

OPTIONS_DEFINE=	CPU_CLIP EXTERNAL DOCS
OPTIONS_DEFAULT=	EXTERNAL
CPU_CLIP_DESC=	Allow machine-dependent clipping
EXTERNAL_DESC=	Enable FLAC and Ogg Vorbis support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCPU_CLIP}
MANUAL_PACKAGE_BUILD=	WITH_CPU_CLIP may customize the package for the build machine
.else
CONFIGURE_ARGS+=	--disable-cpu-clip
.endif

.if ${PORT_OPTIONS:MEXTERNAL}
LIB_DEPENDS+=	libFLAC.so:${PORTSDIR}/audio/flac \
		libvorbis.so:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=--disable-external-libs
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/ doc / /g' ${WRKSRC}/Makefile.in

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} \
	check

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${TAR} -C ${WRKSRC}/doc --exclude "*Makefile*" --exclude "*.in" \
		-cf - . | ${TAR} -C ${STAGEDIR}${DOCSDIR} --unlink -xf -

.include <bsd.port.mk>
