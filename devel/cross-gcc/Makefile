# New ports collection makefile for:	cross-gcc
# Date created:		2006-08-10
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	gcc
PORTVERSION=	4.3.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GCC:S,$,:gcc,} \
		${MASTER_SITE_SOURCEWARE:S,$,:newlib,}
MASTER_SITE_SUBDIR=	releases/${DISTNAME}/:gcc newlib/:newlib
PKGNAMEPREFIX=	${TGTARCH}-${TGTABI}-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:gcc \
		newlib-${NEWLIB_VERSION}${NEWLIB_EXTRACT_SUFX}:newlib
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	ftp://ftp.rtems.com/pub/rtems/SOURCES/4.9/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	stas@FreeBSD.org
COMMENT=	GNU gcc for cross-target development

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4 \
		mpfr.3:${PORTSDIR}/math/mpfr

#
# Temporary hack to deal with dependencies during package builds for
# slave ports.
#
.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS=	${OURTARGET}-as:${PORTSDIR}/devel/${OURTARGET}-binutils
RUN_DEPENDS=	${OURTARGET}-as:${PORTSDIR}/devel/${OURTARGET}-binutils
.else
BUILD_DEPENDS=	${OURTARGET}-as:${PORTSDIR}/devel/cross-binutils
RUN_DEPENDS=	${OURTARGET}-as:${PORTSDIR}/devel/cross-binutils
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	build
STRIP=		#empty
GNU_CONFIGURE=	yes
ALL_TARGET=	all info

DEPENDS_ARGS=	TGTARCH="${TGTARCH}" TGTABI="${TGTABI}"

CONFIGURE_WRKSRC=	${WRKDIR}/build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${CONFIGURE_WRKSRC}
CONFIGURE_SCRIPT=	../${WRKSRC:C,^${WRKDIR}/?,,}/configure

#
# Newlib version to use
#
NEWLIB_VERSION=	1.16.0
NEWLIB_EXTRACT_SUFX=.tar.gz

OURTARGET=	${TGTARCH}-${TGTABI}

#
# override user-defined settings in make.conf
#
WITHOUT_CPU_CFLAGS=	yes
MAKE_ENV=	NO_CPU_CFLAGS=true

CONFIGURE_ARGS=	--target=${OURTARGET} \
		--enable-languages="${TGTLANGS}" \
		--with-system-zlib \
		--disable-nls \
		--with-libiconv-prefix=${LOCALBASE} \
		--without-included_gettext \
		--with-newlib \
		--with-dwarf2 \
		--with-gxx-include-dir=${TGT_LIBDIR}/include/cxx/ \
		--disable-shared \
		--with-gmp="${LOCALBASE}" \
		--with-mpfr="${LOCALBASE}" \

MAN1=		${MANPAGES:S,^,${OURTARGET}-,}

INFO=		${OURTARGET}-cpp \
		${OURTARGET}-cppinternals \
		${OURTARGET}-gcc \
		${OURTARGET}-gccint

GCC_AUTODIRS=	${OURTARGET}/include \
		${OURTARGET}/lib \
		libexec/gcc/${OURTARGET} \
		lib/gcc/${OURTARGET}

MANPAGES=	cpp.1 g++.1 gcc.1 gcov.1

PLIST_FILES=	bin/${OURTARGET}-cpp \
		bin/${OURTARGET}-gcc \
		bin/${OURTARGET}-gcc-${GCCVER} \
		bin/${OURTARGET}-gccbug \
		bin/${OURTARGET}-gcov \
		${OURTARGET}/bin/gcc

# Build C by default
TGTLANGS=	c

TGT_LIBDIR=	${PREFIX}/${OURTARGET}/lib/gcc/

LN_BINARIES=	addr2line ar as c++filt ld \
		nm objcopy objdump ranlib \
		readelf size strings strip

GCCVER=		${PORTVERSION}

.if defined(WITH_CPU)
CONFIGURE_ARGS+=--with-cpu=${WITH_CPU} \
		--enable-cxx-flags=${WITH_CPU}
.endif

.if defined(WITH_FLOAT_TYPE)
CONFIGURE_ARGS+=--with-float=${WITH_FLOAT_TYPE}
.endif

.if defined(WITH_RTEMS_PATCHES)
PATCHFILES+=	gcc-core-4.3.2-rtems4.9-20081214.diff \
		newlib-${NEWLIB_VERSION}-rtems4.9-20081203.diff
.endif

#
# Macro to fix up info referencies
#
FIXREFS=	${SH} -c '${REINPLACE_CMD} -E \
		-e "s,(^|[[:space:]/])$$0\.(texi|info),\1${OURTARGET}-$$0.\2,g"\
		-e "s,(@file)\{$$0\},\1\{${OURTARGET}-$$0\},g" \
		-e "s,\($$0\),\(${OURTARGET}-$$0\),g" $$*' --

.if !defined(TGTARCH) || !defined(TGTABI)
PKGNAMEPREFIX=	cross-
OURTARGET=	cross	# to generate a correct index line
IGNORE=		you should select ARCH and ABI to build port
.endif

OPTIONS=	CXX	"Enable C++ language support" on \
		OBJC	"Enable Objective C support" on \
		FORTRAN	"Enable Fortran support" off

.include <bsd.port.pre.mk>

.if defined(TGTARCH)
.if ${TGTARCH} == "i386" && ${ARCH} == "amd64"
BROKEN=		Does not link
.endif
.endif

PKG_ARGS=	-v -c -${COMMENT:Q} -d ${DESCR} -f ${TMPPLIST} -p ${PREFIX} -P "`cd ${PORTSDIR}/devel/cross-binutils && ${MAKE} ${DEPENDS_ARGS} -V PKGNAME`:devel/cross-binutils" ${EXTRA_PKG_ARGS} $${_LATE_PKG_ARGS} -m ${MTREE_FILE} -o ${PKGORIGIN}

.if !defined(WITHOUT_CXX)
TGTLANGS:=	"${TGTLANGS},c++"
PLIST_FILES+=	bin/${OURTARGET}-c++ \
		bin/${OURTARGET}-g++ \
		${OURTARGET}/bin/c++ \
		${OURTARGET}/bin/g++
.endif

.if !defined(WITHOUT_OBJC)
TGTLANGS:=	"${TGTLANGS},objc"
.endif

.if defined(WITH_FORTRAN)
TGTLANGS:=	"${TGTLANGS},fortran"
PLIST_FILES+=	bin/${OURTARGET}-gfortran \
		${OURTARGET}/bin/gfortran
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "---------------------------------------------------------"
	@${ECHO_MSG} "You can specify target architectur using TGTARCH switch,"
	@${ECHO_MSG} "and ABI using TGTABI switch."
	@${ECHO_MSG}
	@${ECHO_MSG} "Default CPU module can be set using WITH_CPU, FPU type is"
	@${ECHO_MSG} "selectable through WITH_FLOAT_TYPE"
	@${ECHO_MSG}
	@${ECHO_MSG} "NOTE: not all options combinations are supported. For full"
	@${ECHO_MSG} "list of supported values refer to binutils documentation"
	@${ECHO_MSG} "---------------------------------------------------------"
	@${ECHO_MSG}

post-extract:
	@(cd ${WRKSRC} && ${TAR} -xzf \
		${DISTDIR}/newlib-${NEWLIB_VERSION}${NEWLIB_EXTRACT_SUFX})
	@${LN} -sf ${WRKSRC}/newlib-${NEWLIB_VERSION}/newlib ${WRKSRC}/newlib
	@${LN} -sf ${WRKSRC}/newlib-${NEWLIB_VERSION}/libgloss \
		${WRKSRC}/libgloss
	${MKDIR} ${CONFIGURE_WRKSRC}/

post-patch:
#
# Fix INFO references
#
.for FILE in cpp cppinternals gcc gccint
	@${FIXREFS} ${FILE} ${WRKSRC}/gcc/doc/*.texi ${WRKSRC}/gcc/Makefile.in
	@${MV} ${WRKSRC}/gcc/doc/${FILE}.texi \
		${WRKSRC}/gcc/doc/${OURTARGET}-${FILE}.texi
.endfor

#
# Do not install manpages
#
	@${REINPLACE_CMD} -E -e '/^install:/,/^$$/s,install-man,,' \
		${WRKSRC}/gcc/Makefile.in

#
# Do not install unneeded infofiles
#
	@${REINPLACE_CMD} -E \
		-e '/\$$\(DESTDIR\)\$$\(infodir\)\/gccinstall.info/d' \
		${WRKSRC}/gcc/Makefile.in

#
# Do not install libiberty
#
	@${REINPLACE_CMD} -E -e 's,^(install:).*,\1,' \
		${WRKSRC}/libiberty/Makefile.in

post-install:
#
# Install manpages
#
.for FILE in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/gcc/doc/${FILE} \
		${MAN1PREFIX}/man/man1/${OURTARGET}-${FILE}
.endfor

#
# Generate symlinks for binutils binaries to let gcc found them
#
.for F in ${LN_BINARIES}   
	@${LN} -sf ../../../../bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/libexec/gcc/${OURTARGET}/${PORTVERSION}/$F
.endfor

#
# Build pkg-plist
#
.for DIR in ${GCC_AUTODIRS:S,^,${PREFIX}/,}
	@${FIND} ${DIR} ! -type d ! -regex .*/ldscripts/[^/]* |\
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DIR} -type d ! -name ldscripts | ${SORT} -r | \
		${SED} -E -e 's,(.*),@unexec rmdir \1 2>/dev/null || true,' >> \
		${TMPPLIST}
.endfor
	@${ECHO_CMD} "@unexec rmdir ${PREFIX}/${OURTARGET}/bin 2>/dev/null " \
		"|| true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir ${PREFIX}/${OURTARGET} 2>/dev/null || true"\
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir ${PREFIX}/libexec/gcc 2>/dev/null || true" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir ${PREFIX}/lib/gcc 2>/dev/null || true" \
		>> ${TMPPLIST}

.include <bsd.port.post.mk>
