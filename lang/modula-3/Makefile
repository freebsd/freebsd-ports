# New ports collection makefile for:	modula-3
# Version required:	3.5.3
# Date created:		18 Mar 1996
# Whom:			John Polstra <jdp@polstra.com>
#
# $Id$
#

DISTNAME=	modula-3-3.5.3
CATEGORIES+=	languages
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/DEC/Modula-3/release-3.5.3/
DISTFILES=	boot-FreeBSD2.tar.gz m3cc.tar.gz m3.tar.gz

MAINTAINER=	jdp@polstra.com

NO_WRKSUBDIR=	yes
EXTRACT_BEFORE_ARGS=	--exclude "*.orig" -xzf

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
	cd ${WRKSRC}/boot-FreeBSD2; ln -sf ../m3cc .

do-build:
	@test -d ${temp_prefix} || mkdir -p ${temp_prefix}
	@echo "Building bootstrap compiler"
	@cd ${WRKSRC}/boot-FreeBSD2; ./m3boot
	@echo "Shipping bootstrap compiler"
	@cd ${WRKSRC}/boot-FreeBSD2; ./m3ship
	@echo "Building and shipping the rest of the system"
	@cd ${WRKSRC}/m3; \
	    LD_LIBRARY_PATH=${temp_prefix}/lib/m3/FreeBSD2:$$LD_LIBRARY_PATH; \
	    export LD_LIBRARY_PATH; \
	    PATH=${temp_prefix}/bin:$$PATH; \
	    export PATH; \
	    m3build

do-install:
	@test -d ${PREFIX} || mkdir -p ${PREFIX}
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
	@echo "Fixing permissions with mtree"
	@${MTREE_CMD} -e -U -f ${FILESDIR}/mtree.in -p ${PREFIX}
	@echo "Running ldconfig"
	@/sbin/ldconfig -m ${PREFIX}/lib/m3/FreeBSD2
	@echo "Be sure to add ${PREFIX}/lib/m3/FreeBSD2 to"
	@echo "  your ldconfig command in /etc/rc"

.include <bsd.port.mk>
