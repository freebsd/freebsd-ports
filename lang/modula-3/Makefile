# New ports collection makefile for:	modula-3
# Version required:	3.6
# Date created:		18 Mar 1996
# Whom:			John Polstra <jdp@polstra.com>
#
# $Id: Makefile,v 1.27 1998/12/04 07:23:01 asami Exp $
#

DISTNAME=	modula-3-3.6
CATEGORIES=	lang
DISTFILES=

MAINTAINER=	jdp@polstra.com

DEPENDS=	${PORTSDIR}/lang/modula-3-lib:install

WRKSRC=		${WRKDIRPREFIX}${PORTSDIR}/lang/modula-3-lib/work
NO_CHECKSUM=	yes
NO_BUILD=	yes
MAN1=		analyze_coverage.1 m3browser.1 m3build.1 \
		m3bundle.1 m3pp.1 m3ship.1 m3tohtml.1 \
		m3totex.1 m3where.1 quake.1 recordheap.1
SCRIPTS_ENV+=	MAJOR=${major} PKGDIR=${PKGDIR} PLIST=${PLIST}

# Shared library major version number.  Keep this in sync with the
# modula-3-lib port.
major=		6

# The Modula-3 build process insists on installing each individual
# component immediately after that component is built.  To avoid having
# to do the entire build as root, we arrange for everything to first
# be "installed" into the following directory, which we own.
temp_prefix=	${WRKSRC}/installed

# Support building on systems with or without X11 installed.
.ifdef NO_X11
PLIST=		${WRKDIR}/PLIST.noX11
.else
pre-fetch:
	@echo "To build this port without X11, define \"NO_X11\"."

PLIST=		${WRKDIR}/PLIST
MAN1+=		formsedit.1 replayheap.1 showheap.1 shownew.1 showthread.1
.endif

do-install:
	@echo "Deleting extraneous cruft"
	@cd ${temp_prefix}/lib/m3/pkg; \
	    rm -rf m3 m3front m3middle m3linker
	@cd ${temp_prefix}/lib/m3/FreeBSD2; \
	    rm -f libm3front.so.*.* libm3link.so.*.* libm3middle.so.*.*
	@echo "Installing files in \"${PREFIX}\""
	@cd ${temp_prefix}; \
	    umask 022; \
	    sed -e "/^@/d" -e "/m3build-/d" -e "s/\.gz$$//" \
		-e "/^share/d" ${PLIST}.real | \
		cpio -dump -R ${BINOWN}.${BINGRP} ${PREFIX}
	@cd ${temp_prefix}/man/man1; \
	    umask 022; \
	    ${ECHO} ${MAN1} | perl -pe 's/ /\n/g' | \
		cpio -dump -R ${MANOWN}.${MANGRP} ${PREFIX}/man/man1
	@echo "Fixing absolute pathnames in installed files"
	@${SH} ${SCRIPTDIR}/fix_pathnames ${temp_prefix} ${PREFIX}
	@echo "Rebuilding and shipping m3build with correct pathnames"
	@cd ${WRKSRC}/m3/m3build; \
	    LD_LIBRARY_PATH=${PREFIX}/lib/m3/FreeBSD2:$$LD_LIBRARY_PATH; \
	    PATH=${PREFIX}/bin:$$PATH; \
	    export LD_LIBRARY_PATH PATH; \
	    umask 022; \
	    rm -rf FreeBSD2; \
	    ${MKDIR} FreeBSD2; \
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
	@echo "Installing copyright notice"
	@if [ ! -d ${PREFIX}/share/modula-3 ]; then \
	    ${MKDIR} ${PREFIX}/share/modula-3; \
	    chmod 755 ${PREFIX}/share/modula-3; \
	fi
	@${INSTALL_DATA} ${WRKSRC}/m3/src/COPYRIGHT ${PREFIX}/share/modula-3
	@echo "Stripping executables"
	@cd ${temp_prefix}; \
	    find bin -type f ! -name recordheap |\
		(cd ${PREFIX}; xargs ${SH} ${SCRIPTDIR}/maybe-strip)
	@cd ${PREFIX}/lib/m3/FreeBSD2; strip m3 m3cgc1 m3mkdir
	@cd ${PREFIX}/bin; \
	    ln -f m3build m3build-${major}
	@echo "Fixing file permissions"
	@cd ${PREFIX}; \
	    sed -e "/^@/d" -e "s/\.gz$$//" ${PLIST}.real |\
		xargs chown ${BINOWN}.${BINGRP}; \
	    sed -e "/^@/d" -e "s/\.gz$$//" ${PLIST}.real |\
		xargs chmod go=u-w; \
	    find -X lib/m3 -type d | xargs chown ${BINOWN}.${BINGRP}; \
	    find -X lib/m3 -type d | xargs chmod 755
	@echo "Running ldconfig"
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib/m3/FreeBSD2

.include <bsd.port.mk>
