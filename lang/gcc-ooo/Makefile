# ex:ts=8
# Ports collection makefile for:	egcs
# Version required: 			1998-09-14
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $Id: Makefile,v 1.54 1999/04/08 19:05:43 billf Exp $
#

DISTNAME=	egcs-1.1.2
CATEGORIES=	lang
MASTER_SITES=	ftp://go.cygnus.com/pub/ftp.cygnus.com/egcs/releases/egcs-1.1.2/ \
		ftp://ftp.crc.ca/pub/packages/egcs/egcs-1.1.2/ \
		ftp://ftp.funet.fi/mirrors/ftp.cygnus.com/pub/egcs/releases/egcs-1.1.2/ \
		ftp://egcs.cygnus.com/pub/egcs/releases/egcs-1.1.2/ \
		ftp://ftp.nluug.nl/pub/languages/egcs/releases/egcs-1.1.2/ \
		ftp://ftp.iij.ad.jp/pub/egcs/releases/egcs-1.1.2/ \
		ftp://ftp.fu-berlin.de/unix/languages/egcs/releases/egcs-1.1.2/ \
		ftp://cambridge.cygnus.com/pub/egcs/releases/egcs-1.1.2/
DISTFILES=	egcs-core-1.1.2${EXTRACT_SUFX} egcs-g++-1.1.2${EXTRACT_SUFX} \
		egcs-g77-1.1.2${EXTRACT_SUFX} egcs-objc-1.1.2${EXTRACT_SUFX}

MAINTAINER=	obrien@FreeBSD.org

WWW_SITE=	http://egcs.cygnus.com/

FORBIDDEN=	repository copy of lang/egcs, awaiting upgrade

USE_BZIP2=	yes

.include <bsd.port.pre.mk>

EGCS_REV=	egcs-2.91.66
LIBSTDCPP_REV=	2.9.0

.if ${PORTOBJFORMAT} == "elf"
.if ${MACHINE_ARCH} == "i386"
PLIST=		${WRKDIR}/PLIST
.endif
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsdaout${OSREL}
.endif

PLIST_SUB=	EGCS_REV=${EGCS_REV} GNU_HOST=${CONFIGURE_TARGET}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-gnu-as --with-gnu-ld \
		--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/include/g++
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+= --enable-shared
.endif
ALL_TARGET=	bootstrap
MAN1=		cccp.1 g++.1 g77.1 gcc.1

pre-patch:
	@${MV} ${WRKSRC}/gcc/config/i386/t-freebsd ${WRKSRC}/gcc/config/
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd.h ${WRKSRC}/gcc/config/i386/freebsd-aout.h
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd-elf.h ${WRKSRC}/gcc/config/i386/freebsd.h
	@${CP} ${FILESDIR}/alpha-freebsd-elf.h ${WRKSRC}/gcc/config/alpha/freebsd-elf.h
	@${CP} ${FILESDIR}/alpha-freebsd.h ${WRKSRC}/gcc/config/alpha/freebsd.h

pre-configure:
	@# Keep from running `autoconf' and `autoheader' since we modified
	@# configure.in by patching it.
	@touch ${WRKSRC}/gcc/configure
	@touch ${WRKSRC}/gcc/cstamp-h.in
	@(MAJ=`sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${SED} -e "s:__FreeBSD__:__FreeBSD__=$${MAJ}:" ${FILESDIR}/freebsd.h \
		>${WRKSRC}/gcc/config/freebsd.h )
.if ${PORTOBJFORMAT} == "elf" && ${MACHINE_ARCH} == "i386"
	@${SED} -e 's/^@comment ELF-only://' ${PKGDIR}/PLIST >${PLIST}
.endif

pre-install:
	${MKDIR} ${PREFIX}/info

post-install:
	@${RM} -f ${PREFIX}/bin/c++
	@${MV} -f ${PREFIX}/bin/c++filt ${PREFIX}/bin/g++filt
	@(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ \
	${PREFIX}/bin/g++filt ${PREFIX}/bin/g77 ${PREFIX}/bin/gcov \
	${PREFIX}/bin/protoize ${PREFIX}/bin/unprotoize \
	${PREFIX}/bin/${CONFIGURE_TARGET}-gcc \
	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/cc1 \
	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/cc1obj \
	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/cc1plus \
	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/cpp \
	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/collect2 \
	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/f771 ; \
		do strip $$prog ; \
		done)
	ln -f ${PREFIX}/bin/gcc ${PREFIX}/bin/egcc
	ln -f ${PREFIX}/bin/g++ ${PREFIX}/bin/eg++
	${MV} ${PREFIX}/lib/libiberty.a  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}
	${MV} -f ${PREFIX}/lib/libstdc++.a  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/libstdc++.a
.if defined(WANT_SHAREDLIBS)
	${MV} -f ${PREFIX}/lib/libstdc++.so*  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}
.endif
	if [ ! -f ${PREFIX}/info/dir ]; then \
	    ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in cpp g77 gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor

.include <bsd.port.post.mk>
