# $FreeBSD$

OUTSUFX=	lib/$(ARCH)-$(OPSYS:tl)

# XXX: sometimes the build crashes with ``An unhandled exception occurred
# at $0814EBB3'' message (EAccessViolation: Access violation).  It might
# be some concurrency issue, but it occurs even with MAKE_JOBS_UNSAFE, so
# use the following simple workaround for the time being.
ZEALOUS_BUILD=	sh -c 'i=0 ; until $(LAZBUILD_CMD) $(LAZBUILD_ARGS) --ws=$(LCL_PLATFORM) --lazarusdir=$(LAZARUS_DIR) $$0 ; do \
		test $$i -lt 4 || return ; i=$$((i+1)) ; done'

all: ../$(OUTSUFX)/zcad.compiled

ZCAD_DEPS= \
	other/AGraphLaz/lazarus/$(OUTSUFX)/ag_graph.compiled \
	other/VirtualTreeView-Lazarus/Source/$(OUTSUFX)-$(GUI)/virtualtreeview_package.compiled \
	components/zmath/$(OUTSUFX)/zmath.compiled \
	components/zobjectinspector/$(OUTSUFX)/zobjectinspector.compiled

AG_GRAPH_DEPS= \
	other/AGraphLaz/lazarus/$(OUTSUFX)/ag_vectors.compiled \
	other/AGraphLaz/lazarus/$(OUTSUFX)/ag_attr.compiled \
	other/AGraphLaz/lazarus/$(OUTSUFX)/ag_math.compiled \

VTV_DEPS= \
	other/lclextensions/$(OUTSUFX)-$(GUI)/lclextensions_package.compiled

ZMATH_DEPS= \
	components/zebase/$(OUTSUFX)/zebase.compiled

ZOBJINST_DEPS= \
	components/zscript/$(OUTSUFX)/zscript.compiled \
	components/zcontrols/$(OUTSUFX)/zcontrols.compiled \
	components/zundostack/$(OUTSUFX)/zundostack.compiled

ZSCRIPT_DEPS= \
	components/zscriptbase/$(OUTSUFX)/zscriptbase.compiled

ZSCRIPTBASE_DEPS= \
	components/zcontainers/$(OUTSUFX)/zcontainers.compiled

../$(OUTSUFX)/zcad.compiled: $(ZCAD_DEPS)
	$(ZEALOUS_BUILD) zcad.lpi

other/AGraphLaz/lazarus/$(OUTSUFX)/ag_graph.compiled: $(AG_GRAPH_DEPS)
	$(ZEALOUS_BUILD) other/AGraphLaz/lazarus/ag_graph.lpk

other/AGraphLaz/lazarus/$(OUTSUFX)/ag_vectors.compiled:
	$(ZEALOUS_BUILD) other/AGraphLaz/lazarus/ag_vectors.lpk

other/AGraphLaz/lazarus/$(OUTSUFX)/ag_attr.compiled:
	$(ZEALOUS_BUILD) other/AGraphLaz/lazarus/ag_attr.lpk

other/AGraphLaz/lazarus/$(OUTSUFX)/ag_math.compiled:
	$(ZEALOUS_BUILD) other/AGraphLaz/lazarus/ag_math.lpk

other/VirtualTreeView-Lazarus/Source/$(OUTSUFX)-$(GUI)/virtualtreeview_package.compiled: $(VTV_DEPS)
	$(ZEALOUS_BUILD) other/VirtualTreeView-Lazarus/Source/virtualtreeview_package.lpk

other/lclextensions/$(OUTSUFX)-$(GUI)/lclextensions_package.compiled:
	$(ZEALOUS_BUILD) other/lclextensions/lclextensions_package.lpk

components/zmath/$(OUTSUFX)/zmath.compiled: $(ZMATH_DEPS)
	$(ZEALOUS_BUILD) components/zmath/zmath.lpk

components/zebase/$(OUTSUFX)/zebase.compiled:
	$(ZEALOUS_BUILD) components/zebase/zebase.lpk

components/zobjectinspector/$(OUTSUFX)/zobjectinspector.compiled: $(ZOBJINST_DEPS)
	$(ZEALOUS_BUILD) components/zobjectinspector/zobjectinspector.lpk

components/zscript/$(OUTSUFX)/zscript.compiled: $(ZSCRIPT_DEPS)
	$(ZEALOUS_BUILD) components/zscript/zscript.lpk

components/zscriptbase/$(OUTSUFX)/zscriptbase.compiled: $(ZSCRIPTBASE_DEPS)
	$(ZEALOUS_BUILD) components/zscriptbase/zscriptbase.lpk

components/zcontainers/$(OUTSUFX)/zcontainers.compiled: $(ZMATH_DEPS)
	$(ZEALOUS_BUILD) components/zcontainers/zcontainers.lpk

components/zcontrols/$(OUTSUFX)/zcontrols.compiled:
	$(ZEALOUS_BUILD) components/zcontrols/zcontrols.lpk

components/zundostack/$(OUTSUFX)/zundostack.compiled: $(ZSCRIPT_DEPS)
	$(ZEALOUS_BUILD) components/zundostack/zundostack.lpk
