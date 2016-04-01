CXXFLAGS+=	-Wall -Wextra
CPPFLAGS+=	-DSYSTEM_POSIX -DSTDC_HEADERS -DHAVE_SYS_RESOURCE_H \
		-DHAVE_SYS_STAT_H -DHAVE_SYS_TIME_H \
		-DHAVE_FCNTL_H -DHAVE_UNISTD_H -DDOUBLEVEC_T
.if $(ARCH:M*64)
CPPFLAGS+=	-DSIZEOF_CHARP=8
.endif

common_OBJS=	common/blockmem.o \
		common/bspfile.o \
		common/cmdlib.o \
		common/filelib.o \
		common/files.o \
		common/log.o \
		common/mathlib.o \
		common/messages.o \
		common/resourcelock.o \
		common/scriplib.o \
		common/threads.o \
		common/winding.o

hlbsp_OBJS=	hlbsp/merge.o \
		hlbsp/outside.o \
		hlbsp/portals.o \
		hlbsp/qbsp.o \
		hlbsp/solidbsp.o \
		hlbsp/surfaces.o \
		hlbsp/tjunc.o \
		hlbsp/writebsp.o

hlcsg_OBJS=	hlcsg/autowad.o \
		hlcsg/brush.o \
		hlcsg/brushunion.o \
		hlcsg/hullfile.o \
		hlcsg/map.o \
		hlcsg/netvis_in_vis.o \
		hlcsg/properties.o \
		hlcsg/qcsg.o \
		hlcsg/textures.o \
		hlcsg/wadcfg.o \
		hlcsg/wadinclude.o \
		hlcsg/wadpath.o

hlrad_OBJS=	hlrad/lerp.o \
		hlrad/lightmap.o \
		hlrad/mathutil.o \
		hlrad/nomatrix.o \
		hlrad/qrad.o \
		hlrad/qradutil.o \
		hlrad/sparse.o \
		hlrad/trace.o \
		hlrad/transfers.o \
		hlrad/transparency.o \
		hlrad/vismatrix.o \
		hlrad/vismatrixutil.o

hlvis_OBJS=	hlvis/flow.o \
		hlvis/vis.o \
		hlvis/zones.o

ripent_OBJS=	ripent/ripent.o

.cpp.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $< -Icommon -Itemplate

all:	# force default goal

.for p in hlbsp hlcsg hlrad hlvis ripent
PROGS+=		$(p)/$(p)
$(p)/$(p): $(common_OBJS) $($(p)_OBJS)
.endfor

all: $(PROGS)

$(PROGS):
	$(CXX) $(LDFLAGS) -o $@ $> -lpthread

install: $(PROGS)
	$(BSD_INSTALL_PROGRAM) $> $(DESTDIR)$(PREFIX)/bin

.PHONY: all install
