PORTNAME=	spectmorph
DISTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://spectmorph.org/files/releases/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Analyze and combine samples of musical instruments

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	error: unknown type name '__m128'
BROKEN_armv7=	error: unknown type name '__m128'

BUILD_DEPENDS=	fftw3>0:math/fftw3
LIB_DEPENDS=	libao.so:audio/libao \
		libfftw3f.so:math/fftw3-float \
		libfreetype.so:print/freetype2 \
		libsndfile.so:audio/libsndfile

USES=		autoreconf desktop-file-utils gettext-runtime gl gmake gnome libtool pkgconfig python:run qt:5 shebangfix tar:bz2 xorg
USE_QT=		core gui widgets buildtools_build
USE_GNOME=	cairo glib20
USE_GL=		gl
USE_XORG=	x11
USE_LDCONFIG=	yes

SHEBANG_FILES=	tools/sminstbuilder.in

GNU_CONFIGURE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib -lfftw3f_threads

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		JACK LV2
OPTIONS_DEFAULT=	JACK LV2
OPTIONS_SUB=		yes

JACK_CONFIGURE_WITH=	jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack

LV2_DESC=		Build the LV2 plugin
LV2_CONFIGURE_WITH=	lv2
LV2_BUILD_DEPENDS=	lv2>0:audio/lv2

.include <bsd.port.mk>
