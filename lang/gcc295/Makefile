# ex:ts=8
# Ports collection makefile for:	egcs
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.3
CATEGORIES=	lang java
MASTER_SITES=	ftp://egcs.cygnus.com/pub/egcs/releases/%SUBDIR%/  \
		${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	gcc/releases/${PKGNAME}
DISTFILES=	gcc-core-${GCC_REV}${EXTRACT_SUFX} \
		gcc-g++-${GCC_REV}${EXTRACT_SUFX} \
		gcc-g77-${GCC_REV}${EXTRACT_SUFX} \
		gcc-java-${GCC_REV}${EXTRACT_SUFX} \
		gcc-objc-${GCC_REV}${EXTRACT_SUFX}

MAINTAINER=	obrien@FreeBSD.org

USE_BZIP2=	yes

LATEST_LINK=	gcc295

.include <bsd.port.pre.mk>

GCC_REV=	${DISTNAME:S/gcc-//g:S/.test3//g}
TARGLIB=	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}
LIBSTDCPP_REV=	2100

.if ${PORTOBJFORMAT} == "aout"
CONFIGURE_TARGET=	${ARCH}-portbld-freebsdaout${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

PLIST_SUB+=	EGCS_REV=${GCC_REV} GNU_HOST=${CONFIGURE_TARGET}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-gnu-as --with-gnu-ld \
		--with-gxx-include-dir=${TARGLIB}/include/g++
#CONFIGURE_ARGS+=	--program-suffix=-2.95.3
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+= --enable-shared
.endif
.if defined(WANT_THREADS)
#	?is this an ObjC only thing?
CONFIGURE_ARGS+= --enable-threads=posix
.endif
ALL_TARGET=	bootstrap
MAN1=		cccp.1 g++295.1 g77.1 gcc295.1

pre-patch:
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd.h ${WRKSRC}/gcc/config/i386/freebsd-aout.h
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd-elf.h ${WRKSRC}/gcc/config/i386/freebsd.h

pre-configure:
	@(MAJ=`sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${SED} -e "s:__FreeBSD__[0-9=]*:__FreeBSD__=$${MAJ}:" ${FILESDIR}/freebsd.h \
		>${WRKSRC}/gcc/config/freebsd.h )
	@${CP} ${FILESDIR}/alpha-freebsd.h ${WRKSRC}/gcc/config/alpha/freebsd.h
	@# Keep from running `autoconf' and `autoheader' since we modified
	@# configure.in by patching it.
	@touch ${WRKSRC}/gcc/configure
	@touch ${WRKSRC}/gcc/cstamp-h.in

pre-install:
	${MKDIR} ${PREFIX}/info

post-install:
	@${RM} -f ${PREFIX}/bin/c++
	@${MV} -f ${PREFIX}/bin/c++filt ${PREFIX}/bin/g++filt
	@(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ \
		${PREFIX}/bin/g++filt ${PREFIX}/bin/g77 ${PREFIX}/bin/gcov \
		${PREFIX}/bin/protoize ${PREFIX}/bin/unprotoize \
		${PREFIX}/bin/${CONFIGURE_TARGET}-gcc \
		${TARGLIB}/cc1 \
		${TARGLIB}/cc1obj \
		${TARGLIB}/cc1plus \
		${TARGLIB}/cpp0 \
		${TARGLIB}/collect2 \
		${TARGLIB}/f771 ; \
	do \
		strip $$prog ; \
	done)
	${MV} ${PREFIX}/bin/gcc ${PREFIX}/bin/gcc295
	${MV} ${PREFIX}/bin/g++ ${PREFIX}/bin/g++295
	${MV} ${PREFIX}/bin/g77 ${PREFIX}/bin/g77
	${MV} ${PREFIX}/bin/g++filt ${PREFIX}/bin/g++filt295
	${RM} -f ${PREFIX}/bin/cpp
	${MV} ${PREFIX}/lib/libiberty.a ${TARGLIB}
	${MV} -f ${PREFIX}/lib/libstdc++.a.${LIBSTDCPP_REV}  \
		${TARGLIB}/libstdc++.a
	${MV} ${PREFIX}/man/man1/gcc.1 ${PREFIX}/man/man1/gcc295.1
	${MV} ${PREFIX}/man/man1/g++.1 ${PREFIX}/man/man1/g++295.1
	${MV} ${PREFIX}/man/man1/g77.1 ${PREFIX}/man/man1/g77.1
.if defined(WANT_SHAREDLIBS)
	${MV} -f ${PREFIX}/lib/libstdc++.so* ${TARGLIB}
.endif
.for info in cpp g77 gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor
	cd ${PREFIX} ;\
	    find lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV} \
		-type f -o -type l >${WRKDIR}/PLIST.gcc-lib
	${ECHO} "r ${TMPPLIST}"			> ${WRKDIR}/ex.script
	${ECHO} "/Insert PLIST.gcc-lib"		>> ${WRKDIR}/ex.script
	${ECHO} "d"				>> ${WRKDIR}/ex.script
	${ECHO} "r ${WRKDIR}/PLIST.gcc-lib"	>> ${WRKDIR}/ex.script
	${ECHO} "x!"				>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-gcc-lib
	cd ${WRKDIR} ; ex < ex.script

.include <bsd.port.post.mk>
