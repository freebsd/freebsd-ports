# New ports collection makefile for:	modula-3
# Version required:	3.5.3
# Date created:		18 Mar 1996
# Whom:			John Polstra <jdp@polstra.com>
#
# $Id: Makefile,v 1.3 1996/09/10 05:23:49 jdp Exp $
#

DISTNAME=	modula-3-3.5.3
PKGNAME=	modula-3-3.5.3.2
CATEGORIES+=	lang
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/DEC/Modula-3/release-3.5.3/
DISTFILES=	boot-FreeBSD2.tar.gz m3cc.tar.gz m3.tar.gz

MAINTAINER=	jdp@polstra.com

NO_WRKSUBDIR=	yes
EXTRACT_BEFORE_ARGS=	--exclude "*.orig" --exclude "*[-~]" -xzf

# Startup script, run an boot time
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
late_builds=	m3configvars llscan

post-extract:
	@cd ${WRKSRC}/boot-FreeBSD2; ln -sf ../m3cc .

# Make the effects of the patches available to the bootstrap compiler too.
post-patch:
	@cd ${WRKSRC}/boot-FreeBSD2/quake/src; \
	    ln -sf ../../../m3/quake/src/utils.c .
	@cd ${WRKSRC}/boot-FreeBSD2/m3core/FreeBSD2; \
	    ln -sf ../../../m3/m3core/src/runtime/FreeBSD2/RTHeapDepC.c .
	@cd ${WRKSRC}/boot-FreeBSD2/m3build/templates; \
	    ln -sf ../../../m3/m3build/templates/FreeBSD2 .; \
	    ln -sf ../../../m3/m3build/templates/PLATFORMS .

do-build:
	@test -d ${temp_prefix} || mkdir -p ${temp_prefix}
	@echo "Building bootstrap compiler"
	@cd ${WRKSRC}/boot-FreeBSD2; umask 022; ./m3boot
	@echo "Shipping bootstrap compiler"
	@cd ${WRKSRC}/boot-FreeBSD2; umask 022; ./m3ship
	@echo "Building and shipping the rest of the system"
	@cd ${WRKSRC}/m3; \
	    LD_LIBRARY_PATH=${temp_prefix}/lib/m3/FreeBSD2:$$LD_LIBRARY_PATH; \
	    export LD_LIBRARY_PATH; \
	    PATH=${temp_prefix}/bin:$$PATH; \
	    export PATH; \
	    umask 022; \
	    m3build

pre-install:
	@echo "Checking for conflicting shared libraries"
	@PREFIX=${PREFIX} /bin/sh ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

do-install:
	@echo "Setting owner and group of installed files"
	@/usr/sbin/chown -R ${BINOWN}.${BINGRP} ${temp_prefix}/*
	@echo "Copying files to ${PREFIX}"
	@cp -R -P -p ${temp_prefix}/* ${PREFIX}
	@echo "Fixing absolute pathnames in installed files"
	@/bin/sh scripts/fix_pathnames ${temp_prefix} ${PREFIX}
	@echo "Rebuilding and shipping m3build with correct pathnames"
	@cd ${WRKSRC}/m3/m3build; \
	    LD_LIBRARY_PATH=${PREFIX}/lib/m3/FreeBSD2:$$LD_LIBRARY_PATH; \
	    export LD_LIBRARY_PATH; \
	    PATH=${PREFIX}/bin:$$PATH; \
	    export PATH; \
	    umask 022; \
	    m3build -T ${PREFIX}/lib/m3/pkg/m3build/templates \
		-F ${PREFIX}/lib/m3/pkg/m3build/templates/COMMON.BOOT clean; \
	    m3build -T ${PREFIX}/lib/m3/pkg/m3build/templates \
		-F ${PREFIX}/lib/m3/pkg/m3build/templates/COMMON.BOOT; \
	    FreeBSD2/m3ship; \
	    rm -rf FreeBSD2
	@for i in ${late_builds}; do \
	    echo "Building and shipping $${i}"; \
	    cd ${WRKSRC}/m3/$${i}; \
	    LD_LIBRARY_PATH=${PREFIX}/lib/m3/FreeBSD2:$$LD_LIBRARY_PATH; \
	    export LD_LIBRARY_PATH; \
	    PATH=${PREFIX}/bin:$$PATH; \
	    export PATH; \
	    umask 022; \
	    m3build clean; \
	    m3build; \
	    m3ship; \
	    rm -rf FreeBSD2; \
	    done
	@echo "Stripping executables"
	@for i in `cat ${FILESDIR}/files.strip`; do \
	    test ! -f ${PREFIX}/$${i} || strip ${PREFIX}/$${i}; \
	    done
.if !defined(NOMANCOMPRESS)
	@echo "Compressing manual pages"
	@for i in `cat ${FILESDIR}/files.compress`; do \
	    test ! -f ${PREFIX}/$${i} || gzip -9nf ${PREFIX}/$${i}; \
	    done
.endif
	@if [ ! -f ${startup_script} ]; then \
	    echo "Installing ${startup_script} file."; \
	    test -d ${startup_dir} || mkdir -p ${startup_dir}; \
	    echo "#!/bin/sh" > ${startup_script}; \
	    echo "/sbin/ldconfig -m ${PREFIX}/lib/m3/FreeBSD2" >> \
		    ${startup_script}; \
	    chmod 755 ${startup_script}; \
	fi
	@echo "Running ldconfig"
	@/sbin/ldconfig -m ${PREFIX}/lib/m3/FreeBSD2

.include <bsd.port.mk>
