# ex:ts=4
# Ports collection makefile for:	gnat-gcc
# Date created:						22 Jun 2006
# Whom:								Karel Miklav <karel@lovetemple.net>
#
# $FreeBSD$
#

PORTNAME=		gnat-gcc
PORTVERSION=	3.4.6
PORTREVISION=	2
CATEGORIES=		lang
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/gcc-${PORTVERSION}
DISTFILES=		gcc-core-${PORTVERSION}.tar.gz \
				gcc-ada-${PORTVERSION}.tar.gz

MAINTAINER=		karel@lovetemple.net
COMMENT=		The GNU Ada Compiler system

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes
USE_PERL5=	yes
USE_BISON=	yes

CONFLICTS=	gcc-3.4.*
WRKSRC=		${WRKDIR}/gcc-${PORTVERSION}

MAN1=		cpp${gcc_suffix}.1 \
			gcc${gcc_suffix}.1 \
 			gcov${gcc_suffix}.1
MAN7=		${fsf_mans:S/$/${fsf_suffix}.7/}
NOMANCOMPRESS=	yes	# too hard to deal with differences on 5-cur and releng4
INFO=		gcc${gcc_suffix}/cpp \
			gcc${gcc_suffix}/cppinternals \
			gcc${gcc_suffix}/gcc \
			gcc${gcc_suffix}/gccinstall \
			gcc${gcc_suffix}/gccint \
			gcc${gcc_suffix}/gnat-style \
			gcc${gcc_suffix}/gnat_rm \
			gcc${gcc_suffix}/gnat_ugn_unw

LATEST_LINK=	${PORTNAME}${gcc_suffix}

.include <bsd.port.pre.mk>

gcc_suffix=		34
fsf_mans=		fsf-funding gfdl gpl
fsf_suffix=		-${PORTNAME}${gcc_suffix}
targlib=		${PREFIX}/lib/gcc/${CONFIGURE_TARGET}/${PORTVERSION}

PATCH_WRKSRC=	${WRKSRC}

GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKDIR}/build
CONFIGURE_SCRIPT=	../${WRKSRC:C/${WRKDIR}\///}/configure
CONFIGURE_ARGS=	--enable-languages="c,ada" \
				--disable-nls \
				--with-system-zlib \
				--with-libiconv-prefix=${LOCALBASE} \
				--enable-threads=posix \
				--program-suffix=${gcc_suffix} \
				--bindir=${PREFIX}/bin/gcc${gcc_suffix} \
				--libdir=${targlib} \
				--infodir=${PREFIX}/${INFO_PATH}/gcc${gcc_suffix}

BUILD_WRKSRC=	${WRKDIR}/build

INSTALL_WRKSRC=	${WRKDIR}/build

PLIST_SUB=		GCC_VER=${PORTVERSION} \
				GNU_HOST=${CONFIGURE_TARGET} \
				SUFFIX=${gcc_suffix}

USE_LDCONFIG=	${targlib}

# You need a compiler who calls an existing GNAT compiler (3.15 or greater).
# By default, we'll look for one in the path.  If we can't find one, we'll
# fetch a distfile containing a minimum (still pretty large) compiler toolset
# and use that to build.
gnat_gcc!=	if ${WHICH} adagcc > /dev/null 2>&1; then \
				${ECHO_CMD} "`${WHICH} adagcc`"; \
			else \
				${ECHO_CMD} ""; \
			fi
gnat_bind!=	if ${WHICH} gnatbind > /dev/null 2>&1; then \
				${ECHO_CMD} "`${WHICH} gnatbind`"; \
			else \
				${ECHO_CMD} ""; \
			fi
.if empty(gnat_gcc)
gnat_gcc!=	if ${WHICH} gnatgcc > /dev/null 2>&1; then \
				${ECHO_CMD} "`${WHICH} gnatgcc`"; \
			else \
				${ECHO_CMD} ""; \
			fi
.endif

.if !empty(gnat_gcc) && !empty(gnat_bind)
build_path!=	if [ -x ${gnat_gcc} -a -x ${gnat_bind} ]; then \
				${ECHO_CMD} "$$PATH"; \
			else \
				${ECHO_CMD} ""; \
			fi
.else
build_path=
.endif

.if empty(build_path)
DISTFILES+=		gnat-3.15p-boot.tar.gz:boot
MASTER_SITES+=	${MASTER_SITE_LOCAL}:boot
MASTER_SITE_SUBDIR+=	deischen/gcc/:boot
.if ${OSVERSION} >= 500000
BUILD_DEPENDS+=	${LOCALBASE}/lib/compat/libc.so.4:${PORTSDIR}/misc/compat4x
.endif
# Warning! You need the trailing slash on GCC_EXEC_PREFIX.
compiler_data=	GCC_EXEC_PREFIX=${WRKDIR}/adaboot/lib/gcc-lib/ \
				ADA_INCLUDE_PATH=${WRKDIR}/adaboot/lib/gcc-lib/adainclude \
				ADA_OBJECTS_PATH=${WRKDIR}/adaboot/lib/gcc-lib/adalib
bootstrap_path=	${WRKDIR}/adaboot/bin
build_path=		${bootstrap_path}:${PATH}
gnat_gcc=		adagcc
.endif

# Make sure we use the Ada-aware gcc compiler.
CC=				${gnat_gcc}
# C compiler from GNAT 3.15 doesn't understand modern flags.
CFLAGS=
CONFIGURE_ENV+=	${compiler_data} PATH=${build_path}
MAKE_ENV+=		${compiler_data} PATH=${build_path} PTHREAD_LIBS=${PTHREAD_LIBS} CC=${CC}

pre-everything::
	@${ECHO_MSG} "Making GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL} target=${CONFIGURE_TARGET}"

# Append ' [FreeBSD]' to gcc version string.
post-patch:
	@${REINPLACE_CMD} -e 's|\(const char version_string.*\)";|\1 [FreeBSD]";|' \
	    ${WRKSRC}/gcc/version.c

pre-configure:
	cd ${WRKSRC}; contrib/gcc_update --touch
	@${RM} -f ${WRKSRC}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}
	# Ada and C compilers should be the same.
	if [ -d ${bootstrap_path} ]; then \
		${LN} -s ${bootstrap_path}/adagcc ${bootstrap_path}/cc; \
	fi

do-build:
	(cd ${BUILD_WRKSRC}; \
	    ${MAKE_ENV} ${GMAKE} bootstrap)
	(cd ${BUILD_WRKSRC}; \
	    ${MAKE_ENV} ${GMAKE} -C gcc gnatlib)
	(cd ${BUILD_WRKSRC}; \
	    ${MAKE_ENV} ${GMAKE} -C gcc gnattools)

post-install:
	${LN} -s ${PREFIX}/bin/gcc${gcc_suffix}/gcc${gcc_suffix} \
		${PREFIX}/bin/gcc${gcc_suffix}/gcc
	# Man pages can only be generated if Perl >= 5.6 is installed; fake them otherwise.
	for mp in ${_MANPAGES}; do \
		${TEST} -e $${mp} || ${TOUCH} ${TOUCH_FLAGS} $${mp}; \
	done
	# Version FSF funding and licensing manuals.
	for mp in ${fsf_mans}; do \
		${MV} -f ${PREFIX}/man/man7/$${mp}.7 \
			${PREFIX}/man/man7/$${mp}${fsf_suffix}.7; \
	done
	# Prepare a temporary list of installed libraries and include files.
	${RM} -f ${WRKDIR}/PLIST.lib
	for d in ${targlib:S/^${PREFIX}\///} ${targlib:S/^${PREFIX}\///:S/lib/libexec/}; do \
		cd ${PREFIX}; \
		if [ -d $${d} ]; then \
			${FIND} $${d} -type f -o -type l >>${WRKDIR}/PLIST.lib; \
			${FIND} $${d} -type d | ${SORT} -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.lib; \
		fi; \
	done
	# Following directories should be removed on deinstal if empty. Add them to the temporary list.
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc/${CONFIGURE_TARGET} 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc/${CONFIGURE_TARGET} 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	# Insert the temporary list in the packing list.
	cd ${WRKDIR}; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
