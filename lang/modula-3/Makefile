# New ports collection makefile for:	modula-3
# Date created:		18 Mar 1996
# Whom:			John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	modula-3
PORTVERSION=	3.6
CATEGORIES=	lang
DISTFILES=

MAINTAINER=	jdp@polstra.com

DEPENDS=	${PORTSDIR}/lang/modula-3-lib:install

WRKSRC!=	echo `dirname ${WRKDIRPREFIX}${.CURDIR}`/modula-3-lib/work
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
.ifdef WITHOUT_X11
PLIST=		${WRKDIR}/pkg-plist.noX11
.else
pre-fetch:
	@${ECHO_MSG} "To build this port without X11, define \"WITHOUT_X11\"."

PLIST=		${WRKDIR}/pkg-plist
MAN1+=		formsedit.1 replayheap.1 showheap.1 shownew.1 showthread.1
.endif

do-install:
	@${ECHO_MSG} "Deleting extraneous cruft"
	@cd ${temp_prefix}/lib/m3/pkg; \
	    ${RM} -rf m3 m3front m3middle m3linker
	@cd ${temp_prefix}/lib/m3/FreeBSD2; \
	    ${RM} -f libm3front.so.*.* libm3link.so.*.* libm3middle.so.*.*
	@${ECHO_MSG} "Installing files in \"${PREFIX}\""
	@cd ${temp_prefix}; \
	    umask 022; \
	    ${SED} -e "/^@/d" -e "/m3build-/d" -e "s/\.gz$$//" \
		-e "/^share/d" ${PLIST}.real | \
		cpio -dump -R ${BINOWN}.${BINGRP} ${PREFIX}
	@cd ${temp_prefix}/man/man1; \
	    umask 022; \
	    ${ECHO} ${MAN1} | perl -pe 's/ /\n/g' | \
		cpio -dump -R ${MANOWN}.${MANGRP} ${PREFIX}/man/man1
	@${ECHO_MSG} "Fixing absolute pathnames in installed files"
	@${SH} ${SCRIPTDIR}/fix_pathnames ${temp_prefix} ${PREFIX}
	@${ECHO_MSG} "Rebuilding and shipping m3build with correct pathnames"
	@cd ${WRKSRC}/m3/m3build; \
	    LD_LIBRARY_PATH=${PREFIX}/lib/m3/FreeBSD2:$$LD_LIBRARY_PATH; \
	    PATH=${PREFIX}/bin:$$PATH; \
	    export LD_LIBRARY_PATH PATH; \
	    umask 022; \
	    ${RM} -rf FreeBSD2; \
	    ${MKDIR} FreeBSD2; \
	    cd FreeBSD2; \
	    quake -D_bootstrap -D_all -DPACKAGE_DIR=${WRKSRC}/m3/m3build \
		-DPACKAGE=m3build -DBUILD_DIR=FreeBSD2 \
		${PREFIX}/lib/m3/pkg/m3build/templates/FreeBSD2 \
		${WRKSRC}/m3/m3build/src/m3makefile; \
	    ./m3ship
	@${ECHO_MSG} "Rebuilding and shipping m3configvars with correct pathnames"
	@cd ${WRKSRC}/m3/m3configvars; \
	    LD_LIBRARY_PATH=${PREFIX}/lib/m3/FreeBSD2:$$LD_LIBRARY_PATH; \
	    export LD_LIBRARY_PATH; \
	    PATH=${PREFIX}/bin:$$PATH; \
	    export PATH; \
	    umask 022; \
	    ${RM} -rf FreeBSD2; \
	    m3build; \
	    m3ship
	@${ECHO_MSG} "Installing copyright notice"
	@if [ ! -d ${PREFIX}/share/modula-3 ]; then \
	    ${MKDIR} ${PREFIX}/share/modula-3; \
	    ${CHMOD} 755 ${PREFIX}/share/modula-3; \
	fi
	@${INSTALL_DATA} ${WRKSRC}/m3/src/COPYRIGHT ${PREFIX}/share/modula-3
	@${ECHO_MSG} "Stripping executables"
	@cd ${temp_prefix}; \
	    find bin -type f ! -name recordheap |\
		(cd ${PREFIX}; xargs ${SH} ${SCRIPTDIR}/maybe-strip)
	@cd ${PREFIX}/lib/m3/FreeBSD2; strip m3 m3cgc1 m3mkdir
	@cd ${PREFIX}/bin; \
	    ${LN} -f m3build m3build-${major}
	@${ECHO_MSG} "Fixing file permissions"
	@cd ${PREFIX}; \
	    ${SED} -e "/^@/d" -e "s/\.gz$$//" ${PLIST}.real |\
		xargs ${CHOWN} ${BINOWN}.${BINGRP}; \
	    ${SED} -e "/^@/d" -e "s/\.gz$$//" ${PLIST}.real |\
		xargs ${CHMOD} go=u-w; \
	    find -X lib/m3 -type d | xargs ${CHOWN} ${BINOWN}.${BINGRP}; \
	    find -X lib/m3 -type d | xargs ${CHMOD} 755
	@${ECHO_MSG} "Running ldconfig"
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib/m3/FreeBSD2

.include <bsd.port.mk>
