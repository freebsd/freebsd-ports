# New ports collection makefile for:	modula-3
# Version required:	3.6
# Date created:		18 Mar 1996
# Whom:			John Polstra <jdp@polstra.com>
#
# $Id: Makefile,v 1.7 1996/10/29 23:14:05 jdp Exp $
#

DISTNAME=	modula-3-3.6
CATEGORIES+=	lang
DISTFILES=

MAINTAINER=	jdp@polstra.com

DEPENDS=	${PORTSDIR}/lang/modula-3-lib

WRKSRC=		${PORTSDIR}/lang/modula-3-lib/work
NO_WRKDIR=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

# Keep these in sync with the PLIST and with the library version numbers
# in the modula-3-lib port.
major=		4
minor=		0

# The Modula-3 build process insists on installing each individual
# component immediately after that component is built.  To avoid having
# to do the entire build as root, we arrange for everything to first
# be "installed" into the following directory, which we own.
temp_prefix=	${WRKSRC}/installed

do-extract:
	@${DO_NADA}

checksum:
	@${DO_NADA}

do-install:
	@echo "Deleting extraneous cruft"
	@cd ${temp_prefix}/lib/m3/pkg; \
	    rm -rf m3 m3front m3middle m3linker
	@cd ${temp_prefix}/lib/m3/FreeBSD2; \
	    rm -f libm3front.so.*.* libm3link.so.*.* libm3middle.so.*.*
	@echo "Installing files in \"${PREFIX}\""
	@cd ${temp_prefix}; \
	    umask 022; \
	    sed -e "/^@/d" -e "/m3build-/d" -e "s/\.gz$$//" ${PKGDIR}/PLIST | \
		cpio -dump -R ${BINOWN}.${BINGRP} ${PREFIX}
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
	@echo "Rebuilding and shipping m3configvars with correct pathnames"
	@cd ${WRKSRC}/m3/m3configvars; \
	    LD_LIBRARY_PATH=${PREFIX}/lib/m3/FreeBSD2:$$LD_LIBRARY_PATH; \
	    export LD_LIBRARY_PATH; \
	    PATH=${PREFIX}/bin:$$PATH; \
	    export PATH; \
	    umask 022; \
	    rm -rf FreeBSD2; \
	    m3build; \
	    m3ship
	@echo "Stripping executables"
	@cd ${temp_prefix}; \
	    find bin -type f ! -name recordheap | (cd ${PREFIX}; xargs strip)
	@cd ${PREFIX}/lib/m3/FreeBSD2; strip m3 m3cgc1 m3mkdir
	@cd ${PREFIX}/bin; \
	    ln -f m3build m3build-${major}; \
	    ln -f m3build m3build-${major}.${minor}
.if !defined(NOMANCOMPRESS)
	@echo "Compressing manual pages"
	@cd ${temp_prefix}; \
	    find man -type f | (cd ${PREFIX}; xargs gzip -9nf)
.endif
	@echo "Fixing file permissions"
	@cd ${PREFIX}; \
	    grep -v "^@" ${PKGDIR}/PLIST | xargs chown ${BINOWN}.${BINGRP}; \
	    grep -v "^@" ${PKGDIR}/PLIST | xargs chmod go=u-w; \
	    find -X lib/m3 -type d | xargs chown ${BINOWN}.${BINGRP}; \
	    find -X lib/m3 -type d | xargs chmod 755
	@echo "Running ldconfig"
	@/sbin/ldconfig -m ${PREFIX}/lib/m3/FreeBSD2

.include <bsd.port.mk>
