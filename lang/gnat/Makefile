# New ports collection makefile for:	GNU Ada gnat
# Version required:     3.09
# Date created:         Sat Mar 18 02:16:45 1995
# Porter (original):	nils@guru.ims.uni-stuttgart.de
# Porter (version 3):	maurice@serc.rmit.edu.au
#
# $Id: Makefile,v 1.12 1997/09/25 08:47:35 asami Exp $

# Note: 
# - FreeBSD tasking libraries created by Dan Eischen have been incorportated
#   into this edition
# - The default names of a number of binaries have been altered to avoid
#   conflict with other gcc based products. Standard names can be provided using
#   symbolic links.

DISTNAME=       gnat-3.09-src
PKGNAME=        gnat-3.09
CATEGORIES=	lang
MASTER_SITES=   ftp://cs.nyu.edu/pub/gnat/ \
		${MASTER_SITE_GNU}
DISTFILES=      gnat-3.09-src.tar.gz gcc-2.7.2.1.tar.gz

MAINTAINER=	maurice@serc.rmit.edu.au

.if !exists(/usr/local/bin/gnatf)
BROKEN=		"requires existing gnat compiler"
.endif
.if !exists(/usr/local/bin/adagcc)
BROKEN=		"requires patched gcc compiler"
.endif
# You need a compiler who calls an existing gnat compiler (3.08 or greater):
# if you have one, if you have one put it here, otherwise,
# you will need to install from a package first

MAN1=		adagcc.1 cccp.1

# Make sure we use the patched gcc compiler
CC = /usr/local/bin/adagcc

# Which version of gcc do we have? Must be 2.7.2.1
CCVERSION= 2.7.2.1

# which language set 
LANG = c ada

pre-patch:
	@echo "===>  Applying FreeBSD patches to gcc for ${DISTNAME}"
	-(  cd ${WRKDIR}/gcc-2.7.2.1; \
	   patch -s -f < ${PATCHDIR}/patch-freebsdgcc; )
	@echo "===>  Fixing ${DISTNAME} patches to gcc"
	-(  cd ${WRKSRC}/src; \
	   patch -s -f < ${PATCHDIR}/patch-gnat; )
	@echo "===>  Patching gcc for ${DISTNAME}"
	-(  cd ${WRKDIR}/gcc-2.7.2.1; \
	   patch -s -f < ${WRKSRC}/src/gcc-272.dif; )
	(cd ${WRKDIR}/gcc-2.7.2.1; \
	   cp -R ${WRKSRC}/src/ada ada; )

pre-configure:
	(cd ${WRKDIR}/gcc-2.7.2.1/ada; \
	   touch treeprs.ads a-[es]info.h nmake.ad[bs] )

do-build:
	(cd ${WRKDIR}/gcc-2.7.2.1; ${GMAKE} CC="${CC}" CFLAGS="-O2" LANGUAGES="${LANG}" )
	(cd ${WRKDIR}/gcc-2.7.2.1; ${GMAKE} CC="${CC}" CFLAGS="-O2" LANGUAGES="${LANG}" bootstrap )
	(cd ${WRKDIR}/gcc-2.7.2.1; ${GMAKE} CC="${CC}" CFLAGS="-O2" gnatlib_and_tools )

# patch the src that we are going to use and copy any additional files
# required into the correct locations
# use version specific patches where necessary
do-patch:
	(cd ${WRKDIR}; \
	   FILES="${PATCHDIR}/patch-[a-z][a-z]" ; \
	   SORTEDFILES=`echo $$FILES | tr " " "\n" | sort` ; \
	   for i in $$SORTEDFILES ; do \
	      echo Applying ---- $$i ;\
	      patch -s < $$i ;\
	   done )
	(cd ${FILESDIR}; \
	   for i in *.adb *.ads ; do \
	     cp $$i ${WRKDIR}/gcc-2.7.2.1/ada; \
	   done )

do-configure:
	(cd ${WRKDIR}/gcc-2.7.2.1; \
	   ./configure --prefix=${PREFIX} --program-prefix=ada )

do-install:
	(cd ${WRKDIR}/gcc-2.7.2.1; \
	   ${GMAKE} CC="${CC}" LANGUAGES="${LANG}" install )

post-install:
	@(echo "-----------------------------------------------------------" )
	@(echo "" )
	@(echo "For information about using the tasking library please read" )
	@(echo "the README.Tasking file" )
	@(echo "" )
	@(echo "-----------------------------------------------------------" )
	@(echo "" )

.include <bsd.port.mk>
