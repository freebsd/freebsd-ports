# ex:ts=8
# New ports collection makefile for:	egcs
# Version required:	1998-02-21
# Date created:		9 Jan 1998
# Whom:			John Polstra <jdp@polstra.com>
#
# $Id: Makefile,v 1.12 1998/03/17 21:10:40 jdp Exp $
#

DISTNAME=	egcs-1.0.2
CATEGORIES=	lang
MASTER_SITES=	ftp://egcs.cygnus.com/pub/egcs/releases/egcs-1.0.2/  \
		ftp://cambridge.cygnus.com/pub/egcs/releases/egcs-1.0.2/ \
		ftp://ftp.fu-berlin.de/unix/languages/egcs/releases/egcs-1.0.2/

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
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.90.27/cc1 \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.90.27/cc1obj \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.90.27/cc1plus \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.90.27/cpp \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.90.27/f771 \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.90.27/ld ; \
		do strip $$prog ; \
		done)
	if [ ! -f ${PREFIX}/info/dir ]; then \
	    ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in cpp g77 gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
