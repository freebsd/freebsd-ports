# $FreeBSD$

LIB=df

LIBDIR=${PREFIX}/lib
# comment out the line below to build the profile libs
NOPROFILE=yes

SHLIB_MAJOR=1
SHLIB_MINOR=0

SRCS=atom.c  bitvect.c  cdeflate.c  cnbit.c  cnone.c  crle.c  cskphuff.c \
	df24.c  df24f.c dfan.c  dfanf.c dfcomp.c  dfconv.c dff.c  dfgr.c \
	dfgroup.c  dfimcomp.c  dfjpeg.c  dfkconv.c  dfkcray.c  dfkfuji.c \
	dfknat.c dfkswap.c dfkvms.c dfp.c  dfpf.c dfr8.c dfr8f.c dfrle.c \
	dfsd.c dfsdf.c dfstubs.c dfufp2i.c dfunjpeg.c dfutil.c dfutilf.c \
	dir_mac.c  dynarray.c   glist.c  hbitio.c   hblocks.c  hbuffer.c \
	hchunks.c hcomp.c hcompri.c  hdfalloc.c herr.c herrf.c hextelt.c \
	hfile.c hfiledd.c hfilef.c hkit.c linklist.c mcache.c \
	mfan.c mfanf.c  mfgr.c mfgrf.c mstdio.c tbbt.c  vattr.c vattrf.c \
	vconv.c  vg.c vgf.c  vgp.c  vhi.c vio.c  vparse.c vrw.c  vsfld.c \
	df24ff.f  dfanff.f dfff.f  dfpff.f dfr8ff.f  dfsdff.f dfufp2if.f \
	hfileff.f mfgrff.f vattrff.f vgff.f

CFLAGS	+= -I${PREFIX}/include
FFLAGS	+= ${CFLAGS}

.if !defined(OSVERSION)
.if exists(/sbin/sysctl)
OSVERSION!=	/sbin/sysctl -n kern.osreldate
.else
OSVERSION!=	/usr/sbin/sysctl -n kern.osreldate
.endif
.endif

.if ${OSVERSION} >= 400004
LDADD	+= -L${PREFIX}/lib -ljpeg -lg2c -lz -lm
.else
LDADD	+= -L${PREFIX}/lib -ljpeg -lf2c -lz
.endif

afterinstall:
	install -c -o root -g wheel -m 444 \
		atom.h  bitvect.h  cdeflate.h   cnbit.h  cnone.h  crle.h \
		cskphuff.h df.h dfan.h  dfconvrt.h dfgr.h dfi.h dfivms.h \
		dfrig.h dfsd.h dfstubs.h  dfufp2i.h dir_mac.h dynarray.h \
		glist.h  hbitio.h  hchunks.h  hcomp.h  hcompi.h  hconv.h \
		hdf.h hdfi.h  herr.h hfile.h hkit.h  hlimits.h hntdefs.h \
		hproto.h hqueue.h htags.h linklist.h maldebug.h mcache.h \
		mfan.h mfgr.h mstdio.h sys_dir_mac.h tbbt.h trace.h \
		vattr.h vg.h vgint.h hdf.inc dffunc.inc \
			${PREFIX}/include

.include <bsd.lib.mk>
