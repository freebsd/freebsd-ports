# ex:ts=8
# Ports collection makefile for:	egcs
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.3
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/gcc-2.95.3
DISTFILES=	gcc-core-${GCC_REV}${EXTRACT_SUFX} \
		gcc-g++-${GCC_REV}${EXTRACT_SUFX}

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	GNU Compiler Collection

NOT_FOR_ARCHS=	amd64 sparc64 ia64
USE_BZIP2=	yes

LATEST_LINK=	gcc295

.ifdef USE_GCC
.error You have `USE_GCC' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

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
#CONFIGURE_ARGS+=	--program-suffix=-295
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+= --enable-shared
.endif
.if defined(WANT_THREADS)
#	?is this an ObjC only thing?
CONFIGURE_ARGS+= --enable-threads=posix
.endif
ALL_TARGET=	bootstrap
MAN1=		cccp.1 g++295.1 gcc295.1

pre-patch:
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd.h ${WRKSRC}/gcc/config/i386/freebsd-aout.h
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd-elf.h ${WRKSRC}/gcc/config/i386/freebsd.h
	@${MV} ${WRKSRC}/libstdc++/stl/stl_bvector.h \
		${WRKSRC}/libstdc++/stl/stl_bvector.h.orig
	@${SED} -e "s,_WORD_BIT,_WORD_BIT_GCC295,g" \
		< ${WRKSRC}/libstdc++/stl/stl_bvector.h.orig \
		> ${WRKSRC}/libstdc++/stl/stl_bvector.h

pre-configure:
	@(MAJ=`/sbin/sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
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
		${PREFIX}/bin/g++filt ${PREFIX}/bin/gcov \
		${PREFIX}/bin/protoize ${PREFIX}/bin/unprotoize \
		${PREFIX}/bin/${CONFIGURE_TARGET}-gcc \
		${TARGLIB}/cc1 \
		${TARGLIB}/cc1plus \
		${TARGLIB}/cpp0 \
		${TARGLIB}/collect2 \
	; do \
		${STRIP_CMD} $$prog ; \
	done)
	${MV} ${PREFIX}/bin/gcc ${PREFIX}/bin/gcc295
	${MV} ${PREFIX}/bin/g++ ${PREFIX}/bin/g++295
	${MV} ${PREFIX}/bin/protoize ${PREFIX}/bin/protoize295
	${MV} ${PREFIX}/bin/unprotoize ${PREFIX}/bin/unprotoize295
	${MV} ${PREFIX}/bin/g++filt ${PREFIX}/bin/g++filt295
	${RM} -f ${PREFIX}/bin/cpp ${PREFIX}/lib/libiberty.a
	${MV} -f ${PREFIX}/lib/libstdc++.a.${LIBSTDCPP_REV}  \
		${TARGLIB}/libstdc++.a
	${MV} ${PREFIX}/man/man1/gcc.1 ${PREFIX}/man/man1/gcc295.1
	${MV} ${PREFIX}/man/man1/g++.1 ${PREFIX}/man/man1/g++295.1
.if defined(WANT_SHAREDLIBS)
	${MV} -f ${PREFIX}/lib/libstdc++.so* ${TARGLIB}
.endif
.for info in cpp gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor
	cd ${PREFIX} ;\
	    ${FIND} lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV} \
		-type f -o -type l >${WRKDIR}/PLIST.gcc-lib
	${ECHO_CMD} "r ${TMPPLIST}"		> ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.gcc-lib"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"				>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.gcc-lib"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"			>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-gcc-lib
	cd ${WRKDIR} ; ex < ex.script

.include <bsd.port.post.mk>
