# ex:ts=8
# Ports collection makefile for:	egcs
# Version required: 			1998-09-14
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $Id: Makefile,v 1.44 1999/02/09 18:24:50 obrien Exp $
#

DISTNAME=	egcs-1.1.1
CATEGORIES=	lang
MASTER_SITES=	ftp://go.cygnus.com/pub/ftp.cygnus.com/egcs/releases/egcs-1.1.1/ \
		ftp://ftp.funet.fi/mirrors/ftp.cygnus.com/pub/egcs/releases/egcs-1.1.1/ \
		ftp://egcs.cygnus.com/pub/egcs/releases/egcs-1.1.1/ \
		ftp://ftp.fu-berlin.de/unix/languages/egcs/releases/egcs-1.1.1/ \
		ftp://cambridge.cygnus.com/pub/egcs/releases/egcs-1.1.1/

MAINTAINER=	obrien@FreeBSD.org

USE_BZIP2=	yes

.include <bsd.port.pre.mk>

EGCS_REV=	egcs-2.91.60
LIBSTDCPP_REV=	2.9.0

.if ${PORTOBJFORMAT} == "elf"
PLIST=		${WRKDIR}/PLIST
GNUHOST=	${ARCH}-unknown-freebsd${OSREL}
.else
#GNUHOST=	${ARCH}-unknown-freebsdaout${OSREL}
GNUHOST=	${ARCH}-unknown-freebsdaout
.endif

PLIST_SUB=	EGCS_REV=${EGCS_REV} GNU_HOST=${GNUHOST}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-gnu-as --with-gnu-ld ${GNUHOST} \
		--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/include/g++
ALL_TARGET=	bootstrap
MAN1=		cccp.1 g++.1 g77.1 gcc.1

pre-patch:
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd.h ${WRKSRC}/gcc/config/i386/freebsd-aout.h
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd-elf.h ${WRKSRC}/gcc/config/i386/freebsd.h

pre-configure:
	@# Keep from running `autoconf' and `autoheader' since we modified
	@# configure.in by patching it.
	@touch ${WRKSRC}/gcc/configure
	@touch ${WRKSRC}/gcc/cstamp-h.in
	@(cd ${WRKSRC}/gcc/config/${ARCH}/ ; \
	MAJ=`sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${MV} freebsd-aout.h freebsd-aout.h.in ; \
	${SED} -e "s:__FreeBSD__:__FreeBSD__=$${MAJ}:" freebsd-aout.h.in \
		>freebsd-aout.h ; \
	${MV} freebsd.h freebsd.h.in ; \
	${SED} -e "s:__FreeBSD__:__FreeBSD__=$${MAJ}:" freebsd.h.in >freebsd.h )
.if ${PORTOBJFORMAT} == "elf"
	@${SED} -e 's/^@comment ELF-only://' ${PKGDIR}/PLIST >${PLIST}
.endif

pre-install:
	${MKDIR} ${PREFIX}/info
	${TOUCH} ${PREFIX}/info/dir

post-install:
	@${RM} -f ${PREFIX}/bin/c++
	@${MV} -f ${PREFIX}/bin/c++filt ${PREFIX}/bin/g++filt
	@(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ \
	${PREFIX}/bin/g++filt ${PREFIX}/bin/g77 ${PREFIX}/bin/gcov \
	${PREFIX}/bin/protoize ${PREFIX}/bin/unprotoize \
	${PREFIX}/bin/${GNUHOST}-gcc \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/cc1 \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/cc1obj \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/cc1plus \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/cpp \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/collect2 \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/f771 ; \
		do strip $$prog ; \
		done)
	ln -f ${PREFIX}/bin/gcc ${PREFIX}/bin/egcc
	ln -f ${PREFIX}/bin/g++ ${PREFIX}/bin/eg++
	${MV} ${PREFIX}/lib/libiberty.a  \
		${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}
	${MV} -f ${PREFIX}/lib/libstdc++.a  \
		${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/libstdc++.a
	if [ ! -f ${PREFIX}/info/dir ]; then \
	    ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in cpp g77 gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor

.include <bsd.port.post.mk>
