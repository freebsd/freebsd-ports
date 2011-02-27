# ex:ts=8
#
# Ports collection makefile for: gnat-gcc
# Date created:		9 Jul 2006
# Whom:			Karel Miklav <karel@lovetemple.net>
#
# $FreeBSD$
#

PORTNAME=		gnat-gcc
PORTVERSION=		4.3.2
PORTREVISION=	4
CATEGORIES=		lang
MASTER_SITES=		GCC/releases/gcc-${PORTVERSION} \
			CENKES:boot \
			http://lovetemple.net/data/:boot
DISTFILES=		gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
			gcc-ada-${PORTVERSION}${EXTRACT_SUFX} \
			gcc-testsuite-${PORTVERSION}${EXTRACT_SUFX} \
			gnat-gcc41-boot-${boot_stamp}.tbz:boot

MAINTAINER=		karel@lovetemple.net
COMMENT=		The GNU Ada Compiler system

LIB_DEPENDS=		gmp.10:${PORTSDIR}/math/gmp \
			mpfr.4:${PORTSDIR}/math/mpfr

ONLY_FOR_ARCHS=		i386

USE_BZIP2=		yes
USE_GMAKE=		yes
USE_ICONV=		yes
USE_PERL5_BUILD=	yes # Needed for man pages.
USE_BISON=		build

CONFLICTS=		gcc-4.3.*
WRKSRC=			${WRKDIR}/build

MAN1=			cpp${gcc_suffix}.1 \
			gcc${gcc_suffix}.1 \
			gcov${gcc_suffix}.1
MAN7=			${fsf_mans:S/$/${fsf_suffix}.7/}
NO_MANCOMPRESS=		yes # XXX 5-cur and releng4 problems?
INFO=			gcc${gcc_suffix}/cpp \
			gcc${gcc_suffix}/cppinternals \
			gcc${gcc_suffix}/gcc \
			gcc${gcc_suffix}/gccinstall \
			gcc${gcc_suffix}/gccint \
			gcc${gcc_suffix}/gnat-style \
			gcc${gcc_suffix}/gnat_rm \
			gcc${gcc_suffix}/gnat_ugn_unw \
			gcc${gcc_suffix}/libgomp

LATEST_LINK=		${PORTNAME}${gcc_suffix}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=         Does not install (missing distinfo for FreeBSD-9)
.endif

srcdir=			${WRKDIR}/gcc-${PORTVERSION}
gcc_suffix=		43
fsf_mans=		fsf-funding gfdl gpl
fsf_suffix=		-${PORTNAME}${gcc_suffix}
targlib=		${PREFIX}/lib/gcc-${PORTVERSION}
gcc_link=		${PREFIX}/bin/gcc${gcc_suffix}/gcc
boot_stamp=		${ARCH}-freebsd-${OSREL:C/\.[0-9.]*//:S/8/7/}
check_target=		check # XXX

PATCH_WRKSRC=		${srcdir}

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../${srcdir:C/${WRKDIR}//}/configure
CONFIGURE_ARGS=		--enable-languages="c,ada" \
			--disable-nls \
			--with-system-zlib \
			--with-libiconv-prefix=${LOCALBASE} \
			--program-suffix=${gcc_suffix} \
			--bindir=${PREFIX}/bin/gcc${gcc_suffix} \
			--libdir=${targlib}

ALL_TARGET=		bootstrap-lean
MAKE_ENV+=		MAKEINFOFLAGS="--no-split" PTHREAD_LIBS=${PTHREAD_LIBS}

PLIST_SUB=		GCC_VER=${PORTVERSION} \
			GNU_HOST=${CONFIGURE_TARGET} \
			SUFFIX=${gcc_suffix}

USE_LDCONFIG=		${targlib}

# Prepare environment for the bootstrap compiler.
CC=			${WRKDIR}/boot/bin/gcc
build_env=		PTHREAD_LIBS=${PTHREAD_LIBS} \
			PATH=${WRKDIR}/boot/bin:${WRKDIR}/boot/libexec:${PATH}

CONFIGURE_ENV+=		${build_env} CC="${CC}"
MAKE_ENV+=		${build_env}

pre-everything::
	@${ECHO_MSG} -n "Making GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} "
	@${ECHO_MSG}     "${OSREL} target=${CONFIGURE_TARGET}"

post-patch:
	# Append ' [FreeBSD]' to the gcc version string.
	${REINPLACE_CMD} \
	    -e 's|\(const char version_string.*\)";|\1 [FreeBSD]";|' \
	    ${srcdir}/gcc/version.c
	# New putenv(3) behavior in FreeBSD 7.
	if [ ${OSVERSION} -ge 700050 ]; then \
	    ${REINPLACE_CMD} -e 's/#if defined (__FreeBSD__) ||/#if/' \
	        ${srcdir}/gcc/ada/env.c; \
	fi

pre-configure:
	cd ${srcdir} ; contrib/gcc_update --touch
	${RM} -f ${srcdir}/gcc/*/*.info*
	${MKDIR} ${CONFIGURE_WRKSRC}

post-build:
	@${ECHO_MSG} -n "Consider running 'make check' before 'make install', "
	@${ECHO_MSG} -n "especially if you have not performed this build on "
	@${ECHO_MSG} -n "-STABLE or -CURRENT. This assumes that you have "
	@${ECHO_MSG}    "dejagnu and autogen ports installed."

check: build
	cd ${WRKSRC} && \
	export RUNTESTFLAGS='--target_board ''unix{-pthread}''' && \
	${GMAKE} -sk ${check_target}

post-install:
	# Create a gcc link.
	${RM} -f ${gcc_link}
	${LN} -s ${PREFIX}/bin/gcc${gcc_suffix}/gcc${gcc_suffix} ${gcc_link}
	# This empty fortran directory is making trouble.
	${RM} -rf ${PREFIX}/lib/gcc-${PORTVERSION}/gcc/${CONFIGURE_TARGET}/${PORTVERSION}/finclude
	# Man pages can only be generated if Perl >= 5.6 is installed; fake them otherwise.
	for mp in ${_MANPAGES}; do \
	    ${TEST} -e $${mp} || ${TOUCH} ${TOUCH_FLAGS} $${mp}; \
	done
	# Version FSF funding and licensing manuals. XXX Fix before it happens!
	for mp in ${fsf_mans}; do \
	    ${MV} -f ${PREFIX}/man/man7/$${mp}.7 \
	        ${PREFIX}/man/man7/$${mp}${fsf_suffix}.7; \
	done
	# Prepare a temporary list of installed libraries and include files.
	${RM} -f ${WRKDIR}/PLIST.lib
	for d in lib/gcc-${PORTVERSION} libexec/gcc/${CONFIGURE_TARGET}/${PORTVERSION}; do \
	    cd ${PREFIX}; \
	    if [ -d $${d} ]; then \
	        ${FIND} $${d} -type f -o -type l >>${WRKDIR}/PLIST.lib; \
	        ${FIND} $${d} -type d | ${SORT} -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.lib; \
	    fi; \
	done
	# Following directories should be removed on deinstal if empty. Add them to the temporary list.
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc/${CONFIGURE_TARGET} 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	# Insert the temporary list in the packing list.
	cd ${WRKDIR}; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
