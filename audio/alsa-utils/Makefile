PORTNAME=	alsa-utils
PORTVERSION=	1.2.2
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	GH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ALSA compatibility utilities

LICENSE=	GPLv2+

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libepoll-shim.so:devel/libepoll-shim \
		libfftw3f.so:math/fftw3-float \
		libinotify.so:devel/libinotify
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins

USES=		autoreconf gettext-tools gmake libtool localbase ncurses shebangfix \
		tar:bzip2 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	alsa-project
GH_PROJECT=	${PORTNAME}
SHEBANG_FILES=	alsa-info/alsa-info.sh alsaconf/alsaconf.in bat/alsabat-test.sh

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-udev-rules-dir="\$${prefix}/lib/udev"
INSTALL_TARGET=	install-strip
CFLAGS+=	-Dlseek64=lseek -DSCHED_IDLE=SCHED_OTHER \
		-I${LOCALBASE}/include/libepoll-shim
CPPFLAGS+=	-I${.CURDIR}/../alsa-lib/files
LDFLAGS+=	-linotify -lepoll-shim

OPTIONS_DEFINE=		BAT MANPAGES NLS SAMPLERATE
OPTIONS_DEFAULT=	BAT MANPAGES
OPTIONS_SUB=		yes

BAT_DESC=		Basic Audio Tester support
BAT_LIB_DEPENDS=	libfftw3.so:math/fftw3 \
			libfftw3f.so:math/fftw3-float
BAT_CONFIGURE_ENABLE=	bat

MANPAGES_BUILD_DEPENDS=		minixmlto:textproc/minixmlto \
				rst2man:textproc/py-docutils
MANPAGES_CONFIGURE_ENABLE=	xmlto
MANPAGES_BINARY_ALIAS=		xmlto=minixmlto

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
NLS_LIBS=		-lintl

SAMPLERATE_LIB_DEPENDS=		libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_ENV_OFF=	ac_cv_header_samplerate_h=no

post-patch:
	@${REINPLACE_CMD} \
		's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/alsactl/alsactl_init.xml \
		${WRKSRC}/speaker-test/speaker-test.1 \
		${WRKSRC}/speaker-test/samples/sample_map.csv \
		${WRKSRC}/alsaconf/alsaconf.fr.8 \
		${WRKSRC}/alsaconf/alsaconf.8 \
		${WRKSRC}/utils/alsa-utils.spec.in \
		${WRKSRC}/amidi/amidi.1
	@${REINPLACE_CMD} \
		's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/alsa-info/alsa-info.sh.1 \
		${WRKSRC}/amidi/amidi.1

.include <bsd.port.mk>
