PORTNAME=	e2fsprogs
PORTVERSION=	1.47.3
PORTREVISION?=	0	# NOTE: when bumping PORTREVISION, also bump ../e2fsprogs/Makefile!
CATEGORIES?=	filesystems sysutils
MASTER_SITES=	KERNEL_ORG/linux/kernel/people/tytso/${PORTNAME}/v${PORTVERSION}

MAINTAINER?=	mandree@FreeBSD.org
COMMENT?=	Utilities & library to manipulate ext2/3/4 filesystems
WWW=		https://e2fsprogs.sourceforge.net/

LICENSE?=	GPLv2+
.if !defined(_no_license_file)
LICENSE_FILE?=	${WRKSRC}/NOTICE
.endif
LICENSE_DISTFILES_GPLv2+ =	${DISTNAME}${EXTRACT_SUFX}

USES=		compiler:c11 cpe gmake makeinfo pkgconfig tar:xz
CPE_VENDOR=	e2fsprogs_project
USE_CSTD=	gnu11
# this seems a bit redundant to the --rpath below, but
# the latter should be more robust in case someone needs
# to deal with the file systems from a system not yet fully booted.
.if !defined(PKGNAMESUFFIX)
USE_LDCONFIG=	${PREFIX}/lib/e2fsprogs
.endif
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFIGURE_ARGS?=--disable-fsck \
		--disable-e2initrd-helper \
		--disable-libuuid \
		--disable-uuidd \
		--disable-libblkid \
		--enable-elf-shlibs \
		--libdir='${PREFIX}/lib/e2fsprogs/' \
		--includedir='${PREFIX}/include/e2fsprogs/' \
		--with-root-prefix='${PREFIX}' \
		LDFLAGS='${LDFLAGS} -L${LOCALBASE}/lib -Wl,--rpath -Wl,${LOCALBASE}/lib/e2fsprogs'
CONFIGURE_ENV?=	LIBS='-Wl,--as-needed ${LIBS} -lexecinfo -lelf'
MAKE_ARGS+=	pkgconfigdir='${PREFIX}/libdata/pkgconfig'
MAKE_ENV+=	CHECK_CMD=@true

CPPFLAGS+=	${_FUSEFS_CFLAGS} -I${WRKSRC}/lib -I${LOCALBASE}/include
CFLAGS+=	-Wno-unused-command-line-argument

PORTSCOUT=	ignore:1	# cannot handle the version in the directory

.if !defined(MASTERDIR)
CPPFLAGS+=	-D__GNUC_PREREQ\(a,b\)=1

INSTALL_TARGET=		install install-libs

PORTDOCS=	NOTICE README RELEASE-NOTES SUBMITTING-PATCHES

OPTIONS_DEFINE=		DOCS NLS BASHTESTS FUSEFS PARALLELTESTS SLOWTESTS LIBUNWIND
OPTIONS_DEFAULT=		FUSEFS ALLTESTS
OPTIONS_SINGLE=			SELFTEST
OPTIONS_SINGLE_SELFTEST=	NOTESTS SMALLTESTS ALLTESTS
OPTIONS_EXCLUDE+=	EXAMPLES
OPTIONS_SUB=		yes

ALLTESTS_DESC=	Run most self-tests (needs more RAM/disk space)
BASHTESTS_DESC=	Enable tests that require the GNU bash shell
FUSEFS_DESC=	Build user-land ext2/3/4 FUSE module (slow!)
LIBUNWIND_DESC=	Backtrace with libunwind (do set WITH_DEBUG_PORTS+=${PKGORIGIN}!)
NOTESTS_DESC=	Do not run any self-tests (Tier-1, DISCOURAGED)
PARALLELTESTS_DESC=	Parallelize self-tests (needs more disk space)
SELFTEST_DESC=	Choose which set of self-tests to run
SLOWTESTS_DESC=	Enable slow tests that are skipped by default
SMALLTESTS_DESC=Run tests that need <500 MB disk space

BASHTESTS_BUILD_DEPENDS=	${BASH_CMD}:shells/bash
BASH_CMD=	${LOCALBASE}/bin/bash

FUSEFS_USES=		fuse:3
FUSEFS_CONFIGURE_ENABLE=fuse2fs
# we can't use FUSEFS_CFLAGS, see below for workaround
FUSEFS_LDFLAGS=		-L${LOCALBASE}/lib
FUSEFS_LIBS=		-Wl,--as-needed -lfuse3 -lpthread

LIB_DEPENDS+=	libblkid.so:filesystems/libblkid \
		libuuid.so:misc/libuuid

LIBUNWIND_LIB_DEPENDS=	libunwind.so:devel/libunwind
LIBUNWIND_LDFLAGS+=	-rdynamic
LIBUNWIND_LIBS+=	-L${LOCALBASE}/lib -lunwind
LIBUNWIND_EXTRA_PATCHES=${FILESDIR}/extrapatch-e2fsck_sigcatcher.c

NLS_USES=		gettext iconv:build

.endif

# even under DEVELOPER, no REINPLACE_CMD warnings desired
# it simply makes no sense to warn about dozens of files
# for systematic edits that run over files that don't need the edits.
# a "warn if nothing was edited by one command" would be acceptable,
# but until we have that in the framework, just
# avoid Tools/scripts/sed_checked altogether:
REINPLACE_CMD=	${SED} ${REINPLACE_ARGS}

PKGDEINSTALL=	${PKGINSTALL}

MAKE_ARGS+=	V=1

.include <bsd.port.options.mk>

.if ${MASTERDIR} == ${.CURDIR}
PKGNAMESUFFIX=	-core
.endif

.if !empty(PORT_OPTIONS:MFUSEFS)
# this dance is required becuse the -I must go before the default -I${LOCALBASE}/include, so we can't use FUSEFS_CFLAGS
_FUSEFS_CFLAGS=	-I${LOCALBASE}/include/fuse3
.else
_FUSEFS_CFLAGS=
.endif

.if empty(PORT_OPTIONS:MNOTESTS) && ${MASTERDIR} == ${.CURDIR}
USES+=		perl5
USE_PERL5=	build
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNLS}
. if empty(ICONV_LIB)
libintl=	${LOCALBASE}/lib/libintl.a
. else
libintl=	${LOCALBASE}/lib/libintl.a ${LOCALBASE}/lib/libiconv.a
. endif
.else
CONFIGURE_ARGS+=--disable-nls
libintl=
.endif

.if ${MASTERDIR} == ${.CURDIR} && (${ARCH} == "aarch64" || ${ARCH} == "riscv64")
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-no-sbrk
.endif

post-patch::
	${TOUCH} ${WRKSRC}/tests/r_corrupt_fs/is_slow_test
.if !empty(DISTFILES)
	@${REINPLACE_CMD} -e 's/<malloc\.h>/<stdlib.h>/' ${WRKSRC}/*/*.c
	@${REINPLACE_CMD} -e 's,/etc/blkid.tab,${ETCDIR}/blkid.tab,' ${WRKSRC}/misc/blkid* ${WRKSRC}/lib/blkid/blkidP.h
	@${REINPLACE_CMD} -E -e 's/__GNUC_PREREQ\>/__GNUC_PREREQ__/' ${WRKSRC}/*/*/*.[ch] ${WRKSRC}/*/*.c
. if empty(PORT_OPTIONS:MALLTESTS)
.  for i in \
		d_fallocate_blkmap \
		f_baddir \
		f_bbfile \
		f_convert_bmap \
		f_detect_junk \
		f_inode_ea_collision \
		f_lpffile \
		f_no_cache_corrupt_inode \
		f_opt_extent \
		j_corrupt_descr_csum \
		m_bigjournal \
		m_hugefile_slack \
		m_offset \
		m_raid_opt \
		r_32to64bit \
		r_32to64bit_expand_full \
		r_32to64bit_meta \
		r_32to64bit_move_itable \
		r_64to32bit \
		r_64to32bit_meta \
		r_expand_full \
		r_min_itable \
		t_change_uuid_mounted \
		t_dangerous \
		t_disable_changed_csum_seed_mounted \
		t_disable_mcsum \
		t_disable_mcsum_noinitbg \
		t_disable_mcsum_yesinitbg \
		t_enable_mcsum \
		t_enable_mcsum_initbg \
		t_iexpand_full \
		t_iexpand_mcsum \
		t_uninit_bg_rm \
		u_dryrun \
		u_mke2fs_opt_offset
	@${MV} ${WRKSRC}/tests/${i} ${WRKSRC}/tests/disabled_test-${i}
.  endfor
. endif
. if ${PORT_OPTIONS:MBASHTESTS}
	${REINPLACE_CMD} -e 's}^SHELL *=.*}SHELL = ${_CHECK_SHELL}}' ${WRKSRC}/MCONFIG.in
. else
.  for i in f_large_dir
	@${MV} ${WRKSRC}/tests/${i} ${WRKSRC}/tests/disabled_test-${i}
.  endfor
. endif
.endif

##############################################################
# Master port stuff that is not to be seen by the slave ports.
##############################################################
.if ${MASTERDIR} == ${.CURDIR}
# NOTE: The previous .if block goes all the way to the end of the file.

.if !empty(PORT_OPTIONS:MNOTESTS) && (${OPSYS} == FreeBSD) && (${OSVERSION} >= 1500000 || (${ARCH} != amd64))
BROKEN=	it was not tested on your system by the maintainer; you must run self-tests
.endif

pre-build:
# fix up Makefile ordering for parallel builds
	cd ${WRKSRC}/lib/et && ${DO_MAKE_BUILD} compile_et
	cd ${WRKSRC}/lib/ss && _ET_DIR_OVERRIDE=../et ../et/compile_et ss_err.et \
		&& ${REINPLACE_CMD} -f ${FILESDIR}/fix-ss_err.h.sed ss_err.h
	cd ${WRKSRC}/lib/support && ${DO_MAKE_BUILD} prof_err.h

.if ${PORT_OPTIONS:MPARALLELTESTS}
_CHECK_JOBS=${_MAKE_JOBS}
.else
_CHECK_JOBS=
.endif

_checkaddargs=
.if ${PORT_OPTIONS:MBASHTESTS}
_CHECK_SHELL=${LOCALBASE}/bin/bash
_checkaddargs+=--eval SHELL:=${BASH_CMD}
.else
_CHECK_SHELL=${SH}
.endif

.if !defined(TMPDIR)
_checkaddargs+=TMPDIR=${WRKDIR}/tmp
.endif

.if ${PORT_OPTIONS:MSLOWTESTS}
_check_target=fullcheck
_check_timeout=7200
.else
_check_target=check
_check_timeout=600
.endif

.if ${PORT_OPTIONS:MLIBUNWIND}
_staticlibs+=${LOCALBASE}/lib/libunwind.a /usr/lib/liblzma.a /usr/lib/libmd.a
.endif

post-build:
# Relink e2fsck statically - We need to make sure that tools for the root file
# system are statically linked against anything that is outside the root fs,
# else we're in trouble if e2fsck is needed for boot:
# (we don't use e2fsck.static, since we can link libc.so dynamically)
# NOTE: we need to link libgcc statically, it might be under /usr/local!
# => do not add a -Bdynamic - but instead list the dynamic libraries
# before the -Bstatic
	cd ${WRKSRC}/e2fsck && ${RM} -f e2fsck \
		&& ${MAKE_CMD} e2fsck V=1 \
		LIBS="-static-libgcc -lc -Bstatic ../lib/libsupport.a ../lib/libext2fs.a ../lib/libcom_err.a \
		${_staticlibs} /usr/lib/libexecinfo.a /usr/lib/libelf.a \
		${LOCALBASE}/lib/libblkid.a ${LOCALBASE}/lib/libuuid.a ${libintl} ../lib/libe2p.a " \
		&& ${STRIP_CMD} e2fsck
# Regression check: avoid a port (not upstream!) regression from 1.40.5,
# check that e2fsck isn't dynalinked against anything but libc.so:
	@${ECHO_CMD} -n "===>  checking that e2fsck depends on no shared objects outside /lib: "
	@a="$$(ldd ${WRKSRC}/e2fsck/e2fsck 2>/dev/null \
	    | ${GREP} -v 'not a dynamic executable' \
	    | ${GREP} '=>' \
	    | ${AWK}  '{print $$3;}' \
	    | ${EGREP} -v '^/lib/lib.*\.so\.' || :)"; \
	if test "x$$a" = "x" ; then echo 'PASS' ; else \
	    echo 'FAIL' ; echo '===>  e2fsck depends on:' ; echo "$$a" ; exit 1 ; fi
# Update translation binary files
.if ${PORT_OPTIONS:MNLS}
	cd ${WRKSRC}/po && ${MAKE_CMD} update-gmo
.endif
# Build fsck(8) wrapper
	${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} -s ${LIBS} \
		-o ${WRKSRC}/fsck_ext2fs ${FILESDIR}/fsck_ext2fs.c
# While the ${MAKE} check can take a minute on an end user's system, the
# correctness of tools such as e2fsck is critical to the health of the
# file systems.  The upstream is not using any *BSD as his development
# system, and therefore let's exercise due diligence in running the self-
# test on each and every system and not just package building hosts.
# There have been subtle failures induced by Linux-isms in the past.
# -- Matthias Andree, package maintainer, 2007-09-18
.if empty(PORT_OPTIONS:MNOTESTS)
	@${ECHO_CMD} '===>  Running e2fsprogs self-test suite'
# do not add -j options unconditionally to ${MAKE_CMD} below, this might break
# due to excessive disk space use.
	cd ${WRKSRC}/tests && \
		ulimit -t ${_check_timeout} && \
		${MKDIR} ${WRKDIR}/tmp && \
		${SETENV} e2fsprogs_inhibit_SIGINFO=1 BLKID_FILE=${WRKDIR}/tmp/blkid.tab SHELL=${_CHECK_SHELL} \
		${MAKE_CMD} ${_check_target} ${_CHECK_JOBS} ${_checkaddargs} \
	    || { head -n30000 ${WRKSRC}/tests/*.failed 2>/dev/null ; exit 1 ; }
.else
	@${ECHO_CMD} '===>  SKIPPING e2fsprogs self-test suite (DISCOURAGED!)'
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fsck_ext2fs ${STAGEDIR}${PREFIX}/sbin/
	${LN} -fs e2fsck ${STAGEDIR}${PREFIX}/sbin/fsck.ext2
	${LN} -fs e2fsck ${STAGEDIR}${PREFIX}/sbin/fsck.ext3
	${LN} -fs e2fsck ${STAGEDIR}${PREFIX}/sbin/fsck.ext4
	# now the remainder of the usual post-install jobs:
	${INSTALL_MAN} ${FILESDIR}/fsck_ext2fs.8 ${STAGEDIR}${PREFIX}/share/man/man8/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	# remove or relocate files installed by other ports already, or shadowing system files:
	${MV} ${STAGEDIR}${PREFIX}/bin/compile_et ${STAGEDIR}${PREFIX}/bin/e2fsprogs-compile_et
	${RM} ${STAGEDIR}${PREFIX}/sbin/findfs
	${MV} ${STAGEDIR}${PREFIX}/share/man/man1/compile_et.1 ${STAGEDIR}${PREFIX}/share/man/man1/e2fsprogs-compile_et.1
	${MKDIR} ${STAGEDIR}${DATADIR}/et/
	${MV} ${STAGEDIR}${PREFIX}/share/et/* ${STAGEDIR}${DATADIR}/et/
	${REINPLACE_CMD} -e 's}^DIR=.*$$}DIR=${DATADIR}/et}' -i '' ${STAGEDIR}${PREFIX}/bin/e2fsprogs-compile_et
	${RMDIR} ${STAGEDIR}${PREFIX}/share/et
	${MV} -f ${STAGEDIR}${PREFIX}/share/man/man3/com_err.3 \
		 ${STAGEDIR}${PREFIX}/share/man/man3/e2fsprogs-com_err.3
	${RM} ${STAGEDIR}${PREFIX}/share/man/man3/libblkid.3
	${RM} ${STAGEDIR}${PREFIX}/share/man/man8/findfs.8

#
# the next line closes .if ${MASTERDIR} == ${.CURDIR}
.endif

.include <bsd.port.post.mk>
