# New ports collection makefile for:	modula-3-lib
# Version required:	3.6
# Date created:		28 Oct 1996
# Whom:			John Polstra <jdp@polstra.com>
#
# $Id: Makefile,v 1.13 1998/10/13 01:17:27 jseger Exp $
#

DISTNAME=	modula-3-lib-3.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	m3-fbsd-src-3.6.tar.gz \
		m3-fbsd-m3cc-3.6.tar.gz \
		m3-fbsd-m3ccelf-3.6.tar.gz
# Note: Depending on what is already installed on the system, the code
# below may add some more DISTFILES.

MAINTAINER=	jdp@polstra.com

NO_WRKSUBDIR=	yes
SCRIPTS_ENV+=	MAJOR=${major} PKGDIR=${PKGDIR} PLIST=${PLIST}

# There are two distfiles that may or may not be needed, depending on
# what is already installed on the system.  First, we need an executable
# for the Modula-3 compiler, in order to compile the new compiler, which
# is written in Modula-3.  Often, there will already be such an executable
# installed on the system.  Second, we need many files from gcc-2.7.2.1.
# Often, we can find these in the system sources, under "/usr/src/contrib".
#
# This code tries to avoid fetching the distfiles, unless necessary.
# We look on the system to see whether the necessary files are present,
# and use those if we can.  If we cannot find the needed files, we
# fetch the distfiles.

# For the Modula-3 compiler, we look in ${PREFIX} and in /usr/local.
.ifdef PREFIX
have_boot!=	/bin/sh scripts/check_files files/T.boot installed ${PREFIX}
.else
have_boot=
.endif
.if empty(have_boot)
have_boot!=	/bin/sh scripts/check_files files/T.boot installed /usr/local
.endif
.if empty(have_boot)
DISTFILES+=	m3-fbsd-boot-3.6.tar.gz
.endif

# For gcc-2.7.2.1, we look in /usr/src/contrib.
have_gcc!=	/bin/sh scripts/check_files files/T.gcc m3cc /usr/src/contrib
.if empty(have_gcc)
DISTFILES+=	m3-fbsd-gcc-3.6.tar.gz
.endif

# Startup script, run at boot time
startup_dir=	${PREFIX}/etc/rc.d
startup_script=	${startup_dir}/50.m3.sh

# The Modula-3 build process insists on installing each individual
# component immediately after that component is built.  To avoid having
# to do the entire build as root, we arrange for everything to first
# be "installed" into the following directory, which we own.
temp_prefix=	${WRKSRC}/installed

# Where shared libraries are installed, relative to the PREFIX.
libdir=		lib/m3/FreeBSD2

# Shared library major version number
major=		6

# Support building on systems with or without X11 installed.
.ifdef NO_X11
PLIST=		${WRKDIR}/PLIST.noX11
.else
pre-fetch:
	@echo "To build this port without X11, define \"NO_X11\"."

USE_XLIB=	yes
PLIST=		${WRKDIR}/PLIST
.endif

post-extract:
.if !empty(have_boot)
	@echo "Copying bootstrap modula-3 compiler from ${have_boot}"
	@${SH} ${SCRIPTDIR}/copy_files ${FILESDIR}/T.boot installed \
	    ${have_boot} ${WRKSRC}
.endif
.if !empty(have_gcc)
	@echo "Copying gcc sources from ${have_gcc}"
	@${SH} ${SCRIPTDIR}/copy_files ${FILESDIR}/T.gcc m3cc \
	    ${have_gcc} ${WRKSRC}
.endif
	@cd ${WRKSRC}/m3cc/gcc; \
	    chmod +x config.sub configure move-if-change

do-build:
	@test -d ${temp_prefix}/bin || ${MKDIR} ${temp_prefix}/bin
	@test -d ${temp_prefix}/man/man1 || ${MKDIR} ${temp_prefix}/man/man1
	@test -d ${temp_prefix}/lib/m3/pkg/m3build/templates || \
	    ${MKDIR} ${temp_prefix}/lib/m3/pkg/m3build/templates
	@echo "++++++++++ quake ++++++++++"
	@test -d ${WRKSRC}/m3/quake/FreeBSD2 || \
	    ${MKDIR} ${WRKSRC}/m3/quake/FreeBSD2
	@cd ${WRKSRC}/m3/quake/FreeBSD2; \
	    make -f ../src/makefile TARGET=FreeBSD2 COPT=-O CDEBUG= ; \
	    ${CP} -p quake ${temp_prefix}/bin; \
	    ${CP} -p ../src/quake.1 ${temp_prefix}/man/man1
	@echo "++++++++++ m3build ++++++++++"
	@cd ${WRKSRC}/m3/m3build; \
	    PATH=${temp_prefix}/bin:$$PATH ./build FreeBSD2; \
	    ${CP} -p FreeBSD2/m3build FreeBSD2/m3ship FreeBSD2/m3where \
		${temp_prefix}/bin; \
	    ${CP} -p FreeBSD2/m3mkdir ${temp_prefix}/${libdir}; \
	    ${CP} -p templates/CLEANUP templates/COMMON templates/COMMON.BOOT \
		templates/FreeBSD2 templates/PLATFORMS templates/POSIX \
		${temp_prefix}/lib/m3/pkg/m3build/templates; \
	    ${CP} -p FreeBSD2/m3build.1 FreeBSD2/m3ship.1 FreeBSD2/m3where.1 \
		${temp_prefix}/man/man1
	@echo "++++++++++ m3cc ++++++++++"
	@test -d ${WRKSRC}/m3cc/FreeBSD2 || ${MKDIR} ${WRKSRC}/m3cc/FreeBSD2
	@cd ${WRKSRC}/m3cc/FreeBSD2; \
	    ../gcc/configure i486-unknown-freebsd; \
	    make m3cgc1 CC="${CC}" CFLAGS="${CFLAGS}"; \
	    ${CP} -p m3cgc1 ${temp_prefix}/${libdir}
	@echo "++++++++++ everything else ++++++++++"
	@cd ${WRKSRC}/m3; \
	    LD_LIBRARY_PATH=${temp_prefix}/${libdir}:$$LD_LIBRARY_PATH; \
	    PATH=${temp_prefix}/bin:$$PATH; \
	    export LD_LIBRARY_PATH PATH; \
	    m3build

pre-install:
	@echo "Checking for conflicting shared libraries"
	@PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

do-install:
	@echo "Installing shared libraries"
	@cd ${temp_prefix}; \
	    umask 022; \
	    grep '^lib/m3/' ${PLIST}.real | \
		cpio -dump -R ${BINOWN}.${BINGRP} ${PREFIX}
	@cd ${PREFIX}; \
	    grep '^lib/m3/' ${PLIST}.real | xargs chmod go=u-w; \
	    find -X lib/m3 -type d | xargs chown ${BINOWN}.${BINGRP}; \
	    find -X lib/m3 -type d | xargs chmod 755
	@echo "Installing copyright notice"
	@if [ ! -d ${PREFIX}/share/modula-3-lib ]; then \
	    ${MKDIR} ${PREFIX}/share/modula-3-lib; \
	    chmod 755 ${PREFIX}/share/modula-3-lib; \
	fi
	@${INSTALL_DATA} ${WRKSRC}/m3/src/COPYRIGHT \
	    ${PREFIX}/share/modula-3-lib
	@if [ ! -f ${startup_script} ]; then \
	    echo "Installing ${startup_script} file"; \
	    test -d ${startup_dir} || ${MKDIR} ${startup_dir}; \
	    echo "#!/bin/sh" > ${startup_script}; \
	    echo "echo -n ' Modula-3'" >> ${startup_script}; \
	    echo "/sbin/ldconfig -m ${PREFIX}/lib/m3/FreeBSD2" \
		>> ${startup_script}; \
	    chmod 755 ${startup_script}; \
	fi
	@echo "Running ldconfig"
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib/m3/FreeBSD2

.include <bsd.port.mk>
