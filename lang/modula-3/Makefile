# New ports collection makefile for:	modula-3
# Version required:	3.6
# Date created:		18 Mar 1996
# Whom:			John Polstra <jdp@polstra.com>
#
# $Id: Makefile,v 1.4 1996/09/12 00:39:41 jdp Exp $
#

DISTNAME=	modula-3-3.6
CATEGORIES+=	lang
MASTER_SITES=	ftp://freefall.FreeBSD.ORG/pub/FreeBSD/LOCAL_PORTS/
DISTFILES=	m3-fbsd-src-3.6.tar.gz m3-fbsd-m3cc-3.6.tar.gz
# Note: Depending on what is already installed on the system, the code
# below may add some more DISTFILES.

MAINTAINER=	jdp@polstra.com

NO_WRKSUBDIR=	yes

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
startup_script=	${startup_dir}/m3.sh

# The Modula-3 build process insists on installing each individual
# component immediately after that component is built.  To avoid having
# to do the entire build as root, we arrange for everything to first
# be "installed" into the following directory, which we own.
temp_prefix=	${WRKDIR}/installed

# Some parts of the system depend on absolute pathnames into the
# installed tree.  Those parts have to be built after we have moved
# the tree to its final resting place.
late_builds=	m3configvars

post-extract:
	@${DO_NADA}
.if !empty(have_boot)
	@echo "Copying bootstrap modula-3 compiler from ${have_boot}"
	@/bin/sh ${SCRIPTDIR}/copy_files ${FILESDIR}/T.boot installed \
	    ${have_boot} ${WRKDIR}
.endif
.if !empty(have_gcc)
	@echo "Copying gcc sources from ${have_gcc}"
	@/bin/sh ${SCRIPTDIR}/copy_files ${FILESDIR}/T.gcc m3cc \
	    ${have_gcc} ${WRKDIR}
.endif

do-build:
	@test -d ${temp_prefix}/bin || mkdir -p ${temp_prefix}/bin
	@test -d ${temp_prefix}/man/man1 || mkdir -p ${temp_prefix}/man/man1
	@test -d ${temp_prefix}/lib/m3/pkg/m3build/templates || \
	    mkdir -p ${temp_prefix}/lib/m3/pkg/m3build/templates
	@echo "++++++++++ quake ++++++++++"
	@test -d ${WRKSRC}/m3/quake/FreeBSD2 || \
	    mkdir -p ${WRKSRC}/m3/quake/FreeBSD2
	@cd ${WRKSRC}/m3/quake/FreeBSD2; \
	    make -f ../src/makefile TARGET=FreeBSD2 COPT=-O CDEBUG= ; \
	    cp -p quake ${temp_prefix}/bin; \
	    cp -p ../src/quake.1 ${temp_prefix}/man/man1
	@echo "++++++++++ m3build ++++++++++"
	@cd ${WRKSRC}/m3/m3build; \
	    PATH=${temp_prefix}/bin:$$PATH ./build FreeBSD2; \
	    cp -p FreeBSD2/m3build FreeBSD2/m3ship FreeBSD2/m3where \
		${temp_prefix}/bin; \
	    cp -p FreeBSD2/m3mkdir ${temp_prefix}/lib/m3/FreeBSD2; \
	    cp -p templates/CLEANUP templates/COMMON templates/COMMON.BOOT \
		templates/FreeBSD2 templates/PLATFORMS templates/POSIX \
		${temp_prefix}/lib/m3/pkg/m3build/templates; \
	    cp -p FreeBSD2/m3build.1 FreeBSD2/m3ship.1 FreeBSD2/m3where.1 \
		${temp_prefix}/man/man1
	@echo "++++++++++ m3cc ++++++++++"
	@test -d ${WRKSRC}/m3cc/FreeBSD2 || mkdir -p ${WRKSRC}/m3cc/FreeBSD2
	@cd ${WRKSRC}/m3cc/FreeBSD2; \
	    ../gcc/configure i486-unknown-freebsd; \
	    make m3cgc1 CC=cc CFLAGS=-O; \
	    cp -p m3cgc1 ${temp_prefix}/lib/m3/FreeBSD2
	@echo "++++++++++ everything else ++++++++++"
	@cd ${WRKSRC}/m3; \
	    LD_LIBRARY_PATH=${temp_prefix}/lib/m3/FreeBSD2:$$LD_LIBRARY_PATH; \
	    PATH=${temp_prefix}/bin:$$PATH; \
	    export LD_LIBRARY_PATH PATH; \
	    m3build

pre-install:
	@echo "Checking for conflicting shared libraries"
	@PREFIX=${PREFIX} /bin/sh ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

do-install:
	@echo "Deleting extraneous cruft"
	@cd ${temp_prefix}/lib/m3/pkg; \
	    rm -rf m3 m3front m3middle m3linker
	@cd ${temp_prefix}/lib/m3/FreeBSD2; \
	    rm -f libm3front.so.*.* libm3link.so.*.* libm3middle.so.*.*
	@echo "Setting permissions of installed files"
	@/usr/sbin/chown -R ${BINOWN}.${BINGRP} ${temp_prefix}/*
	@chmod -R go=u-w ${temp_prefix}/*
	@echo "Copying files to ${PREFIX}"
	@cp -R -P -p ${temp_prefix}/* ${PREFIX}
	@echo "Fixing absolute pathnames in installed files"
	@/bin/sh ${SCRIPTDIR}/fix_pathnames ${temp_prefix} ${PREFIX}
	@echo "Rebuilding and shipping m3build with correct pathnames"
	@cd ${WRKSRC}/m3/m3build; \
	    LD_LIBRARY_PATH=${PREFIX}/lib/m3/FreeBSD2:$$LD_LIBRARY_PATH; \
	    PATH=${PREFIX}/bin:$$PATH; \
	    export LD_LIBRARY_PATH PATH; \
	    umask 022; \
	    rm -rf FreeBSD2; \
	    mkdir FreeBSD2; \
	    cd FreeBSD2; \
	    quake -D_bootstrap -D_all -DPACKAGE_DIR=${WRKSRC}/m3/m3build \
		-DPACKAGE=m3build -DBUILD_DIR=FreeBSD2 \
		${PREFIX}/lib/m3/pkg/m3build/templates/FreeBSD2 \
		${WRKSRC}/m3/m3build/src/m3makefile; \
	    ./m3ship
	@for i in ${late_builds}; do \
	    echo "Building and shipping $${i}"; \
	    cd ${WRKSRC}/m3/$${i}; \
	    LD_LIBRARY_PATH=${PREFIX}/lib/m3/FreeBSD2:$$LD_LIBRARY_PATH; \
	    export LD_LIBRARY_PATH; \
	    PATH=${PREFIX}/bin:$$PATH; \
	    export PATH; \
	    umask 022; \
	    rm -rf FreeBSD2; \
	    m3build; \
	    m3ship; \
	    done
	@echo "Stripping executables"
	@cd ${temp_prefix}; \
	    find bin -type f ! -name recordheap | (cd ${PREFIX}; xargs strip)
	@cd ${PREFIX}/lib/m3/FreeBSD2; strip m3 m3cgc1 m3mkdir
.if !defined(NOMANCOMPRESS)
	@echo "Compressing manual pages"
	@cd ${temp_prefix}; \
	    find man -type f | (cd ${PREFIX}; xargs gzip -9nf)
.endif
	@if [ ! -f ${startup_script} ]; then \
	    echo "Installing ${startup_script} file"; \
	    test -d ${startup_dir} || mkdir -p ${startup_dir}; \
	    echo "#!/bin/sh" > ${startup_script}; \
	    echo "echo -n ' Modula-3'" >> ${startup_script}; \
	    echo "/sbin/ldconfig -m ${PREFIX}/lib/m3/FreeBSD2" >> \
		    ${startup_script}; \
	    chmod 755 ${startup_script}; \
	fi
	@echo "Running ldconfig"
	@/sbin/ldconfig -m ${PREFIX}/lib/m3/FreeBSD2

.include <bsd.port.mk>
