# -*- Mode: Makefile -*-
# Port of:              GNU Ada gnat
# Version required:     2.03
# Space required:       >= 23MB
# Date created:         Sat Mar 18 02:16:45 1995
# Porter:               nils@guru.ims.uni-stuttgart.de
#
# $Id: Makefile,v 1.3 1995/04/15 05:44:36 asami Exp $

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

pre-build:
	@echo "===>  Building patched gcc library for ${DISTNAME}"
	cd ${WRKSRC}/gcc && \
	   ${MAKE} CC="${CC} -I. -I${COMPILERSOURCE}/include" \
		   COMPILERSOURCE="${COMPILERSOURCE}" 

do-build:
	cd ${WRKSRC}/ada; \
	   ${GMAKE} CC="${CC}" COMPILERSOURCE="${COMPILERSOURCE}"

do-configure:
	@env CURDIR=${.CURDIR} DISTDIR=${DISTDIR} WRKDIR=${WRKDIR} \
	     WRKSRC=${WRKSRC} PATCHDIR=${PATCHDIR} SCRIPTDIR=${SCRIPTDIR} \
	     FILESDIR=${FILESDIR} PORTSDIR=${PORTSDIR} PREFIX=${PREFIX} \
	     DEPENDS="${DEPENDS}" \
	     COMPILERSOURCE="${COMPILERSOURCE}" CCVERSION="${CCVERSION}" \
	       ${SHELL} ${SCRIPTDIR}/configure; 

do-install:
	@${MAKE} ${.MAKEFLAGS} pre-install
	@(cd ${WRKSRC}/ada; \
	${MAKE} PREFIX_DIR=${PREFIX} ${MAKE_FLAGS} ${MAKEFILE} \
		${INSTALL_TARGET})

.include <bsd.port.mk>
