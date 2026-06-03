PORTNAME=	audiowmark
DISTVERSION=	0.6.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://github.com/swesterfeld/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Audio and video watermarking tool
WWW=		https://github.com/swesterfeld/audiowmark

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libmpg123.so:audio/mpg123 \
		libsndfile.so:audio/libsndfile \
		libzita-resampler.so:audio/zita-resampler

USES=		compiler:c++14-lang gettext-tools libtool localbase:ldflags \
		pkgconfig shebangfix tar:zst
SHEBANG_FILES=	src/videowmark

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/audiowmark \
		bin/videowmark
PORTDOCS=	README.adoc

OPTIONS_DEFINE=		DOCS FFMPEG
OPTIONS_DEFAULT=	FFMPEG

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ON=	--with-ffmpeg

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.adoc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
