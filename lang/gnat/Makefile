# -*- Mode: Makefile -*-
# Port of:              GNU Ada gnat
# Version required:     2.03
# Space required:       >= 23MB
# Date created:         Sat Mar 18 02:16:45 1995
# Porter:               nils@guru.ims.uni-stuttgart.de
#
# $Id$

DISTNAME=       gnat-2.03-src
PKGNAME=        gnat-2.03
CATEGORIES+=	languages
MASTER_SITES=   ftp://cs.nyu.edu/pub/gnat/
EXTRACT_SUFX=	.tar.gz

# You need a compiler who calls an existing gnat compiler:
CC = gcc-2.6.3

# You have to tell me where your gcc 2.6.3 source is located
COMPILERSOURCE = /usr/src/gnu/usr.bin/cc
#COMPILERSOURCE = /cdrom/filesys/usr/src/gnu/usr.bin/cc

# Which version of gcc do we have? Must be either 2.6.2 or 2.6.3.
CCVERSION= 2.6.3

USE_GMAKE= true

# This is for the package: target. I decided to install the Ada compiler
# as /usr/libexec/gnat1, the rest in /usr/local/{bin,adainclude,adalib}.
PREFIX		= /usr

WRKDIR          = ${.CURDIR}/work
CONFIGURE_COOKIE= ${WRKDIR}/.configure_done
PREBUILD_COOKIE = ${WRKDIR}/.prebuild_done
BUILD_COOKIE    = ${WRKDIR}/.build_done
INSTALL_COOKIE  = ${WRKDIR}/.install_done

pre-build: ${PREBUILD_COOKIE}
${PREBUILD_COOKIE}:
	@echo "===>  Building patched gcc library for ${DISTNAME}"
	cd ${WRKSRC}/gcc && \
	   ${MAKE} CC="${CC} -I. -I${COMPILERSOURCE}/include" \
		   COMPILERSOURCE="${COMPILERSOURCE}" 
	@${TOUCH} ${TOUCHFLAGS} ${PREBUILD_COOKIE}

build: configure pre-build ${BUILD_COOKIE}
${BUILD_COOKIE}:
	@echo "===>  Building for ${DISTNAME}"
	cd ${WRKSRC}/ada; \
	   ${GMAKE} CC="${CC}" COMPILERSOURCE="${COMPILERSOURCE}"
	@${TOUCH} ${TOUCH_FLAGS} ${BUILD_COOKIE}

configure: extract patch ${CONFIGURE_COOKIE}
${CONFIGURE_COOKIE}:
	@echo "===>  Configuring for ${DISTNAME}"
	@env CURDIR=${.CURDIR} DISTDIR=${DISTDIR} WRKDIR=${WRKDIR} \
	     WRKSRC=${WRKSRC} PATCHDIR=${PATCHDIR} SCRIPTDIR=${SCRIPTDIR} \
	     FILESDIR=${FILESDIR} PORTSDIR=${PORTSDIR} PREFIX=${PREFIX} \
	     DEPENDS="${DEPENDS}" \
	     COMPILERSOURCE="${COMPILERSOURCE}" CCVERSION="${CCVERSION}" \
	       ${SHELL} ${SCRIPTDIR}/configure; 
	@${TOUCH} ${TOUCH_FLAGS} ${CONFIGURE_COOKIE}

install: build ${INSTALL_COOKIE}
${INSTALL_COOKIE}:
	@echo "===>  Installing for ${DISTNAME}"
	@${MAKE} ${.MAKEFLAGS} pre-install
	@(cd ${WRKSRC}/ada; \
	${MAKE} PREFIX_DIR=${PREFIX} ${MAKE_FLAGS} ${MAKEFILE} \
		${INSTALL_TARGET})
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

.include <bsd.port.mk>
