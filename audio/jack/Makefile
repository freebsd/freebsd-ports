PORTNAME=	jackit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.22
PORTREVISION=	3
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/

MAINTAINER=	dev@submerge.ch
COMMENT=	Low latency audio server
WWW=		https://jackaudio.org/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate \
		libsysinfo.so:devel/libsysinfo

USES=		compiler:c11 localbase pkgconfig python shebangfix waf

USE_GITHUB=	yes
GH_ACCOUNT=	jackaudio
GH_PROJECT=	jack2

USE_LDCONFIG=	yes
USE_RC_SUBR=	jackd

SHEBANG_FILES=	dbus/jack_control
SHEBANG_LANG=	python3

CONFIGURE_ARGS=	--celt=no --samplerate=yes
CFLAGS+=	-fPIC
TESTING_UNSAFE=	No function 'test' defined in ${WRKSRC}/wscript

OPTIONS_DEFINE=		ALSA DBUS OPUS PROFILING SOSSO
OPTIONS_DEFAULT=	DBUS OPUS
OPTIONS_SUB=		yes

PROFILING_DESC=	Build with profiling information
SOSSO_DESC=	Build new OSS driver backend (sosso library)

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ON=	--alsa=yes
ALSA_CONFIGURE_OFF=	--alsa=no

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libexpat.so:textproc/expat2
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}
DBUS_CONFIGURE_ON=	--dbus --classic --autostart=dbus

OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_CONFIGURE_ON=	--opus=yes
OPUS_CONFIGURE_OFF=	--opus=no

PROFILING_CONFIGURE_ON=	--profile

# Let users test the new OSS driver backend coming in 1.9.23, see
# https://github.com/jackaudio/jack2/pull/943
SOSSO_PATCHFILES_OFF=	250420381b1a6974798939ad7104ab1a4b9a9994.patch:-p1
SOSSO_GH_TAGNAME=	0762eac06a8c327757acfa7c770e16d827610873

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
		lib/libjack*.so \
		lib/jack/*.so \
		$$(ls bin/* | ${GREP} -v jack_control)

.include <bsd.port.mk>
