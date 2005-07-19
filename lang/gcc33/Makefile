# ex:ts=8
# Ports collection makefile for:	egcs
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	3.3.6
PORTEPOCH=	1
CATEGORIES=	lang
VERSIONSTRING=	${PORTVERSION}
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/gcc-${VERSIONSTRING}
DISTFILES=	\
		gcc-core-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-g++-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-g77-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-objc-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-testsuite-${VERSIONSTRING}${EXTRACT_SUFX}

MAINTAINER?=	gerald@FreeBSD.org
COMMENT?=	GNU Compiler Collection 3.3

CONFLICTS=	gcc-4.0.* gcc-4.1.*
LATEST_LINK?=	gcc33${PKGNAMESUFFIX}
USE_BISON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_REINPLACE=	yes

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure
NOMANCOMPRESS=	yes	# too hard to deal with differences on 5-cur and releng4

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
IGNORE=		does not support FreeBSD 7.x and above
.endif
.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
BROKEN=			"Bus errors in stage2; system compiler may be broken."
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

SRCDIR=		${WRKDIR}/gcc-${VERSIONSTRING}
WRKSRC=		${WRKDIR}/build
SUFFIX=		33
TARGLIB=	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls \
		--with-system-zlib \
		--program-suffix=${SUFFIX} \
		--libdir=${TARGLIB} \
		--with-gxx-include-dir=${TARGLIB}/include/c++/ \
		--enable-languages=c,c++,objc,f77
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
		g77-${SUFFIX}.1 \
		gcc${SUFFIX}.1 \
		gcov${SUFFIX}.1
INFO=		cpp cppinternals g77 gcc gccint

pre-everything::
	@${ECHO_MSG} "Making GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL}  target=${CONFIGURE_TARGET}"

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
	# man pages can only be generated if Perl >= 5.6 is installed;
	# fake them otherwise.
	for mp in ${_MANPAGES}; do \
	  ${TEST} -e $${mp} || ${TOUCH} ${TOUCH_FLAGS} $${mp}; \
	done
.for f in c++ g77 gcc g++ cpp gcov ${CONFIGURE_TARGET}-gcc ${CONFIGURE_TARGET}-g++
	# gij and jv-convert, for example, are not built on all platforms.
	if [ -e ${PREFIX}/bin/${f}${SUFFIX} ]; then \
	  ${STRIP_CMD} ${PREFIX}/bin/${f}${SUFFIX}; \
	fi
	if [ -e ${PREFIX}/man/man1/${f}.1 ]; then \
	  ${MV} -f ${PREFIX}/man/man1/${f}.1 \
	           ${PREFIX}/man/man1/${f}${SUFFIX}.1; \
	fi
.endfor
	${MV} -f ${PREFIX}/bin/g77${SUFFIX} ${PREFIX}/bin/g77-${SUFFIX}
	-${MV} -f ${PREFIX}/man/man1/g77${SUFFIX}.1 ${PREFIX}/man/man1/g77-${SUFFIX}.1
	${RM} -f ${TARGLIB}/*.la
	${RM} -f ${PREFIX}/man/man7/fsf-funding.7 \
	         ${PREFIX}/man/man7/gfdl.7 ${PREFIX}/man/man7/gpl.7
	# Add target libraries and include files to packaging list.
	${RM} -f ${WRKDIR}/PLIST.lib
.for d in ${TARGLIB:S/^${PREFIX}\///} include/gnu
	cd ${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	    ${FIND} $d -type d | ${SORT} -r \
	        | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc-lib/${CONFIGURE_TARGET} 2>&1 || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc-lib 2>&1 || true" >> ${WRKDIR}/PLIST.lib
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

cklatest:
.for SITE in ftp://gcc.gnu.org/pub/gcc/snapshots/
	@-ncftpls -l ${SITE} | ${GREP} 'LATEST.*3\.3'
.endfor

.include <bsd.port.post.mk>
