# $FreeBSD$

ECHO=		/bin/echo
MKDIR=		/bin/mkdir -p
SED=		sed
ANT=    	ant -Dos=$(ECLIPSE_OS) -Dws=$(ECLIPSE_WS)

PORTDESTDIR=	$(PREFIX)/eclipse

CFLAGS+=	-I$(JAVA_HOME)/include		\
	 	-I$(JAVA_HOME)/include/bsd	\
	 	-I$(JAVA_HOME)/include/freebsd

LIBUPDATE=	libupdate.so
LIBUPDATE_DST=	plugins/org.eclipse.update.core.freebsd/os/freebsd/x86
LIBUPDATE_SRC=	plugins/org.eclipse.update.core.freebsd/src

SWT_VERSION=	$(ECLIPSE_BUILD)
LIBSWT=		libswt-gtk-$(SWT_VERSION).so
LIBSWTPI=	libswt-pi-gtk-$(SWT_VERSION).so
LIBSWT_DST=	plugins/org.eclipse.swt.gtk/os/freebsd/x86
LIBSWT_SRC= 	plugins/org.eclipse.swt/Eclipse_SWT

LAUNCHER=	eclipse
LAUNCHER_DST=	plugins/platform-launcher/bin/freebsd/gtk
LAUNCHER_SRC=	plugins/platform-launcher/library/gtk

LAUNCHER_SRCS=	$(LAUNCHER_SRC)/../eclipse.c \
		$(LAUNCHER_SRC)/../eclipseUtil.c \
		$(LAUNCHER_SRC)/eclipseGtk.c
LAUNCHER_OBJS=	$(LAUNCHER_SRCS:S/.c/.o/g)

LAUNCHER_CFLAGS= -s \
		-DPROGRAM_NAME="\"$(LAUNCHER)\"" \
		-DDEFAULT_OS="\"$(ECLIPSE_OS)\"" \
		-DDEFAULT_OS_ARCH="\"$(ECLIPSE_ARCH)\"" \
	        -DDEFAULT_WS="\"$(ECLIPSE_WS)\"" \
	        -I$(LAUNCHER_SRC) \
	        -I$(LAUNCHER_SRC)/.. \
	        `pkg-config --cflags gtk+-2.0`
LAUNCHER_LIBS=  `pkg-config --libs gtk+-2.0`

ECLIPSE_TOPLEVEL_FILES= \
	startup.jar splash.bmp cpl-v10.html \
	install.ini notice.html .eclipseproduct

ECLIPSE_CORE_FEATURES= \
	org.eclipse.jdt \
	org.eclipse.jdt.source \
	org.eclipse.pde	\
	org.eclipse.platform \
	org.eclipse.platform.source \
	org.eclipse.team.extras

ECLIPSE_GTK_FEATURES= \
	org.eclipse.platform.freebsd.gtk \
	org.eclipse.platform.freebsd.gtk.source \
	org.eclipse.sdk.freebsd.gtk \

ECLIPSE_MOTIF_FEATURES= \
	org.eclipse.platform.freebsd.gtk \
	org.eclipse.platform.freebsd.gtk.source \
	org.eclipse.sdk.freebsd.gtk \

ECLIPSE_FEATURES= $(ECLIPSE_CORE_FEATURES)

.if $(ECLIPSE_WS) == gtk
ECLIPSE_FEATURES+= $(ECLIPSE_GTK_FEATURES)
.endif

.if $(ECLIPSE_WS) == motif
ECLIPSE_FEATURES+= $(ECLIPSE_MOTIF_FEATURES)
.endif

all: binaries java

binaries: libupdate libswt launcher

libupdate: $(LIBUPDATE_DST)/$(LIBUPDATE)

$(LIBUPDATE_DST)/$(LIBUPDATE):	$(LIBUPDATE_SRC)/update.cpp
	@$(ECHO) "===> Building $(LIBUPDATE)."
	$(MKDIR) $(LIBUPDATE_DST)
	$(CXX) $(CFLAGS) -shared -fpic -fPIC -I$(LIBUPDATE_SRC) -o $(.TARGET) $(.ALLSRC)

libswt: $(LIBSWT_DST)/$(LIBSWTPI) $(LIBSWT_DST)/$(LIBSWT)

$(LIBSWT_DST)/$(LIBSWT):  $(LIBSWT_SRC)/callback.o
	@$(ECHO) "===> Linking $(LIBSWT)."
	$(MKDIR) $(LIBSWT_DST)
	$(CC) -shared -Wl,-x -o $(.TARGET) $(.ALLSRC)

$(LIBSWT_DST)/$(LIBSWTPI):  $(LIBSWT_SRC)/structs.o $(LIBSWT_SRC)/swt.o
	@$(ECHO) "===> Linking $(LIBSWTPI)."
	$(MKDIR) $(LIBSWT_DST)
	$(CC) -shared -Wl,-x -o $(.TARGET) $(.ALLSRC)	\
		`pkg-config --libs gthread-2.0`	\
		`pkg-config --libs gtk+-2.0`

.for i in callback.c structs.c swt.c
$(LIBSWT_SRC)/${i:R:S/$/.o/g}:  $(LIBSWT_SRC)/$i
	@$(ECHO) "===> Compiling $i."
	$(CC) $(CFLAGS) -c -s -fpic -fPIC -o $(.TARGET) $(.ALLSRC)	\
		`pkg-config --cflags gthread-2.0`	\
		`pkg-config --cflags gtk+-2.0`
.endfor

launcher: $(LAUNCHER_DST)/$(LAUNCHER)

.for i in $(LAUNCHER_SRCS)
${i:R:S/$/.o/g}:  $i
	@$(ECHO) "===> Compiling $i."
	$(CC) -c $(CFLAGS) $(LAUNCHER_CFLAGS) -o $(.TARGET) $(.ALLSRC)
.endfor

$(LAUNCHER_DST)/$(LAUNCHER):: $(LAUNCHER_OBJS)
	@$(ECHO) "===> Linking $(LAUNCHER)."
	$(MKDIR) $(LAUNCHER_DST)
	$(CXX) -o $(.TARGET) $(.ALLSRC) $(LAUNCHER_LIBS)

java:	build-java build-doc build-install

build-java:
	@$(ECHO) "===> Compiling Java sources."
	$(ANT) -f build.xml compile

build-doc:
	@$(ECHO) "===> Building Javadoc."
	$(ANT) -f build.xml init buildDoc

build-install:
	$(ANT) -f build.xml install

install:
	@$(ECHO) "===> Creating destination directory..."
	@$(MKDIR) $(PORTDESTDIR)
	@$(ECHO) "===> Installing a shell script..."
	@$(SED) \
	-e "/%%ECLIPSE_HOME%%/s//$(PORTDESTDIR:S/\//\\\//g)/g" \
	-e "/%%JAVA_HOME%%/s//$(JAVA_HOME:S/\//\\\//g)/g" \
        eclipse.in > eclipse.tmp
	$(BSD_INSTALL_SCRIPT) eclipse.tmp $(PREFIX)/bin/eclipse
	@$(ECHO) "===> Installing Eclipse platform."
	@$(MKDIR) $(PORTDESTDIR)
	$(BSD_INSTALL_PROGRAM) $(LAUNCHER_DST)/$(LAUNCHER) $(PORTDESTDIR)
.for i in $(ECLIPSE_TOPLEVEL_FILES)
	$(BSD_INSTALL_DATA) plugins/org.eclipse.platform/$i $(PORTDESTDIR)
.endfor
.for i in $(ECLIPSE_FEATURES)
	@$(ECHO) "===> Installing feature $i"
	$(ANT) -f features/$i-feature/build.xml \
		-Dfeature.base=$(PORTDESTDIR) \
		-Dinclude.children=yes \
		gather.bin.parts
.endfor

clean:
	rm -rf $(LIBUPDATE_DST)/$(LIBUPDATE)
	rm -rf $(LIBSWT_DST)/$(LIBSWTPI) $(LIBSWT_DST)/$(LIBSWT)
	rm -rf $(LAUNCHER_DST)/$(LAUNCHER)
	rm -rf $(LAUNCHER_OBJS)
	rm -rf $(LIBSWT_SRC)/*.o $(LAUNCHER_OBJS)
