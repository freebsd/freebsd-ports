# New ports collection makefile for:    crossm68k
# Version required:     1.4
# Date created:         26 Mar 96
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $Id$
#

DISTNAME=	gcc-2.7.2.2
PKGNAME=	crossm68k-1.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cygnus.com/pub/newlib/	\
		${MASTER_SITE_GNU}
DISTFILES=	binutils-2.8.1.tar.gz	\
		${DISTNAME}.tar.gz	\
		newlib-1.8.0.tar.gz

PATCH_SITES=	ftp://sunsite.unc.edu/pub/gnu/    \
		ftp://ftp.informatik.hu-berlin.de/pub/gnu/gcc/  \
		${MASTER_SITE_GNU}
PATCHFILES=	crossgcc-${DISTNAME}.patch	\
		gcc-2.7.2.2-2.7.2.3.diff.gz
PATCH_DIST_STRIP=-p1 --directory=${WRKSRC}/gcc

MAINTAINER=	jhicks@atlanta.glenayre.com

NO_PACKAGE=	please compile locally
WRKSRC=		${WRKDIR}/src
USE_GMAKE=	yes
GNU_CONFIGURE=  yes

TARGET=		m68k-coff
CONFIGURE_ARGS= --with-gnu-as --target=${TARGET}

MAN1=	${TARGET}-ar.1	${TARGET}-nm.1 ${TARGET}-objdump.1		\
	${TARGET}-ranlib.1 ${TARGET}-size.1 ${TARGET}-strings.1		\
	${TARGET}-strip.1 ${TARGET}-objcopy.1 ${TARGET}-nlmconv.1	\
	${TARGET}-c++filt.1 configure.1 ${TARGET}-as.1 ${TARGET}-ld.1	\
	${TARGET}-g++.1 ${TARGET}-gcc.1 cccp.1

post-extract:
	(cd $(WRKDIR); sh ${SCRIPTDIR}/one-tree-1.4.sh)

.include <bsd.port.mk>
