# ex:ts=8
# Ports collection makefile for:	egcs
# Version required: 			1998-09-14
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	egcs
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/${PORTNAME}-${PORTVERSION}
DISTFILES=	egcs-core-1.1.2${EXTRACT_SUFX} egcs-g++-1.1.2${EXTRACT_SUFX} \
		egcs-g77-1.1.2${EXTRACT_SUFX} egcs-objc-1.1.2${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	EGCS enhanced version of the GNU compiler suite

USE_BZIP2=	yes
ONLY_FOR_ARCHS=	i386 alpha

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

EGCS_REV=	egcs-2.91.66

.if ${PORTOBJFORMAT} == "elf"
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
	@(MAJ=`/sbin/sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${SED} -e "s:__FreeBSD__:__FreeBSD__=$${MAJ}:" ${FILESDIR}/freebsd.h \
		>${WRKSRC}/gcc/config/freebsd.h )

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
		do ${STRIP_CMD} $$prog ; \
		done)
	${LN} -f ${PREFIX}/bin/gcc ${PREFIX}/bin/egcc
	${LN} -f ${PREFIX}/bin/g++ ${PREFIX}/bin/eg++
	${MV} ${PREFIX}/lib/libiberty.a  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}
	${MV} -f ${PREFIX}/lib/libstdc++.a  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/libstdc++.a
.if defined(WANT_SHAREDLIBS)
	${MV} -f ${PREFIX}/lib/libstdc++.so*  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}
.endif
.for info in cpp g77 gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor
	cd ${PREFIX} ;\
	    ${FIND} lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV} \
		-type f -o -type l >${WRKDIR}/PLIST.gcc-lib
	${ECHO_CMD} "r ${TMPPLIST}"		> ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.gcc-lib"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"				>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.gcc-lib"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"			>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-gcc-lib
	cd ${WRKDIR} ; ex < ex.script

.include <bsd.port.post.mk>
