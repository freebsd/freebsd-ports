# ex:ts=8
# Ports collection makefile for:	egcs
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	4.0.4
PORTREVISION=	20060511
CATEGORIES=	lang
VERSIONSTRING=	4.0-${PORTREVISION}
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	snapshots/${VERSIONSTRING}
DISTFILES=	gcc-core-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-g++-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-objc-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-testsuite-${VERSIONSTRING}${EXTRACT_SUFX}

MAINTAINER?=	gerald@FreeBSD.org
COMMENT?=	GNU Compiler Collection 4.0

SUFFIX=		40
LATEST_LINK?=	gcc${SUFFIX}${PKGNAMESUFFIX}
USE_BISON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_PERL5_BUILD=yes

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure
NOMANCOMPRESS=	yes	# too hard to deal with differences on 5-cur and releng4

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

SRCDIR=		${WRKDIR}/gcc-${VERSIONSTRING}
WRKSRC=		${WRKDIR}/build
TARGLIB=	${PREFIX}/lib/gcc/${CONFIGURE_TARGET}/${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-nls \
		--with-system-zlib \
		--with-libiconv-prefix=${LOCALBASE} \
		--program-suffix=${SUFFIX} \
		--libdir=${TARGLIB} \
		--with-gxx-include-dir=${TARGLIB}/include/c++/ \
		--infodir=${PREFIX}/${INFO_PATH}/gcc${SUFFIX}
CONFIGURE_ENV=	RANLIB=:
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
ALL_TARGET=	bootstrap-lean
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${TARGLIB}
SUB_LIST=	TARGLIB="${TARGLIB}"
SUB_FILES=	gcc.sh
RC_D_SH=	etc/rc.d/gcc${SUFFIX}.sh
PLIST_SUB=	GCC_VER=${PORTVERSION} GNU_HOST=${CONFIGURE_TARGET} \
		SUFFIX=${SUFFIX}
MAN1=		cpp${SUFFIX}.1 \
		g++${SUFFIX}.1 \
		gcc${SUFFIX}.1 \
		gcov${SUFFIX}.1
INFO=		gcc${SUFFIX}/cpp \
		gcc${SUFFIX}/cppinternals \
		gcc${SUFFIX}/gcc \
		gcc${SUFFIX}/gccinstall \
		gcc${SUFFIX}/gccint

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
	-@${MKDIR} ${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKDIR}/gcc.sh ${PREFIX}/${RC_D_SH}
	# man pages can only be generated if Perl >= 5.6 is installed;
	# fake them otherwise.
	for mp in ${_MANPAGES}; do \
	  ${TEST} -e $${mp} || ${TOUCH} ${TOUCH_FLAGS} $${mp}; \
	done
.for f in c++ gcc g++ cpp gcov ${CONFIGURE_TARGET}-gcc ${CONFIGURE_TARGET}-g++
	# gij and jv-convert, for example, are not built on all platforms.
	if [ -e ${PREFIX}/man/man1/${f}.1 ]; then \
	  ${MV} -f ${PREFIX}/man/man1/${f}.1 \
	           ${PREFIX}/man/man1/${f}${SUFFIX}.1; \
	fi
.endfor
	${MV} -f ${PREFIX}/include/mf-runtime.h \
	         ${TARGLIB}/gcc/${CONFIGURE_TARGET}/${PORTVERSION}/include
	${RM} -f ${TARGLIB}/*.la
	${RM} -f ${PREFIX}/man/man7/fsf-funding.7 \
	         ${PREFIX}/man/man7/gfdl.7 ${PREFIX}/man/man7/gpl.7
	# Add target libraries and include files to packaging list.
	${RM} -f ${WRKDIR}/PLIST.lib
.for d in ${TARGLIB:S/^${PREFIX}\///} ${TARGLIB:S/^${PREFIX}\///:S/lib/libexec/}
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
	@-ncftpls -l ${SITE} | ${GREP} 'LATEST.*4\.0'
.endfor

.include <bsd.port.post.mk>
