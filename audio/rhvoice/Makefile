PORTNAME=	RHVoice
DISTVERSION=	1.2.4
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Speech synthesizer for English, Russian, Georgian, and other languages

LICENSE=	LGPL21+ GPLv3+ # the main code is under LGPL21+, MAGE library is under GPLv3+, voices are licensed for use by individuals only, no commercial use
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21+ =	${WRKSRC}/licenses/lgpl-2.1.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/licenses/gpl-3.0.txt

BROKEN_FreeBSD_12_powerpc64=	fails to configure: The C++ compiler is not working

USES=		compiler:c++0x pkgconfig scons
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TUPLE=	arsenm:sanitizers-cmake:99e159e:sanitizers/cmake/thirdparty/sanitizers \
		unicode-org:cldr:d1c59ae:cldr/src/third-party/cldr \
		rhvoice:victoria-rus:e57c82c:victoria_rus/data/voices/victoria \
		rhvoice:evgeniy-rus:dd971ee:evgeniy_rus/data/voices/evgeniy-rus \
		rhvoice:evgeniy-eng:c483272:evgeniy_eng/data/voices/evgeniy-eng

OPTIONS_RADIO=			AUDIO
OPTIONS_RADIO_AUDIO=		PULSEAUDIO AO PORTAUDIO # only one of them works at a time
OPTIONS_DEFAULT=		AO

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
AO_LIB_DEPENDS=			libao.so:audio/libao
PORTAUDIO_LIB_DEPENDS=		libportaudio.so:audio/portaudio

post-patch-PULSEAUDIO-off:
	@${REINPLACE_CMD} 's|conf.CheckPKG("libpulse-simple")|False|' ${WRKSRC}/SConstruct

post-patch-AO-off:
	@${REINPLACE_CMD} 's|conf.CheckPKG("ao")|False|' ${WRKSRC}/SConstruct

post-patch-PORTAUDIO-off:
	@${REINPLACE_CMD} 's|conf.CheckPKG("portaudio-2.0")|False|' ${WRKSRC}/SConstruct

post-install:
	# create config file
	${MV} ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample
	# strip binaries
	cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/RHVoice-test bin/sd_rhvoice lib/libRHVoice.so lib/libRHVoice_audio.so lib/libRHVoice_core.so
	# install accessibility/speech-dispatcher module
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/speech-dispatcher-modules
	${RLN} ${STAGEDIR}${PREFIX}/bin/sd_rhvoice ${STAGEDIR}${PREFIX}/lib/speech-dispatcher-modules

.include <bsd.port.mk>
