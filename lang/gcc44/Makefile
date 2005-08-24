# ex:ts=8
# Ports collection makefile for:	egcs
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	4.1.0
PORTREVISION=	20050819
CATEGORIES=	lang java
VERSIONSTRING=	4.1-${PORTREVISION}
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	snapshots/${VERSIONSTRING}
DISTFILES=	gcc-core-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-g++-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-objc-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-testsuite-${VERSIONSTRING}${EXTRACT_SUFX}

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	GNU Compiler Collection 4.1

.if defined(WITH_FORTRAN)
LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4
.endif

CONFLICTS=	gcc-3.3.* gcc-3.4.* gcc-4.0.*
LATEST_LINK?=	gcc41${PKGNAMESUFFIX}
NOT_FOR_ARCHS=	alpha
USE_BISON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_REINPLACE=	yes
.if defined(WITH_JAVA_AWT)
USE_GNOME=	gtk20
USE_X11=	yes
.endif

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure
NOMANCOMPRESS=	yes	# too hard to deal with differences on 5-cur and releng4

.include <bsd.port.pre.mk>

.if ${ARCH} == i386  ||  ${ARCH} == amd64  ||  ${ARCH} == ia64  ||  ${ARCH} == sparc64
WITHOUT_JAVA=	yes
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

SRCDIR=		${WRKDIR}/gcc-${VERSIONSTRING}
WRKSRC=		${WRKDIR}/build
SUFFIX=		41
TARGLIB=	${PREFIX}/lib/gcc/${CONFIGURE_TARGET}/${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-nls \
		--with-system-zlib \
		--with-libiconv-prefix=${LOCALBASE} \
		--program-suffix=${SUFFIX} \
		--libdir=${TARGLIB} \
		--with-gxx-include-dir=${TARGLIB}/include/c++/
.if defined(WITH_JAVA_AWT)
CONFIGURE_ARGS+=	--enable-java-awt=xlib,gtk #--enable-gtk-cairo=yes
WANT_SHAREDLIBS=yes	# We need this at the moment.
.endif
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+=	--enable-shared
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${TARGLIB}
.else
CONFIGURE_ARGS+=	--disable-shared
.endif
ALL_TARGET=	bootstrap-lean
PLIST_SUB=	GCC_VER=${PORTVERSION} GNU_HOST=${CONFIGURE_TARGET}
MAN1=		cpp${SUFFIX}.1 \
		g++${SUFFIX}.1 \
		gcc${SUFFIX}.1 \
		gcov${SUFFIX}.1
INFO=		cpp cppinternals gcc gccinstall gccint

.if defined(WITH_FORTRAN)
DISTFILES+=	gcc-fortran-${VERSIONSTRING}${EXTRACT_SUFX}
CONFIGURE_ARGS+=--with-gmp=${LOCALBASE}
MAN1+=		gfortran${SUFFIX}.1
INFO+=		gfortran
PLIST_SUB+=	FORTRAN=""
.else
PLIST_SUB+=	FORTRAN="@comment "
.endif

.if ! defined(WITHOUT_JAVA)
DISTFILES+=	gcc-java-${VERSIONSTRING}${EXTRACT_SUFX}
EXTRA_PATCHES=	${FILESDIR}/java-patch-hier
# FIXME: we are currently getting weird build failures with libjava on
# some 4.x and 5.x systems, which the following works around. PR 81788.
CONFIGURE_ARGS+=--disable-rpath
MAN1+=		fastjar${SUFFIX}.1 \
		gcj${SUFFIX}.1 \
		gcj-dbtool${SUFFIX}.1 \
		gcjh${SUFFIX}.1 \
		gij${SUFFIX}.1 \
		gjnih${SUFFIX}.1 \
		grmic${SUFFIX}.1 \
		grmiregistry${SUFFIX}.1 \
		grepjar${SUFFIX}.1 \
		jar${SUFFIX}.1 \
		jcf-dump${SUFFIX}.1 \
		jv-scan${SUFFIX}.1 jv-convert${SUFFIX}.1 \
		rmic${SUFFIX}.1 rmiregistry${SUFFIX}.1
INFO+=		gcj fastjar hacking vmintegration
PLIST_SUB+=	JAVA=""
.else
CONFIGURE_ARGS+=--disable-libgcj
PLIST_SUB+=	JAVA="@comment "
.endif

pre-everything::
	@${ECHO_MSG} "Making GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL}  target=${CONFIGURE_TARGET}"
.if ! defined(WITHOUT_JAVA)
	@${ECHO_MSG} "(with Java)"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\(const char version_string.*\)";|\1 [FreeBSD]";|' \
	    ${SRCDIR}/gcc/version.c

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-build:
	@${ECHO_MSG} "Consider running 'make check' before 'make install', especially"
	@${ECHO_MSG} "if you have not performed this build on -STABLE or -CURRENT."
	@${ECHO_MSG} "This assumes that you have the dejagnu port installed."

check: build
	cd ${WRKSRC}; export RUNTESTFLAGS='--target_board ''unix{-pthread}'''; ${GMAKE} -sk check

post-install:
	# FIXME: As of July 2005 libjava installs these bogus directories.
	-${RMDIR} -p ${PREFIX}/share/classpath/api
	# man pages can only be generated if Perl >= 5.6 is installed;
	# fake them otherwise.
	for mp in ${_MANPAGES}; do \
	  ${TEST} -e $${mp} || ${TOUCH} ${TOUCH_FLAGS} $${mp}; \
	done
.for f in c++ gcc g++ cpp gcov ${CONFIGURE_TARGET}-gcc ${CONFIGURE_TARGET}-g++ gcj gcjh gij jv-scan jcf-dump jv-convert jar grepjar rmic rmiregistry
	# gij and jv-convert, for example, are not built on all platforms.
	if [ -e ${PREFIX}/man/man1/${f}.1 ]; then \
	  ${MV} -f ${PREFIX}/man/man1/${f}.1 \
	           ${PREFIX}/man/man1/${f}${SUFFIX}.1; \
	fi
.endfor
	${RM} -f ${TARGLIB}/*.la
	${RM} -f ${PREFIX}/man/man7/fsf-funding.7 \
	         ${PREFIX}/man/man7/gfdl.7 ${PREFIX}/man/man7/gpl.7
	# Add target libraries and include files to packaging list.
	${RM} -f ${WRKDIR}/PLIST.lib
.for d in ${TARGLIB:S/^${PREFIX}\///} ${TARGLIB:S/^${PREFIX}\///:S/lib/libexec/} include/gcj include/gnu include/java include/javax
	cd ${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	    ${FIND} $d -type d | ${SORT} -r \
	        | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc/${CONFIGURE_TARGET} 2>&1 || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc 2>&1 || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc/${CONFIGURE_TARGET} 2>&1 || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc 2>&1 || true" >> ${WRKDIR}/PLIST.lib
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

cklatest:
.for SITE in ftp://gcc.gnu.org/pub/gcc/snapshots/
	@-ncftpls -l ${SITE} | ${GREP} 'LATEST.*4\.1'
.endfor

.include <bsd.port.post.mk>
