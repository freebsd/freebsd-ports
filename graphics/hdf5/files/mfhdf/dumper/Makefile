# $FreeBSD$

PROG		 = hdp
NOMAN		 = 1
LDFLAGS		+= -L${.CURDIR}/../libsrc -L${.CURDIR}/../../hdf/src -lmfhdf -ldf
CFLAGS		+= -I${.CURDIR}/../libsrc -I${.CURDIR}/../../hdf/src

SRCS		=  hdp.c hdp_list.c hdp_sds.c hdp_util.c hdp_vd.c hdp_vg.c hdp_rig.c show.c hdp_dump.c hdp_gr.c

.include <bsd.prog.mk>

test: ${PROG}
	env LD_LIBRARY_PATH=${.CURDIR}/../libsrc:${.CURDIR}/../../hdf/src sh testhdp.sh
