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
		bin/ResampAudio
MAINHEADERS =	include/AD.h \
		include/AO.h \
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
MAN3FILES =	man/AFclose.3tsp \
		man/AFopenRead.3tsp \
		man/AFopenWrite.3tsp \
		man/AFreadData.3tsp \
		man/AFsetFileType.3tsp \
		man/AFsetHinfo.3tsp \
		man/AFwriteData.3tsp \
		man/AFsetNHpar.3tsp
MAN1FILES =	man/AFsp.1audio \
		man/CompAudio.1audio \
		man/CopyAudio.1audio \
		man/FiltAudio.1audio \
		man/GenNoise.1audio \
		man/GenTone.1audio \
		man/InfoAudio.1audio \
		man/LPanal.1audio \
		man/LPsyn.1audio \
		man/ResampAudio.1audio

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
