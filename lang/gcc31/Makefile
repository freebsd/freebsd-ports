# ex:ts=8
# New ports collection makefile for:	egcs
# Version required:	1998-02-21
# Date created:		9 Jan 1998
# Whom:			John Polstra <jdp@polstra.com>
#
# $Id: Makefile,v 1.17 1998/05/05 06:34:46 obrien Exp $
#

DISTNAME=	egcs-19980508
CATEGORIES=	lang
MASTER_SITES=	ftp://egcs.cygnus.com/pub/egcs/snapshots/1998-05-08/ \
		ftp://cambridge.cygnus.com/pub/egcs/snapshots/1998-05-08/ \
		ftp://ftp.fu-berlin.de/unix/languages/egcs/snapshots/1998-05-08/

MAINTAINER=	obrien@FreeBSD.org

MANUAL_PACKAGE_BUILD=	installs libstdc++.a which conflicts with system version

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-gnu-as --with-gnu-ld i386-unknown-freebsd
ALL_TARGET=	bootstrap
MAN1=		cccp.1 g++.1 g77.1 gcc.1

post-patch:
	@(cd ${WRKSRC}/gcc/config/i386/ ; \
	MAJ=`sysctl -n kern.osreldate | sed -e '/.....$$/s///'` ; \
	mv freebsd.h freebsd.h.in ; \
	sed -e "s:__FreeBSD__:__FreeBSD__=$${MAJ}:" freebsd.h.in >freebsd.h ; \
	mv freebsd-elf.h freebsd-elf.h.in ; \
	sed -e "s:__FreeBSD__:__FreeBSD__=$${MAJ}:" freebsd-elf.h.in >freebsd-elf.h)

post-install:
	@(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ ${PREFIX}/bin/c++ \
	${PREFIX}/bin/c++filt ${PREFIX}/bin/g77 ${PREFIX}/bin/gcov \
	${PREFIX}/bin/protoize ${PREFIX}/bin/unprotoize \
	${PREFIX}/bin/i386-unknown-freebsd-gcc \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.91.28/cc1 \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.91.28/cc1obj \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.91.28/cc1plus \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.91.28/cpp \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.91.28/collect2 \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.91.28/f771 ; \
		do strip $$prog ; \
		done)
	if [ ! -f ${PREFIX}/info/dir ]; then \
	    ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in cpp g77 gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
