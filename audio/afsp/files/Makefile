# $FreeBSD$

LIBRARIES =	lib/libAO.a \
		lib/libtsp.a
BINARIES =	bin/CompAudio \
		bin/CopyAudio \
		bin/FiltAudio \
		bin/GenNoise \
		bin/GenTone \
		bin/InfoAudio \
		bin/LPanal \
		bin/LPsyn \
		bin/PQevalAudio \
		bin/ResampAudio
MAINHEADERS =	include/AO.h \
		include/AObase.h \
		include/libtsp.h
SUBHEADERS =	include/libtsp/AFdataio.h \
		include/libtsp/AFheader.h \
		include/libtsp/AFmsg.h \
		include/libtsp/AFpar.h \
		include/libtsp/AIpar.h \
		include/libtsp/AUpar.h \
		include/libtsp/ESpar.h \
		include/libtsp/FImsg.h \
		include/libtsp/FIpar.h \
		include/libtsp/FLmsg.h \
		include/libtsp/FNmsg.h \
		include/libtsp/MSmsg.h \
		include/libtsp/SPmsg.h \
		include/libtsp/STmsg.h \
		include/libtsp/UTmsg.h \
		include/libtsp/UTpar.h \
		include/libtsp/UTtypes.h \
		include/libtsp/VRmsg.h \
		include/libtsp/WVpar.h \
		include/libtsp/nucleus.h \
		include/libtsp/sysOS.h
MAN3FILES =	man/libtsp/AF/AFclose.3tsp \
		man/libtsp/AF/AFdReadData.3tsp \
		man/libtsp/AF/AFdWriteData.3tsp \
		man/libtsp/AF/AFfReadData.3tsp \
		man/libtsp/AF/AFfWriteData.3tsp \
		man/libtsp/AF/AFopnRead.3tsp \
		man/libtsp/AF/AFopnWrite.3tsp \
		man/libtsp/AF/AFsetFileType.3tsp \
		man/libtsp/AF/AFsetInfo.3tsp \
		man/libtsp/AF/AFsetNHpar.3tsp \
		man/libtsp/AF/AFsetSpeaker.3tsp
MAN1FILES =	man/audio/AFsp.1audio \
		man/audio/CompAudio.1audio \
		man/audio/CopyAudio.1audio \
		man/audio/FiltAudio.1audio \
		man/audio/GenNoise.1audio \
		man/audio/GenTone.1audio \
		man/audio/InfoAudio.1audio \
		man/audio/LPanal.1audio \
		man/audio/LPsyn.1audio \
		man/audio/PQevalAudio.1audio \
		man/audio/ResampAudio.1audio
HTMLFILES1 =	html/audio/AFsp.html \
		html/audio/CompAudio.html \
		html/audio/CopyAudio.html \
		html/audio/FiltAudio.html \
		html/audio/GenNoise.html \
		html/audio/GenTone.html \
		html/audio/InfoAudio.html \
		html/audio/LPanal.html \
		html/audio/LPsyn.html \
		html/audio/PQevalAudio.html \
		html/audio/ResampAudio.html
HTMLFILES3 =	html/libtsp/AF/AFclose.html \
		html/libtsp/AF/AFdReadData.html \
		html/libtsp/AF/AFdWriteData.html \
		html/libtsp/AF/AFfReadData.html \
		html/libtsp/AF/AFfWriteData.html \
		html/libtsp/AF/AFopnRead.html \
		html/libtsp/AF/AFopnWrite.html \
		html/libtsp/AF/AFsetFileType.html \
		html/libtsp/AF/AFsetInfo.html \
		html/libtsp/AF/AFsetNHpar.html \
		html/libtsp/AF/AFsetSpeaker.html
FILTERFILES =	filters/STL_BPF5k_FIR_16k.cof \
		filters/STL_BPF_FIR_16k.cof \
		filters/STL_G712_IIR_16k.cof \
		filters/STL_G712_IIR_8k.cof \
		filters/STL_IRS_FIR_16k.cof \
		filters/STL_IRS_FIR_8k.cof \
		filters/STL_IRS_IIR_8k.cof \
		filters/STL_LPx2_FIR.cof \
		filters/STL_LPx3_FIR.cof \
		filters/STL_LPx3_IIR.cof \
		filters/STL_MSin_FIR_16k.cof \
		filters/STL_P341S_FIR_16k.cof \
		filters/STL_dc_IIR_8k.cof \
		filters/STL_dsm_FIR_16k.cof \
		filters/STL_hIRS_FIR_16k.cof \
		filters/STL_mIRSR_FIR_16k.cof \
		filters/STL_mIRSR_FIR_8k.cof \
		filters/STL_mIRSS_FIR_16k.cof \
		filters/STL_mIRSS_FIR_48k.cof \
		filters/STL_pso_FIR_8k.cof \
		filters/TIA_IRS_FIR_8k.cof

all:
	for dirs in libtsp libAO audio; do \
		(cd $$dirs; $(MAKE)); \
	done

install: ${LIBRARIES} ${BINARIES}
	${BSD_INSTALL_DATA} ${LIBRARIES} ${PREFIX}/lib/
	${BSD_INSTALL_PROGRAM} ${BINARIES} ${PREFIX}/bin/
	${BSD_INSTALL_DATA} ${MAINHEADERS} ${PREFIX}/include/
	mkdir -p ${PREFIX}/include/libtsp/
	${BSD_INSTALL_DATA} ${SUBHEADERS} ${PREFIX}/include/libtsp/
	${BSD_INSTALL_MAN} ${MAN1FILES} ${PREFIX}/man/man1/
	${BSD_INSTALL_MAN} ${MAN3FILES} ${PREFIX}/man/man3/
	mkdir -p ${PREFIX}/share/doc/afsp/audio/
	${BSD_INSTALL_DATA} ${HTMLFILES1} ${PREFIX}/share/doc/afsp/audio/
	mkdir -p ${PREFIX}/share/doc/afsp/libtsp/AF/
	${BSD_INSTALL_DATA} ${HTMLFILES3} ${PREFIX}/share/doc/afsp/libtsp/AF/
	mkdir -p ${PREFIX}/share/afsp/filters/
	${BSD_INSTALL_DATA} ${FILTERFILES} ${PREFIX}/share/afsp/filters/
