PORTNAME=	neuralrack
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0-2
DISTVERSIONSUFFIX=	-gaa4278e
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	NeuralRack is a Neural Model and Impulse Response File loader
WWW=		https://github.com/brummer10/NeuralRack

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		xxd:sysutils/xxd
LIB_DEPENDS=	libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile

USES=		compiler:c++20-lang gmake gnome localbase pkgconfig xorg
USE_GNOME=	cairo
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_TUPLE=	\
		brummer10:libxputty:3f41e69:brummer10_libxputty/libxputty \
		HiFi-LoFi:FFTConvolver:f2cdeb04c42141d2caec19ca4f137398b2a76b85:HiFi_LoFi_FFTConvolver/FFTConvolver \
		mikeoliphant:NeuralAudio:02b6f79:neural_audio/NeuralAudio \
			mikeoliphant:RTNeural:5909c44:RTNeural/NeuralAudio/deps/RTNeural \
				xtensor-stack:xsimd:a00c81f7b9e808a42aedcf7da2fbb1f9a636da34:xtensor_stack_xsimd/NeuralAudio/deps/RTNeural/modules/xsimd \
			mikeoliphant:NeuralAmpModelerCore:e181f61efb8d05d34add45b5eecb3893ff21177c:NeuralAmpModelerCore/NeuralAudio/deps/NeuralAmpModelerCore \
			Chowdhury-DSP:math_approx:f6d55e7:math_approx/NeuralAudio/deps/math_approx

#WRKSRC=		${WRKDIR}/NeuralRack-${PORTVERSION}
WRKSRC=		${WRKDIR}/NeuralRack-${DISTVERSION}${DISTVERSIONSUFFIX}

MAKEFILE=	makefile

CXXFLAGS+=	-I${WRKSRC}/NeuralAudio/deps/RTNeural/modules/Eigen

BUILD_CONFLICTS=	portaudio # because portaudio is built with the JACK option off, but neuralrack finds it and assumes that JACK is enabled there

.include <bsd.port.mk>
