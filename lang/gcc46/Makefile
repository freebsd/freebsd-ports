# ex:ts=8 
# Ports collection makefile for:	egcs 
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

SNAPDATE=	2002-10-14
SNAPVER=	${SNAPDATE:S/-//g}
#CVS_DATE=	${SNAPDATE} 18:53:04 EDT

PORTNAME=	gcc
PORTVERSION=	3.3
PORTREVISION=	${SNAPVER}
CATEGORIES=	lang java
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	snapshots/${SNAPDATE}
.if !defined(CVS_DATE)
DISTFILES=	\
		gcc-core-${SNAPVER}${EXTRACT_SUFX} \
		gcc-g++-${SNAPVER}${EXTRACT_SUFX} \
		gcc-g77-${SNAPVER}${EXTRACT_SUFX} \
		gcc-java-${SNAPVER}${EXTRACT_SUFX} \
		gcc-objc-${SNAPVER}${EXTRACT_SUFX}
.endif

PATCH_SITES=	ftp://relay.nuxi.com/obrien/
PATCHFILES=	port_gcc33_${SNAPDATE}.diff

MAINTAINER=	ports@FreeBSD.org

NO_CDROM=	'dated material'
LATEST_LINK=	gcc33

USE_BZIP2=	yes

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure
NOMANCOMPRESS=	yes	# to hard to deal with differences on 5-cur and releng4

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
CONFIGURE_TARGET=	${ARCH}-portbld-freebsdaout${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

#GCC_REV=	${PORTVERSION:C/\.0$//}
GCC_REV=	3.3
#SRCDIR=		${WRKDIR}/gcc-${GCC_REV}
SRCDIR=		${WRKDIR}/gcc-${SNAPVER}
WRKSRC=		${WRKDIR}/build
TARGLIB=	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}
PLIST_SUB=	GCC_REV=${GCC_REV} GNU_HOST=${CONFIGURE_TARGET}  \
		SNAPVER=${SNAPVER}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	yes
CONFIGURE_ARGS=	--disable-nls --with-gnu-as --with-gnu-ld \
		--with-gxx-include-dir=${TARGLIB}/include/g++-v3
#CONFIGURE_ARGS+=	--program-suffix=33
#	Java
CONFIGURE_ARGS+=	--with-system-zlib #--includedir=${TARGLIB}/include/Java -libdir=${TARGLIB}
#CONFIGURE_ARGS+=	--disable-libgcj	# does not bootstrap now
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+= --enable-shared
.else
CONFIGURE_ARGS+= --disable-shared
.endif
.if defined(WANT_THREADS_SUPPORT)
CONFIGURE_ARGS+= --enable-threads
#	?is this an ObjC only thing?
CONFIGURE_ARGS+= --enable-threads=posix
.endif
ALL_TARGET=	bootstrap
MAN1=		cpp33.1 g++33.1 g77-33.1 gcc33.1 gcov33.1 \
		gcj33.1 gcjh33.1 gij.1 grepjar33.1 jar33.1 \
		jcf-dump33.1 jv-scan33.1 jv-convert.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7

pre-fetch:
	@${ECHO} "Making GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL} ${PORTOBJFORMAT}	target ${CONFIGURE_TARGET}"

.if defined(CVS_DATE)
NO_CHECKSUM=	yes
DIST_SUBDIR=	${PKGNAME}
CVS_CMD?=	cvs -z3 -qR
CVSROOT=	:pserver:anoncvs@subversions.gnu.org:/cvsroot/gcc
STAMPFILE=	${DISTDIR}/${DIST_SUBDIR}/.timestamp
do-fetch:
	@if [ ! -e ${STAMPFILE} ] || \
	    [ "X${CVS_DATE}" != "X$$(${CAT} ${STAMPFILE})" ]; then \
		${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
		cd ${DISTDIR}/${DIST_SUBDIR} ; \
		unset CVS_RSH CVS_SERVER || ${TRUE} ; \
		${ECHO_MSG} ">> Attempting to CVS checkout from ${CVSROOT}." ;\
		if ${CVS_CMD} -d ${CVSROOT} co -D "${CVS_DATE}" gcc ; \
		then \
			( ${ECHO} -n "${CVS_DATE}" > ${STAMPFILE} ) ; \
			exit ; \
		fi ; \
		${ECHO_MSG} ">> Couldn't CVS checkout ${PKGNAME}." ; \
		${ECHO_MSG} ">> Please try again later."; \
		exit 1; \
	fi
	@test -e ${DISTDIR}/${DIST_SUBDIR}/${PATCHFILES} \
	    || fetch -o ${DISTDIR}/${DIST_SUBDIR}/${PATCHFILES} \
		${PATCH_SITES}${PATCHFILES}

do-extract:
	${MKDIR} ${SRCDIR}
	cd ${DISTDIR}/${DIST_SUBDIR}/gcc ; pax -pe -rwt . ${SRCDIR}
.endif	# CVS_DATE

pre-configure:
	@# Keep from running `autoconf' and `autoheader' since we modified
	@# configure.in by patching it.
	@${TOUCH} ${SRCDIR}/gcc/configure
	@${TOUCH} ${SRCDIR}/gcc/cstamp-h.in
	@${MKDIR} ${CONFIGURE_WRKSRC}
	@${RM} -f ${SRCDIR}/gcc/*/*.info*

pre-build:
	cd ${SRCDIR} ; contrib/gcc_update --touch

pre-install:
	${MKDIR} ${PREFIX}/info

post-install:
	@${RM} -f ${PREFIX}/bin/c++ ${PREFIX}/bin/${CONFIGURE_TARGET}-c++
	@(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ \
		${PREFIX}/bin/g77 ${PREFIX}/bin/gcov \
		${PREFIX}/bin/${CONFIGURE_TARGET}-gcc \
		${TARGLIB}/cc1 ${TARGLIB}/cc1obj ${TARGLIB}/cc1plus \
		${TARGLIB}/collect2 ${TARGLIB}/f771 ; \
	do \
		strip $$prog ; \
	done )
.for file in gcc g++ cpp gcov ${CONFIGURE_TARGET}-gcc ${CONFIGURE_TARGET}-g++ gcj gcjh jv-scan jcf-dump jar grepjar
	${MV} -f ${PREFIX}/bin/${file} ${PREFIX}/bin/${file}33
	( ${TEST} ! -e ${PREFIX}/man/man1/${file}.1 \
		|| ${MV} -f ${PREFIX}/man/man1/${file}.1 \
		${PREFIX}/man/man1/${file}33.1 )
.endfor
.for file in g77
	${MV} -f ${PREFIX}/bin/${file} ${PREFIX}/bin/${file}-33
	( ${TEST} ! -e ${PREFIX}/man/man1/${file}.1 \
		|| ${MV} -f ${PREFIX}/man/man1/${file}.1 \
		${PREFIX}/man/man1/${file}-33.1 )
.endfor
	${MV} -f ${PREFIX}/bin/gccbug ${PREFIX}/bin/gccbug-${PORTVERSION}
	# These 3 libraries are moved from PREFIX/lib to avoid conflicts
	# 	with the stock compiler.
.for file in libstdc++ libsupc++ libg2c libfrtbegin libobjc
	${MV} -f ${PREFIX}/lib/${file}.* ${TARGLIB}
.endfor
	-${MV} -f ${PREFIX}/lib/ieee ${TARGLIB}
	# Java
	-${MV} -f ${PREFIX}/lib/libgcj.* ${TARGLIB}
	${RM} -f ${PREFIX}/lib/libiberty.a
	${RM} -f ${TARGLIB}/*.la
.for info in cpp cppinternals g77 gcc gcj
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor
# I am sick and tired of the anonyance that man pages can only be generated if
# perl 5.6 is installed.  This is becoming a royal PITA on non-5-CURRENT systems
.for mp in ${_MANPAGES}
	( ${TEST} -e ${mp} && ${TOUCH} ${TOUCH_FLAGS} ${mp} )
.endfor
	cd ${PREFIX} ;\
	    ${FIND} ${TARGLIB:S/^${PREFIX}\///} -type f -o -type l	\
	    	>${WRKDIR}/PLIST.gcc-lib
	cd ${PREFIX} ;\
	    ${FIND} ${TARGLIB:S/^${PREFIX}\///} -type d \
	    	| sort -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.gcc-lib
	(${ECHO_CMD} "@unexec rmdir %D/lib/gcc-lib/${CONFIGURE_TARGET} 2>&1 || true" ; ${ECHO_CMD} "@unexec rmdir %D/lib/gcc-lib 2>&1 || true") >> ${WRKDIR}/PLIST.gcc-lib
	${ECHO_CMD} "r ${TMPPLIST}"		> ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.gcc-lib"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"				>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.gcc-lib"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"			>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-gcc-lib
	cd ${WRKDIR} ; ex < ex.script

cklatest:
.for SITE in ftp://gcc.gnu.org/pub/gcc/snapshots/                                   ftp://mirrors.rcn.net/mirrors/sources.redhat.com/gcc/snapshots/	
	@-ncftpls ${SITE} | grep LATEST
.endfor

.include <bsd.port.post.mk>
