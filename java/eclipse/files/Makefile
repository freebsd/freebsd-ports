# $FreeBSD$

ECHO=		/bin/echo
FIND=		/usr/bin/find
MKDIR=		/bin/mkdir -p
SED=		/usr/bin/sed
CP=		/bin/cp
CSH=		/bin/csh
SH=		/bin/sh
GMAKE=		$(LOCALBASE)/bin/gmake
ANT=		$(LOCALBASE)/bin/ant
UNZIP_CMD=	$(LOCALBASE)/bin/unzip

PORTDESTDIR=	$(PREFIX)/eclipse

CFLAGS+=	-I$(JAVA_HOME)/include		\
		-I$(JAVA_HOME)/include/bsd	\
		-I$(JAVA_HOME)/include/freebsd

LIBUPDATE=	libupdate.so
LIBUPDATE_DST=	plugins/org.eclipse.update.core.freebsd/os/freebsd/x86
LIBUPDATE_SRC=	plugins/org.eclipse.update.core.freebsd/src
 
SWT_VERSION=	$(ECLIPSE_BUILD)
LIBSWT=		libswt-$(ECLIPSE_WS)-$(SWT_VERSION).so
LIBSWTPI=	libswt-pi-$(ECLIPSE_WS)-$(SWT_VERSION).so
LIBSWT_DST=	plugins/org.eclipse.swt.$(ECLIPSE_WS)/os/freebsd/x86
LIBSWT_SRC=	plugins/org.eclipse.swt/Eclipse_SWT
 
LAUNCHER=	eclipse
LAUNCHER_DST=	plugins/platform-launcher/bin/freebsd/$(ECLIPSE_WS)
LAUNCHER_SRC=	plugins/platform-launcher/library/$(ECLIPSE_WS)

LAUNCHER_SRCS=	$(LAUNCHER_SRC)/../eclipse.c \
		$(LAUNCHER_SRC)/../eclipseUtil.c \
		$(LAUNCHER_SRC)/../eclipseShm.c \
		$(LAUNCHER_SRC)/eclipseGtk.c
LAUNCHER_OBJS=	$(LAUNCHER_SRCS:S/.c/.o/g)

all:		binaries java

binaries:	libswt launcher libupdate

libswt:
	@$(ECHO) "===> Building libswt."
	cd "plugins/org.eclipse.swt/Eclipse SWT PI/$(ECLIPSE_WS)/library" && \
		$(SH) ./build.sh && \
		$(CP) *.so ../../../../org.eclipse.swt.$(ECLIPSE_WS)/os/freebsd/x86/

launcher:
	@$(ECHO) "===> Building Eclipse launcher."
	cd plugins/platform-launcher/library/$(ECLIPSE_WS) && \
		$(CSH) build.csh -os freebsd && \
		$(CP) eclipse ../../bin/freebsd/$(ECLIPSE_WS)/eclipse

libupdate:
	@$(ECHO) "===> Building libupdate."
	cd plugins/org.eclipse.update.core.freebsd/src && \
		$(ANT) -Djava.home=$(JAVA_HOME)
	@$(ECHO) "===> Building libcore."
	cd plugins/org.eclipse.core.resources.freebsd/src && \
		env JDK_INCLUDE="/usr/local/jdk1.4.2/include -I/usr/local/jdk1.4.2/include/freebsd" $(GMAKE) && \
		$(CP) *.so ../../org.eclipse.core.resources.freebsd/os/freebsd/x86

java:		build-install

build-install:
	@$(ECHO) "===> Building Eclipse platform."
	./build -os $(ECLIPSE_OS) -ws $(ECLIPSE_WS) -arch $(ECLIPSE_ARCH)

install:
	@$(ECHO) "===> Installing Eclipse platform."
	@$(MKDIR) $(PORTDESTDIR)
	$(UNZIP_CMD) result/$(ECLIPSE_OS)-$(ECLIPSE_WS)-$(ECLIPSE_ARCH)-sdk.zip -d $(PREFIX)
	@$(ECHO) "===> Installing a shell script..."
	@$(SED) \
	-e "/%%ECLIPSE_HOME%%/s//$(PORTDESTDIR:S/\//\\\//g)/g" \
	-e "/%%JAVA_HOME%%/s//$(JAVA_HOME:S/\//\\\//g)/g" \
	eclipse.in > eclipse.tmp
	$(BSD_INSTALL_SCRIPT) eclipse.tmp $(PREFIX)/bin/eclipse

clean:
	./build -os $(ECLIPSE_OS) -ws $(ECLIPSE_WS) -arch $(ECLIPSE_ARCH) clean
	rm -rf $(LIBSWT_DST)/$(LIBSWTPI) $(LIBSWT_DST)/$(LIBSWT)
	rm -rf $(LAUNCHER_DST)/$(LAUNCHER)
	rm -rf $(LIBSWT_SRC)/*.o $(LAUNCHER_OBJS)
	rm -rf $(LIBUPDATE_DST)/$(LIBUPDATE)
