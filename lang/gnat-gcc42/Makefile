# ex:ts=4
# Ports collection makefile for:	gnat-gcc
# Date created:						22 Jun 2006
# Whom:								Karel Miklav <karel@lovetemple.net>
#
# $FreeBSD$
#

PORTNAME=		gnat-gcc
PORTVERSION=	4.1.2
PORTREVISION=	1
CATEGORIES=		lang
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	snapshots/${versionstring}
DISTFILES=		gcc-core-${versionstring}${EXTRACT_SUFX} \
				gcc-ada-${versionstring}${EXTRACT_SUFX} \
				gcc-testsuite-${versionstring}${EXTRACT_SUFX}

MAINTAINER=		karel@lovetemple.net
COMMENT=		The GNU Ada Compiler system

ONLY_FOR_ARCHS=	i386

USE_BZIP2=		yes
USE_GMAKE=		yes
USE_ICONV=		yes
USE_PERL5_BUILD=	yes
USE_BISON=		yes

CONFLICTS=		gcc-4.1.*
WRKSRC=			${WRKDIR}/build

MAN1=			cpp${gcc_suffix}.1 \
				gcc${gcc_suffix}.1 \
				gcov${gcc_suffix}.1
MAN7=			${fsf_mans:S/$/${fsf_suffix}.7/}
NOMANCOMPRESS=	yes	# 5-cur and releng4 problems?
INFO=			gcc${gcc_suffix}/cpp \
				gcc${gcc_suffix}/cppinternals \
				gcc${gcc_suffix}/gcc \
				gcc${gcc_suffix}/gccinstall \
				gcc${gcc_suffix}/gccint \
				gcc${gcc_suffix}/gnat-style \
				gcc${gcc_suffix}/gnat_rm \
				gcc${gcc_suffix}/gnat_ugn_unw

LATEST_LINK=	${PORTNAME}${gcc_suffix}

.include <bsd.port.pre.mk>

gcc_snapshot=	20060901
versionstring=	${PORTVERSION:C/\.[0-9]*$//}-${gcc_snapshot}
srcdir=			${WRKDIR}/gcc-${versionstring}
gcc_suffix=		41
fsf_mans=		fsf-funding gfdl gpl
fsf_suffix=		-${PORTNAME}${gcc_suffix}
targlib=		${PREFIX}/lib/gcc/${CONFIGURE_TARGET}/${PORTVERSION}

PATCH_WRKSRC=	${srcdir}

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../${srcdir:C/${WRKDIR}//}/configure
CONFIGURE_ARGS=	--enable-languages="c,ada" \
				--disable-nls \
				--with-system-zlib \
				--with-libiconv-prefix=${LOCALBASE} \
				--program-suffix=${gcc_suffix} \
				--bindir=${PREFIX}/bin/gcc${gcc_suffix} \
				--libdir=${targlib} \
				--infodir=${PREFIX}/${INFO_PATH}/gcc${gcc_suffix}

ALL_TARGET=		bootstrap-lean
MAKE_ENV+=		MAKEINFOFLAGS="--no-split" PTHREAD_LIBS=${PTHREAD_LIBS}

PLIST_SUB=		GCC_VER=${PORTVERSION} \
				GNU_HOST=${CONFIGURE_TARGET} \
				SUFFIX=${gcc_suffix}

USE_LDCONFIG=	${targlib}

# We need an existing GNAT compiler to bootstrap this one.
have_gnat!=	if ${WHICH} gnatmake > /dev/null 2>&1; then \
				${ECHO_CMD} "t"; \
			else \
				${ECHO_CMD} ""; \
			fi
.if empty(have_gnat)
BUILD_DEPENDS+=	${LOCALBASE}/bin/gcc34/gcc34:${PORTSDIR}/lang/gnat-gcc34
CONFIGURE_ENV+=	PATH=${LOCALBASE}/bin/gcc34:${PATH} CC=${LOCALBASE}/bin/gcc34/gcc34
MAKE_ENV+=		PATH=${LOCALBASE}/bin/gcc34:${PATH} CC=${LOCALBASE}/bin/gcc34/gcc34
.endif

pre-everything::
	@${ECHO_MSG} "Making GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL} target=${CONFIGURE_TARGET}"

# Append ' [FreeBSD]' to gcc version string.
post-patch:
	@${REINPLACE_CMD} -e 's|\(const char version_string.*\)";|\1 [FreeBSD]";|' \
	    ${srcdir}/gcc/version.c

pre-configure:
	cd ${srcdir} ; contrib/gcc_update --touch
	@${RM} -f ${srcdir}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-build:
	@${ECHO_MSG} "Consider running 'make check' before 'make install', especially"
	@${ECHO_MSG} "if you have not performed this build on -STABLE or -CURRENT."
	@${ECHO_MSG} "This assumes that you have the dejagnu port installed."

check: build
	cd ${WRKSRC}; export RUNTESTFLAGS='--target_board ''unix{-pthread}'''; ${GMAKE} -sk check

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
	# Save the runaway header.
	${MV} -f ${PREFIX}/include/mf-runtime.h \
	         ${targlib}/gcc/${CONFIGURE_TARGET}/${PORTVERSION}/include
	# Remove libtool library files.
	${RM} -f ${targlib}/*.la
	# Add target libraries and include files to packaging list.
	${RM} -f ${WRKDIR}/PLIST.lib
	for d in ${targlib:S/^${PREFIX}\///} ${targlib:S/^${PREFIX}\///:S/lib/libexec/}; do \
		cd ${PREFIX} ; \
		if [ -d $${d} ]; then \
			${FIND} $${d} -type f -o -type l >>${WRKDIR}/PLIST.lib ; \
			${FIND} $${d} -type d | ${SORT} -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.lib ; \
		fi ; \
	done
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc/${CONFIGURE_TARGET} 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc/${CONFIGURE_TARGET} 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
