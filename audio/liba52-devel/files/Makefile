# $FreeBSD$

LIB=		a52-devel
SHLIB_MAJOR=	${LIB_VERSION}
SHLIB_MINOR=	0
CFLAGS+=	-I${.CURDIR}

SRCS=	bit_allocate.c bitstream.c crc.c downmix.c imdct.c parse.c \
	resample.c
INCS=	a52.h a52_internal.h a52_util.h mm_accel.h

# idea taken from port security/libparanoia
# hacks around <bsd.lib.mk>, which ignores PREFIX
.if defined(PREFIX)
DESTDIR=	${PREFIX}/
.else
DESTDIR=	/usr/local/
.endif
INCSDIR=	include/a52dec-devel/
INCDIR=		${INCSDIR}		# for pre-bsd.incs.mk API
LIBDIR=		lib/

.include <bsd.lib.mk>
