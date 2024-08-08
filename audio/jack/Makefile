PORTNAME=	jackit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.22
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	dev@submerge.ch
COMMENT=	Low latency audio server
WWW=		https://jackaudio.org/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate \
		libsysinfo.so:devel/libsysinfo

USES=		compiler:c11 pkgconfig python shebangfix waf
USE_LDCONFIG=	yes
USE_RC_SUBR=	jackd

USE_GITHUB=	yes
GH_ACCOUNT=	jackaudio
GH_PROJECT=	jack2

CFLAGS+=	-fPIC
CPPFLAGS+=	-I${LOCALBASE}/include

SHEBANG_FILES=	dbus/jack_control
SHEBANG_LANG=	python3

CONFIGURE_ARGS=	--celt=no --samplerate=yes

OPTIONS_DEFINE=		ALSA DBUS OPUS PROFILING SOSSO
OPTIONS_DEFAULT=	DBUS OPUS
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_OFF=	--alsa=no
ALSA_CONFIGURE_ON=	--alsa=yes

DBUS_CONFIGURE_ON=	--dbus --classic --autostart=dbus
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libexpat.so:textproc/expat2
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}

OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_CONFIGURE_ON=	--opus=yes
OPUS_CONFIGURE_OFF=	--opus=no

PROFILING_DESC=		Build with profiling information
PROFILING_CONFIGURE_ON=	--profile

# Let users test the new OSS driver backend coming in 1.9.23, see
# https://github.com/jackaudio/jack2/pull/943
SOSSO_DESC=		Build new OSS driver backend (sosso library)
SOSSO_GH_TAGNAME=	0762eac06a8c327757acfa7c770e16d827610873

TESTING_UNSAFE=	No function 'test' defined in ${WRKSRC}/wscript

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDBUS}
PLIST_SUB+=	CLASSIC="@comment "
.else
PLIST_SUB+=	CLASSIC=""
.endif

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
		lib/libjack*.so \
		lib/jack/*.so \
		$$(ls bin/* | ${GREP} -v jack_control)

.include <bsd.port.post.mk>
