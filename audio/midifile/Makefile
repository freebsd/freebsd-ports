PORTNAME=	midifile
PORTVERSION=	g20200602
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ MIDI file parsing and writing library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	craigsapp
GH_TAGNAME=	988d55b

CMAKE_ON=	BUILD_SHARED_LIBS

EXECUTABLES=	80off asciimidi binasc createmidifile createmidifile2 drumtab durations mid2mat mid2mtb mid2svg \
		midi2binasc midi2melody midi2notes midi2skini midi2text midicat midimixup miditime perfid retick \
		shutak smfdur stretch sysextest text2midi textmidi toascii tobin tobinary todec tohex type0 vlv

do-install: # https://github.com/craigsapp/midifile/issues/83
.for e in ${EXECUTABLES}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${e} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${e}
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/include/midifile
.for h in Binasc.h MidiEvent.h MidiEventList.h MidiFile.h MidiMessage.h Options.h
	${INSTALL_DATA} ${WRKSRC}/include/${h} ${STAGEDIR}${PREFIX}/include/midifile
.endfor
	${INSTALL_LIB} ${BUILD_WRKSRC}/libmidifile.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
