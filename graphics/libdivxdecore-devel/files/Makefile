# $FreeBSD$

LIB=	divxdecore
SHLIB_MAJOR=	${LIB_VERSION}
SHLIB_MINOR=	0
CFLAGS+=-I${.CURDIR} -DLINUX -DO_BINARY=0 -D_DECORE
SRCS=   basic_prediction.c clearblock.c debug.c decore.c \
	getbits.c idct.c mp4_block.c mp4_decoder.c mp4_header.c \
	mp4_iquant.c mp4_mblock.c mp4_picture.c mp4_predict.c \
	mp4_recon.c mp4_tables.c mp4_vars.c mp4_vld.c \
	postprocess.c store.c transferIDCT.c yuv2rgb.c
INCS=	decore.h

# idea taken from port security/libparanoia
# hacks around <bsd.lib.mk>, which ignores PREFIX
.if defined(PREFIX)
DESTDIR=${PREFIX}/
.else
DESTDIR=/usr/local/
.endif
INCSDIR=include/divx/
INCDIR=${INCSDIR}			# for pre-bsd.incs.mk API
LIBDIR=lib/

.include <bsd.lib.mk>
