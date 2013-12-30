##### PLEASE SET THE FOLLOWING VARIABLES FIRST ################################
# - Set TARGET_OS to LINUX, FREEBSD or NETBSD.
#
# - PLUGIN_INSTALL_DIRECTORY is where the CWirc plugin stub (cwirc.so) is
#   installed. It should be the X-Chat plugins directory, so the CWirc
#   plugin is loaded automatically when X-Chat starts.
#
# - FRONTEND_INSTALL_DIRECTORY is where the CWirc frontend executable is
#   installed. It should be a bin directory in the PATH, so the plugin
#   portion can execute it.
#
# - CWIRC_EXTENSIONS_DIRECTORY is where CWirc will look for extension programs.
#
# - Define any additional linker flags your system might need in EXTRA_LDFLAGS
#   (for example, "-lossaudio" with NetBSD 1.6.1)
################################################################################
#
# $FreeBSD$
TARGET_OS=FREEBSD
PLUGIN_INSTALL_DIRECTORY=%%STAGEDIR%%%%PREFIX%%/lib/xchat/plugins
FRONTEND_INSTALL_DIRECTORY=%%STAGEDIR%%%%PREFIX%%/bin
CWIRC_EXTENSIONS_DIRECTORY=%%STAGEDIR%%%%PREFIX%%/share/cwirc/extensions
#EXTRA_LDFLAGS=

# Use these with Debian GNU/Linux for example
#TARGET_OS=LINUX
#PLUGIN_INSTALL_DIRECTORY=/usr/lib/xchat/plugins
#FRONTEND_INSTALL_DIRECTORY=/usr/bin
#CWIRC_EXTENSIONS_DIRECTORY=/usr/lib/cwirc/extensions
#EXTRA_LDFLAGS=

# Use these with FreeBSD 5.1 for example
#TARGET_OS=FREEBSD
#PLUGIN_INSTALL_DIRECTORY=/usr/X11R6/lib/xchat/plugins
#FRONTEND_INSTALL_DIRECTORY=/usr/X11R6/bin
#CWIRC_EXTENSIONS_DIRECTORY=/usr/X11R6/lib/cwirc/extensions
#EXTRA_LDFLAGS=

# Use these with NetBSD 1.6.1 for example
#TARGET_OS=NETBSD
#PLUGIN_INSTALL_DIRECTORY=/usr/pkg/lib/xchat/plugins
#FRONTEND_INSTALL_DIRECTORY=/usr/pkg/bin
#CWIRC_EXTENSIONS_DIRECTORY=/usr/pkg/lib/cwirc/extensions
#EXTRA_LDFLAGS=-lossaudio

################################################################################

VERSION=2.0.0

PLUGIN=cwirc.so
FRONTEND=cwirc_frontend

RM?=/bin/rm
CP?=/bin/cp
MKDIR?=/bin/mkdir
TAR?=tar
PWD?=pwd
CC?=gcc
STRIP?=strip

XCHAT_PLUGIN_INCLUDE_PATH=xchat

XCHAT_INC=-I$(XCHAT_PLUGIN_INCLUDE_PATH)
#CFLAGS=-Wall -Wstrict-prototypes -O2 -D$(TARGET_OS)
CFLAGS+= -D$(TARGET_OS)
GTK_CFLAGS=`pkg-config --cflags gtk+-2.0`
LDFLAGS=-lm ${EXTRA_LDFLAGS}
GTK_LDFLAGS=`pkg-config --libs gtk+-2.0`

all:			missing_settings				\
			$(PLUGIN) 					\
			$(FRONTEND)

install:		missing_settings				\
			$(PLUGIN)					\
			$(FRONTEND)
			$(MKDIR) -p $(PLUGIN_INSTALL_DIRECTORY)
			$(MKDIR) -p $(CWIRC_EXTENSIONS_DIRECTORY)
			$(CP) $(PLUGIN) $(PLUGIN_INSTALL_DIRECTORY)
			$(MKDIR) -p $(FRONTEND_INSTALL_DIRECTORY)
			$(CP) $(FRONTEND) $(FRONTEND_INSTALL_DIRECTORY)

uninstall:		missing_settings
			$(RM) -f $(PLUGIN_INSTALL_DIRECTORY)/$(PLUGIN)
			$(RM) -f $(FRONTEND_INSTALL_DIRECTORY)/$(FRONTEND)

PLUGIN_OBJS=		plugin.shared.o					\
			ipc.shared.o					\
			grid.shared.o					\
			propagation.shared.o				\
			cwframe.shared.o

FRONTEND_OBJS=		frontend.o					\
			io.o						\
			gui.o						\
			ipc.o						\
			keyer.o						\
			grid.o						\
			propagation.o					\
			cwsound.o					\
			cwdecoder.o					\
			cwframe.o					\
			rcfile.o					\
			extension.o

$(PLUGIN):		$(PLUGIN_OBJS)
			$(CC) -shared $(LDFLAGS) -o $@ $(PLUGIN_OBJS)
			$(STRIP) $@

$(FRONTEND):		$(FRONTEND_OBJS)
			$(CC) $(LDFLAGS) $(GTK_LDFLAGS) -o $@ $(FRONTEND_OBJS)
			$(STRIP) $@

plugin.shared.o:	plugin.c					\
			$(XCHAT_PLUGIN_INCLUDE_PATH)/xchat-plugin.h	\
			types.h						\
			common.h					\
			cwirc.h						\
			cwframe.h					\
			ipc.h
			$(CC) $(CFLAGS) $(XCHAT_INC) -fPIC -c -o $@ plugin.c

frontend.o:		frontend.c					\
			types.h						\
			cwirc.h						\
			common.h					\
			rcfile.h					\
			io.h						\
			gui.h						\
			extension.h					\
			ipc.h
			$(CC) $(CFLAGS) $(XCHAT_INC) -c -o $@ frontend.c

io.o:			io.c						\
			types.h						\
			io.h						\
			cwirc.h						\
			keyer.h						\
			cwsound.h					\
			cwdecoder.h					\
			propagation.h					\
			extension.h					\
			ipc.h
			$(CC) $(CFLAGS) -c -o $@ io.c

gui.o:			gui.c						\
			types.h						\
			gui.h						\
			common.h					\
			cwirc.h						\
			rcfile.h					\
			grid.h						\
			io.h						\
			cwdecoder.h					\
			extension.h					\
			keyer.h						\
			ipc.h						\
			smeter.xpm					\
			sidetone.xpm					\
			straightkey.xpm					\
			iambickey.xpm
			$(CC) $(CFLAGS) $(GTK_CFLAGS) -c -o $@ gui.c

keyer.o:		keyer.c						\
			types.h						\
			keyer.h
			$(CC) $(CFLAGS) -c -o $@ keyer.c

grid.o:			grid.c						\
			grid.h
			$(CC) $(CFLAGS) -c -o $@ grid.c

grid.shared.o:		grid.c						\
			grid.h
			$(CC) $(CFLAGS) -fPIC -c -o $@ grid.c

propagation.o:		propagation.c					\
			propagation.h
			$(CC) $(CFLAGS) -c -o $@ propagation.c

propagation.shared.o:	propagation.c					\
			propagation.h
			$(CC) $(CFLAGS) -fPIC -c -o $@ propagation.c

cwsound.o:		cwsound.c					\
			types.h						\
			cwsound.h					\
			sounder_down.h					\
			sounder_up.h
			$(CC) $(CFLAGS) -c -o $@ cwsound.c

cwframe.o:		cwframe.c					\
			types.h						\
			cwframe.h					\
			cwirc.h						\
			grid.h						\
			propagation.h					\
			io.h						\
			ipc.h
			$(CC) $(CFLAGS) -c -o $@ cwframe.c

cwframe.shared.o:	cwframe.c					\
			types.h						\
			cwframe.h					\
			cwirc.h						\
			grid.h						\
			propagation.h					\
			io.h						\
			ipc.h
			$(CC) $(CFLAGS) -fPIC -c -o $@ cwframe.c

cwdecoder.o:		cwdecoder.c					\
			types.h						\
			cwdecoder.h					\
			morsecodes.h					\
			cwirc.h
			$(CC) $(CFLAGS) -c -o $@ cwdecoder.c

ipc.o:			ipc.c						\
			ipc.h
			$(CC) $(CFLAGS) -c -o $@ ipc.c

ipc.shared.o:		ipc.c						\
			ipc.h
			$(CC) $(CFLAGS) -fPIC -c -o $@ ipc.c

rcfile.o:		rcfile.c					\
			types.h						\
			rcfile.h					\
			cwirc.h						\
			grid.h						\
			io.h						\
			cwdecoder.h
			$(CC) $(CFLAGS) -c -o $@ rcfile.c

extension.o:		extension.c					\
			types.h						\
			cwirc.h						\
			extension.h					\
			ipc.h						\
			common.h
			$(CC) $(CFLAGS) -c -o $@ extension.c

sounder_down.h:		sounder_down.wav				\
			mksndinclude
			./mksndinclude sounder_down > $@ < sounder_down.wav

sounder_up.h:		sounder_up.wav					\
			mksndinclude
			./mksndinclude sounder_up > $@ < sounder_up.wav

mksndinclude:		mksndinclude.c					\
			types.h
			$(CC) $(CFLAGS) -o $@ mksndinclude.c

common.h:
			echo "#define FRONTEND \"$(FRONTEND)\"" > $@
			echo "#define VERSION \"$(VERSION)\"" >> $@
			echo "#define EXTENSIONS_DIR			\
			\"$(CWIRC_EXTENSIONS_DIRECTORY)\"" >> $@

clean:
			$(RM) -f $(FRONTEND)
			$(RM) -f *.so
			$(RM) -f *.o
			$(RM) -f common.h
			$(RM) -f sounder_down.h
			$(RM) -f sounder_up.h
			$(RM) -f mksndinclude
			$(RM) -rf release

missing_settings:
			@(if [ ! "$(TARGET_OS)" ] ||			\
			     [ ! "$(PLUGIN_INSTALL_DIRECTORY)" ] ||	\
			     [ ! "$(FRONTEND_INSTALL_DIRECTORY)" ] ||	\
			     [ ! "$(CWIRC_EXTENSIONS_DIRECTORY)" ];then	\
			    echo;					\
			    echo "*** Please edit the Makefile to ***";	\
			    echo "**** set the target OS and the ****";	\
			    echo "**** CWirc installation paths. ****";	\
			    echo;					\
			    exit 1;					\
			  fi)

########## RELEASE ONLY SECTION ################################################
SRCFILES=	COPYING Changelog Makefile README LISEZMOI RELEASE_NOTES\
		schematics/rs232_key_connection.jpg			\
		schematics/cw_oscillator.jpg cwdecoder.c cwframe.c	\
		cwsound.c frontend.c extension.c grid.c gui.c keyer.c	\
		io.c ipc.c mksndinclude.c plugin.c propagation.c	\
		rcfile.c						\
		cwdecoder.h cwframe.h cwirc.h cwsound.h extension.h	\
		grid.h gui.h keyer.h io.h ipc.h morsecodes.h		\
		propagation.h rcfile.h types.h xchat/xchat-plugin.h	\
		xchat/README.xchat_include_file				\
		straightkey.xpm iambickey.xpm smeter.xpm sidetone.xpm	\
		sounder_down.wav sounder_up.wav				\
		debian/changelog debian/compat debian/control		\
		debian/copyright debian/rules debian/watch		\
		rpm/cwirc.spec rpm/rpmmacros

release:	source_release debian_release rpm_release

source_release:	release/cwirc-$(VERSION).tar.gz

release/cwirc-$(VERSION).tar.gz:
		$(MKDIR) -p release/cwirc-$(VERSION)
		$(CP) --parents -a $(SRCFILES) release/cwirc-$(VERSION)
		$(TAR) -C release -cvzf $@ cwirc-$(VERSION)
		$(RM) -r release/cwirc-$(VERSION)

debian_release: release/cwirc-$(VERSION).tar.gz
		$(MKDIR) -p release/debian
		$(TAR) -C release/debian -zxf $<
		(cd release/debian/cwirc-$(VERSION) &&			\
			dpkg-buildpackage -rfakeroot)
		$(RM) -rf release/debian/cwirc-$(VERSION)

rpm_release:	release/cwirc-$(VERSION).tar.gz
		$(MKDIR) -p release/rpm/RPM/BUILD
		$(MKDIR) -p release/rpm/RPM/RPMS
		$(MKDIR) -p release/rpm/RPM/SOURCES
		$(MKDIR) -p release/rpm/RPM/SPECS
		$(MKDIR) -p release/rpm/RPM/SRPMS
		(if [ -f ~/.rpmmacros ];then				\
		   $(CP) -a ~/.rpmmacros release/rpm/RPM;		\
		 fi)
		$(CP) rpm/rpmmacros ~/.rpmmacros
		(RPMTOPDIR=`cd release/rpm/RPM && $(PWD)`;		\
		 echo "%_topdir $$RPMTOPDIR" >> ~/.rpmmacros)
		$(CP) release/cwirc-$(VERSION).tar.gz release/rpm/RPM/SOURCES
		$(CP) rpm/cwirc.spec release/rpm/RPM/SPECS
		rpm -ba release/rpm/RPM/SPECS/cwirc.spec
		$(CP) release/rpm/RPM/RPMS/*/*.rpm release/rpm
		$(CP) release/rpm/RPM/SRPMS/*.src.rpm release/rpm
		$(RM) ~/.rpmmacros
		(if [ -f release/rpm/RPM/.rpmmacros ];then		\
		   $(CP) -a release/rpm/RPM/.rpmmacros ~;		\
		 fi)
		$(RM) -rf release/rpm/RPM
################################################################################
