# $FreeBSD$

PORTNAME=	pulseeffects
DISTVERSIONPREFIX=	v
DISTVERSION=	4.6.8
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	daniel@shafer.cc
COMMENT=	Audio effects for Pulseaudio applications

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gstreamer1>=1.4.0:multimedia/py-gstreamer1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		appstream-glib>0:devel/appstream-glib \
		itstool>0:textproc/itstool
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libbs2b.so:audio/libbs2b \
		libdbus-1.so:devel/dbus \
		libebur128.so:audio/libebur128 \
		liblilv-0.so:audio/lilv \
		libpulse.so:audio/pulseaudio \
		librubberband.so:audio/rubberband \
		libsamplerate.so:audio/libsamplerate \
		libserd-0.so:devel/serd \
		libsndfile.so:audio/libsndfile \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom \
		libzita-convolver.so:audio/zita-convolver
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gstreamer1>=1.4.0:multimedia/py-gstreamer1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		calf-lv2>0:audio/calf-lv2 \
		ladspa>0:audio/ladspa \
		lsp-plugins-lv2>0:audio/lsp-plugins-lv2 \
		mda-lv2>0:audio/mda-lv2 \
		zam-plugins-lv2>0:audio/zam-plugins-lv2

USES=		compiler:c++17-lang desktop-file-utils libtool \
		localbase:ldflags gettext gnome meson ninja pathfix pkgconfig \
		python:3.6+ shebangfix
USE_GNOME=	cairo gconf2 gtkmm30 libsigc++20 pygobject3
USE_GSTREAMER1=	bad bs2b good ladspa lv2 pulse webrtcdsp
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	wwmm

GLIB_SCHEMAS=	com.github.wwmm.pulseeffects.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.autogain.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.bassenhancer.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.compressor.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.convolver.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.crossfeed.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.crystalizer.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.deesser.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.delay.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.equalizer.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.equalizer.leftchannel.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.equalizer.rightchannel.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.exciter.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.filter.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.gate.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.limiter.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.loudness.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.maximizer.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.multibandcompressor.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.multibandgate.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.pitch.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.reverb.gschema.xml \
		com.github.wwmm.pulseeffects.sinkinputs.stereotools.gschema.xml \
		com.github.wwmm.pulseeffects.sourceoutputs.compressor.gschema.xml \
		com.github.wwmm.pulseeffects.sourceoutputs.deesser.gschema.xml \
		com.github.wwmm.pulseeffects.sourceoutputs.equalizer.gschema.xml \
		com.github.wwmm.pulseeffects.sourceoutputs.equalizer.leftchannel.gschema.xml \
		com.github.wwmm.pulseeffects.sourceoutputs.equalizer.rightchannel.gschema.xml \
		com.github.wwmm.pulseeffects.sourceoutputs.filter.gschema.xml \
		com.github.wwmm.pulseeffects.sourceoutputs.gate.gschema.xml \
		com.github.wwmm.pulseeffects.sourceoutputs.gschema.xml \
		com.github.wwmm.pulseeffects.sourceoutputs.limiter.gschema.xml \
		com.github.wwmm.pulseeffects.sourceoutputs.multibandcompressor.gschema.xml \
		com.github.wwmm.pulseeffects.sourceoutputs.multibandgate.gschema.xml \
		com.github.wwmm.pulseeffects.sourceoutputs.pitch.gschema.xml \
		com.github.wwmm.pulseeffects.sourceoutputs.reverb.gschema.xml \
		com.github.wwmm.pulseeffects.sourceoutputs.webrtc.gschema.xml \
		com.github.wwmm.pulseeffects.spectrum.gschema.xml

INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	meson_post_install.py

HELP_LANGS=	it_IT pt_BR ru
HELP_PNGS=	advancedinfo.png blacklist.png effectsorder.png enableapp.png \
		saturated.png settingsmenu.png userpresets.png

post-install:
# Fixes symlink warnings in stage-qa
.for x in ${HELP_LANGS}
.for f in ${HELP_PNGS}
	@${RLN} ${STAGEDIR}${PREFIX}/share/help/C/pulseeffects/figures/${f} \
		${STAGEDIR}${PREFIX}/share/help/${x}/pulseeffects/figures/${f}
.endfor
.endfor

.include <bsd.port.mk>
