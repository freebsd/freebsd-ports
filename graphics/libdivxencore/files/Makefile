# $FreeBSD$

LIB=	divxencore
SHLIB_MAJOR=	${LIB_VERSION}
SHLIB_MINOR=	0
CFLAGS+=-I${.CURDIR}
SRCS=	bitstream.c encore.c mom_access.c mom_util.c mot_code.c \
	mot_est_comp.c mot_est_mb.c mot_util.c putvlc.c rate_ctl.c \
	text_bits.c text_code.c text_code_mb.c text_dct.c vop_code.c
INCS=	encore.h

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
