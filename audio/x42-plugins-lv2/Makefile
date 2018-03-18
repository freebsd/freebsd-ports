# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	x42-plugins
PORTVERSION=	20170428
CATEGORIES=	audio
MASTER_SITES=	http://gareus.org/misc/x42-plugins/
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of LV2 plugins (submodules)

BROKEN_aarch64=		fails to compile: unknown FP unit 'sse'
BROKEN_armv6=		fails to compile: unknown FP unit 'sse'
BROKEN_armv7=		fails to compile: unknown FP unit 'sse'
BROKEN_mips64=		fails to compile: unknown FP unit 'sse'

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/fftw3.h:math/fftw3 \
		bash:shells/bash
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		liblo.so:audio/liblo \
		libltc.so:audio/libltc \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libzita-convolver.so:audio/zita-convolver

USES=		gmake localbase pkgconfig tar:xz shebangfix
USE_GNOME=	glib20 pango cairo
USE_XORG=	x11
USE_GL=		glu gl
MAKE_ENV=	BUILDOPENGL=yes BUILDGTK=no LV2DIR=${PREFIX}/lib/lv2 MANDIR=${PREFIX}/man/man1
SHEBANG_FILES=	stepseq.lv2/gridgen.sh

post-patch:
	${REINPLACE_CMD} 's/__APPLE__/__FreeBSD__/' \
		${WRKSRC}/tuna.lv2/src/spectr.c \
		${WRKSRC}/meters.lv2/src/spectr.c
	${REINPLACE_CMD} 's|$$(mandir)/man1|$$(MANDIR)|' \
		${WRKSRC}/sisco.lv2/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/convo.lv2/convoLV2.so

.include <bsd.port.mk>
