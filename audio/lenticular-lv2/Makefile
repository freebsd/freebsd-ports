PORTNAME=	lenticular
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0-14
DISTVERSIONSUFFIX=	-g14d8075
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 plugins based on Mutable Instrument's Clouds

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		compiler:c++11-lang gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	polyeffects
GH_PROJECT=	lenticular_lv2

GH_TUPLE=	\
		VCVRack:pichenettes-eurorack:99432f2bf443219b3eb77e65e1a18583faad422e:AndrewBelt_eurorack/eurorack \
		pichenettes:avril:36b988a851f8638adb9f53ff98939cb08ffce8cc:pichenettes_avril/parasites/avrlib \
		pichenettes:avrilx:5c28367e91dfb036593e876c886241cf81f60a2d:pichenettes_avrilx/parasites/avrlibx \
		pichenettes:stm-audio-bootloader:6f20ead22a28967b0446546d2fcf0dfb9599ba93:pichenettes_stm_audio_bootloader/parasites/stm_audio_bootloader \
		pichenettes:avr-audio-bootloader:52754f878b4883adf565bc3ddf691c5e1c4a9f6d:pichenettes_avr_audio_bootloader/parasites/avr_audio_bootloader \
		mqtthiqs:stmlib:8ab2aaee77cbacb47b646d46d22ee5d358effe2d:mqtthiqs_stmlib/parasites/stmlib \
		pichenettes:stmlib:d9b189670be3d5c1e41ee143b6ee92171cfd6de3:pichenettes_stmlib/eurorack/stmlib

PLIST_FILES=	\
	lib/lv2/polylenticular.lv2/manifest.ttl \
	lib/lv2/polylenticular.lv2/polyclouds.so \
	lib/lv2/polylenticular.lv2/polyclouds.ttl \
	lib/lv2/polylenticular.lv2/polyplaits.so \
	lib/lv2/polylenticular.lv2/polyplaits.ttl \
	lib/lv2/polylenticular.lv2/polywarps.so \
	lib/lv2/polylenticular.lv2/polywarps.ttl

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/polylenticular.lv2/*.so

.include <bsd.port.mk>
