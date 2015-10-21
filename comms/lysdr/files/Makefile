# Makefile based on wscript
# waf does deep magic ignoring our environment.

PACKAGES=       gtk+-2.0 jack fftw3
CFLAGS+=        `pkg-config -cflags ${PACKAGES}`
LDFLAGS+=       `pkg-config -libs ${PACKAGES}` -lm

SRCS=           gui.c sdr.c filter.c audio_jack.c smeter.c waterfall.c lysdr.c
PROG=           lysdr
WITHOUT_MAN=    yes

.include <bsd.prog.mk>
