# New ports collection makefile for:	modula-3-lib
# Date created:		28 Oct 1996
# Whom:			John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	modula-3-lib
PORTVERSION=	3.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	asami/LOCAL_PORTS
DISTFILES=	m3-fbsd-src-3.6.tar.gz \
		m3-fbsd-m3cc-3.6.tar.gz \
		m3-fbsd-m3ccelf-3.6.tar.gz \
		m3-fbsd-gcc-3.6.tar.gz
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

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400011
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-new-sigset-aa \
		${PATCHDIR}/extra-patch-new-sigset-ab \
		${PATCHDIR}/extra-patch-new-sigset-ac
.else
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-old-sigset-aa
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
.ifdef WITHOUT_X11
PLIST=		${WRKDIR}/pkg-plist.noX11
.else
pre-fetch:
	@${ECHO_MSG} "To build this port without X11, define \"WITHOUT_X11\"."

USE_XLIB=	yes
PLIST=		${WRKDIR}/pkg-plist
.endif

post-extract:
.if !empty(have_boot)
	@${ECHO_MSG} "Copying bootstrap modula-3 compiler from ${have_boot}"
	@${SH} ${SCRIPTDIR}/copy_files ${FILESDIR}/T.boot installed \
	    ${have_boot} ${WRKSRC}
.endif
	@cd ${WRKSRC}/m3cc/gcc; \
	    ${CHMOD} +x config.sub configure move-if-change

do-build:
	@test -d ${temp_prefix}/bin || ${MKDIR} ${temp_prefix}/bin
	@test -d ${temp_prefix}/man/man1 || ${MKDIR} ${temp_prefix}/man/man1
	@test -d ${temp_prefix}/lib/m3/pkg/m3build/templates || \
	    ${MKDIR} ${temp_prefix}/lib/m3/pkg/m3build/templates
	@${ECHO_MSG} "++++++++++ quake ++++++++++"
	@test -d ${WRKSRC}/m3/quake/FreeBSD2 || \
	    ${MKDIR} ${WRKSRC}/m3/quake/FreeBSD2
	@cd ${WRKSRC}/m3/quake/FreeBSD2; \
	    make -f ../src/makefile TARGET=FreeBSD2 COPT=-O CDEBUG= ; \
	    ${CP} -p quake ${temp_prefix}/bin; \
	    ${CP} -p ../src/quake.1 ${temp_prefix}/man/man1
	@${ECHO_MSG} "++++++++++ m3build ++++++++++"
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
	@${ECHO_MSG} "++++++++++ m3cc ++++++++++"
	@test -d ${WRKSRC}/m3cc/FreeBSD2 || ${MKDIR} ${WRKSRC}/m3cc/FreeBSD2
	@cd ${WRKSRC}/m3cc/FreeBSD2; \
	    ../gcc/configure i486-unknown-freebsd; \
	    make m3cgc1 CC="${CC}" CFLAGS="${CFLAGS}"; \
	    ${CP} -p m3cgc1 ${temp_prefix}/${libdir}
	@${ECHO_MSG} "++++++++++ everything else ++++++++++"
	@cd ${WRKSRC}/m3; \
	    LD_LIBRARY_PATH=${temp_prefix}/${libdir}:$$LD_LIBRARY_PATH; \
	    PATH=${temp_prefix}/bin:$$PATH; \
	    export LD_LIBRARY_PATH PATH; \
	    m3build

pre-install:
	@${ECHO_MSG} "Checking for conflicting shared libraries"
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${ECHO_MSG} "Installing shared libraries"
	@cd ${temp_prefix}; \
	    umask 022; \
	    ${GREP} '^lib/m3/' ${PLIST}.real | \
		cpio -dump -R ${BINOWN}.${BINGRP} ${PREFIX}
	@cd ${PREFIX}; \
	    ${GREP} '^lib/m3/' ${PLIST}.real | xargs ${CHMOD} go=u-w; \
	    find -X lib/m3 -type d | xargs ${CHOWN} ${BINOWN}.${BINGRP}; \
	    find -X lib/m3 -type d | xargs ${CHMOD} 755
	@${ECHO_MSG} "Installing copyright notice"
	@if [ ! -d ${PREFIX}/share/modula-3-lib ]; then \
	    ${MKDIR} ${PREFIX}/share/modula-3-lib; \
	    ${CHMOD} 755 ${PREFIX}/share/modula-3-lib; \
	fi
	@${INSTALL_DATA} ${WRKSRC}/m3/src/COPYRIGHT \
	    ${PREFIX}/share/modula-3-lib
	@if [ ! -f ${startup_script} ]; then \
	    ${ECHO_MSG} "Installing ${startup_script} file"; \
	    test -d ${startup_dir} || ${MKDIR} ${startup_dir}; \
	    ${INSTALL_SCRIPT} ${FILESDIR}/50.m3.sh ${startup_script}; \
	fi
	@${ECHO_MSG} "Running ldconfig"
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib/m3/FreeBSD2

.include <bsd.port.post.mk>
