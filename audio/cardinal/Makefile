PORTNAME=	cardinal
PORTVERSION=	g20220207
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Plugin wrapper around VCV Rack

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/FuzzySearchDatabase.hpp:textproc/fuzzysearchdatabase \
		bash:shells/bash
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libjansson.so:devel/jansson \
		liblo.so:audio/liblo \
		libpffft.so:math/pffft \
		libpulse-simple.so:audio/pulseaudio \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libspeexdsp.so:audio/speexdsp

USES=		compiler:c++11-lang gl gmake libarchive localbase:ldflags pkgconfig python shebangfix xorg
USE_XORG=	x11 xcursor xext xrandr
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	DISTRHO
GH_PROJECT=	Cardinal
GH_TAGNAME=	4efe110

GH_TUPLE=	\
		VCVRack:Rack:0d003b96476af45102117c2bb958aeb59eb523cf:VCVRack_Rack/src/Rack \
		DISTRHO:DPF:60b9b76b466ad62a9f64f2eb7557a2563bbbf683:DISTRHO_DPF/dpf \
		meganz:mingw-std-threads:f6365f900fb9b1cd6014c8d1cf13ceacf8faf3de:meganz_mingw_std_threads/include/mingw-std-threads \
		DLTcollab:sse2neon:be721a98e7829ce5824a53da78d8210c024ba6c0:DLTcollab_sse2neon/include/sse2neon \
		CardinalModules:Fundamental:50f8ccce5ec433470d87894c94762df133d940f1:CardinalModules_Fundamental/plugins/Fundamental \
		CardinalModules:AudibleInstruments:fec73bc29fc3771d23e6ea03132597774f61c92e:CardinalModules_AudibleInstruments/plugins/AudibleInstruments \
		AnimatedCircuits:RackModules:bd45fc5e9b472182bcc74da264f865d1424a76be:AnimatedCircuits_RackModules/plugins/AnimatedCircuits \
		mhampton:ZetaCarinaeModules:7fa3a59e71cf5f541a335e89bc45102923a3fd62:mhampton_ZetaCarinaeModules/plugins/ZetaCarinaeModules \
		dbgrande:GrandeModular:40a197698496030a30ead69658b1484eca2ae299:dbgrande_GrandeModular/plugins/GrandeModular \
		bogaudio:BogaudioModules:8e982f462c4117f84794cbf6a13740992ff17d92:bogaudio_BogaudioModules/plugins/BogaudioModules \
		CardinalModules:Bidoo:988c2372a95d163b71d04b217080e612b767c539:CardinalModules_Bidoo/plugins/Bidoo \
		VCVRack:ESeries:cb665989f48db6c4fe96924b9e42c804ee15d5cf:VCVRack_ESeries/plugins/ESeries \
		jeremywen:JW-Modules:68f04a5a8a1a656e7a3aa7e217524f0feb91167e:jeremywen_JW_Modules/plugins/JW-Modules \
		CardinalModules:rackwindows:60dfe5dff94b82fc42a43d971e41e64e296b0220:CardinalModules_rackwindows/plugins/rackwindows \
		MarcBoule:ImpromptuModular:368cbd6ee17398c7329b263dde0409bf7a57ce3b:MarcBoule_ImpromptuModular/plugins/ImpromptuModular \
		jhoar:AmalgamatedHarmonics:35b89c93152ac2194eecffbd4aa39e71caa90cc0:jhoar_AmalgamatedHarmonics/plugins/AmalgamatedHarmonics \
		CardinalModules:cf:16470fb91bc14a7bb1aa8e646b6461af82f81275:CardinalModules_cf/plugins/cf \
		MarcBoule:MindMeldModular:621a29f3f1b521582fd11ca7f17635d19faa340c:MarcBoule_MindMeldModular/plugins/MindMeldModular \
		ValleyAudio:ValleyRackFree:440553f3371eab4a84e2b6dcbd3b44ca027871d7:ValleyAudio_ValleyRackFree/plugins/ValleyAudio \
		SVModular:DrumKit:8d78f221927f5aa75d99e4fb8a6b8750141e0933:SVModular_DrumKit/plugins/DrumKit \
		falkTX:Carla:b8d38e395c215eed189a4849972f90af810ef971:falkTX_Carla/carla \
		Xenakios:Atelier:b84dea414c3a2bac231d1c5b837c3003d60a6446:Xenakios_Atelier/plugins/Atelier \
		CardinalModules:mscHack:cf6b1aa5ae47a9e56a0f2ddb0c1aa54927134fb5:CardinalModules_mscHack/plugins/mscHack \
		zezic:ZZC:15364616da500d31f7545dcbfc01b4fda7f7c9d4:zezic_ZZC/plugins/ZZC \
		wiqid:repelzen:185e07ea94086a04b3daacb4bf94c0fbd3544725:wiqid_repelzen/plugins/repelzen \
		CardinalModules:AriaModules:90f8009e1431341225c616bb3a9c250b02bce2c1:CardinalModules_AriaModules/plugins/AriaModules \
		baconpaul:BaconPlugs:0a6c390eedf98884393f82cb066038a78a316ea5:baconpaul_BaconPlugs/plugins/BaconPlugs \
		RCameron93:FehlerFabrik:9b5897828dc1b757f42cb707b5979488acb67401:RCameron93_FehlerFabrik/plugins/FehlerFabrik \
		CardinalModules:Mog-VCV:01c4fac9f2e91f60125d36767224f457b2057fb7:CardinalModules_Mog_VCV/plugins/Mog \
		jatinchowdhury18:ChowDSP-VCV:80f61cd0171bb7d988c9ec3a144e0566d62c767c:jatinchowdhury18_ChowDSP_VCV/plugins/ChowDSP \
		gluethegiant:gtg-rack:54fed7f78bbaac1f1d6275aa737acc39aebc6e72:gluethegiant_gtg_rack/plugins/GlueTheGiant \
		mhetrick:hetrickcv:2fc83df75154c32b83addd3ed68b35eb6156ca0d:mhetrick_hetrickcv/plugins/HetrickCV \
		VegaDeftwing:LyraeModules:1c32b02bd11a549d28da0620719541ac6f966652:VegaDeftwing_LyraeModules/plugins/LyraeModules \
		mgunyho:Little-Utils:b7ce2244835fa376201b21b2274937152dcd1121:mgunyho_Little_Utils/plugins/LittleUtils \
		SteveRussell33:Prism:453da225742f3829ba037770245333a28751fbb8:SteveRussell33_Prism/plugins/Prism \
		EaterOfSheep:Extratone:9fb70500b17fe2495aba9f5f77ddf496d5c09f13:EaterOfSheep_Extratone/plugins/Extratone \
		SteveRussell33:LifeFormModular:c7b8d096f618c421d7d45784b894c0ac2f3395b0:SteveRussell33_LifeFormModular/plugins/LifeFormModular \
		netboy3:21kHz-rack-plugins:0bee82247151e2fe2885f1e15fbbd74ddb4f48d0:netboy3_21kHz_rack_plugins/plugins/21kHz \
		DISTRHO:PawPaw:b41a693b64cdba1abd8d278c9985fb690b522854:DISTRHO_PawPaw/deps/PawPaw \
		LomasModules:LomasModules:a4b802ae1ac12415cbeaeaef5f949dd8d38dfc5c:LomasModules_LomasModules/plugins/LomasModules \
		expertsleepersltd:vcvrack-encoders:df096a635fe8d3ea86a1e6451a55e45ccee5b83d:expertsleepersltd_vcvrack_encoders/plugins/ExpertSleepers-Encoders \
		CardinalModules:ihtsyn:31c4229eb328f6aaa4024f76c595b55213cdf1cf:CardinalModules_ihtsyn/plugins/ihtsyn \
		CardinalModules:QuickJS:9ed118744671f1e257ebb0d731300ba115f6cfce:CardinalModules_QuickJS/deps/QuickJS \
		NikolaiVChr:Autinn:bc880d9d8fb59016de61e3253aff2b543d7bb665:NikolaiVChr_Autinn/plugins/Autinn \
		\
		VCVRack:nanovg:0bebdb314aff9cfa28fde4744bcb037a2b3fd756:VCVRack_nanovg/src/Rack/dep/nanovg \
		memononen:nanosvg:25241c5a8f8451d41ab1b02ab2d865b01600d949:memononen_nanosvg/src/Rack/dep/nanosvg \
		AndrewBelt:osdialog:21b9dcc2a1bbdacb9b46da477ffd82a4ce9204b9:AndrewBelt_osdialog/src/Rack/dep/osdialog \
		VCVRack:oui-blendish:2fc6405883f8451944ed080547d073c8f9f31898:VCVRack_oui_blendish/src/Rack/dep/oui-blendish \
		VCVRack:rtaudio:8128053f4bd83463c7c901d9f5d40b272c2f4e4e:VCVRack_rtaudio/src/Rack/dep/rtaudio \
		VCVRack:glfw:0e18076016f4ba57c314eeebd85654c70644abe3:VCVRack_glfw/src/Rack/dep/glfw \
		gulrak:filesystem:7e37433f318488ae4bc80f80e12df12a01579874:gulrak_filesystem/src/Rack/dep/filesystem \
		\
		craigsapp:midifile:99e87b684f88ebff6417ef25f269f1a95b780ad2:craigsapp_midifile/plugins/BaconPlugs/libs/midifile \
		\
		JerrySievert:SynthDevKit:0f322e58f00f1a04276ecc3eadb610b418f040d5:JerrySievert_SynthDevKit/plugins/DrumKit/deps/SynthDevKit \
		\
		Chowdhury-DSP:chowdsp_utils:b75c3401fa93bbc596a72d21f50e1268fce415a4:Chowdhury_DSP_chowdsp_utils/plugins/ChowDSP/lib/chowdsp_utils \
		\
		pichenettes:avril:276b2887e4110ca913294fcbb313163dfb28a448:pichenettes_avril/plugins/AudibleInstruments/eurorack/avrlib \
		pichenettes:avrilx:868d6e74eb8555f9575b5149202256156e5c03fa:pichenettes_avrilx/plugins/AudibleInstruments/eurorack/avrlibx \
		pichenettes:stmlib:8998429236d6edd4934b6c9ae8e0f167e3d30aa7:pichenettes_stmlib/plugins/AudibleInstruments/eurorack/stmlib \
		pichenettes:stm-audio-bootloader:1ec7d6374e2d305cb710170eb80de9b66e795792:pichenettes_stm_audio_bootloader/plugins/AudibleInstruments/eurorack/stm_audio_bootloader \
		pichenettes:avr-audio-bootloader:0de2be5928afdf7fb3e5ada60544ed6c15ab808f:pichenettes_avr_audio_bootloader/plugins/AudibleInstruments/eurorack/avr_audio_bootloader \
		\
		CardinalModules:eurorack:87bf3b1da88147e3fcc8c57e3072eec67ccd380a:CardinalModules_eurorack/plugins/AudibleInstruments/eurorack \
		\
		LancePutnam:Gamma:70ba31c92db6afa160523940fd046a2bc249e8ad:LancePutnam_Gamma/plugins/HetrickCV/Gamma \
		\
		DISTRHO:pugl:b1d9703ecbdb0a033fe0b9acdf58b90f7d81a8e5:DISTRHO_pugl/dpf/dgl/src/pugl-upstream \
		\
		falkTX:Carla-Plugins:4d9d457d86bebe68f76640718d20f9b72b0a57c6:falkTX_Carla_Plugins/carla/source/native-plugins/external \

USE_GITLAB=	nodefault
GL_TUPLE=	sonusdept:sonusmodular:b63a685c6c68be188f5a3d5d9f6582eb94d62e53:sonusmodular/plugins/sonusmodular

SHEBANG_GLOB=	*.sh

CXXFLAGS+=	-I${LOCALBASE}/include/pffft
LDFLAGS+=	-lpffft

MAKE_ENV=	LD_PRELOAD=/usr/lib/libpthread.so # workaround for https://github.com/DISTRHO/Cardinal/issues/128#issuecomment-1030817359
MAKE_ARGS=	SYSDEPS=true

BINARY_ALIAS=	gcc-ar=ar \
		python3=${PYTHON_CMD}

.include <bsd.port.mk>
