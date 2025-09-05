PORTNAME=	rl9
PORTVERSION=	${LINUX_DIST_VER}
PORTREVISION=	1
CATEGORIES=	emulators linux
PKGNAMEPREFIX=	linux_base-
EXTRACT_ONLY=	${DISTFILES:N*${SRC_SUFX}*:Nf/filesystem-*:C/:[^:]+$//}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode (Rocky Linux ${LINUX_DIST_VER})

LICENSE=	BSD2CLAUSE

USES=		linux:rl9
USE_LINUX=	# empty
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

# lib64/gconv/ stuff that is loaded dynamically and has rpath
NO_SHLIB_REQUIRES_GLOB=	libCNS.so* libGB.so* libISOIR165.so* \
			libJIS.so* libJISX0213.so* libKSC.so*

.include	"${.CURDIR}/Makefile.version"

BIN_DISTNAMES=	bash-${bash_ver} \
		bzip2-${bzip2_ver} \
		coreutils-${coreutils_ver} \
		diffutils-${diffutils_ver} \
		e2fsprogs-${e2fsprogs_ver} \
		filesystem-${filesystem_ver} \
		findutils-${findutils_ver} \
		fuse-${fuse_ver} \
		gawk-${gawk_ver} \
		glibc-all-langpacks-${glibc_ver} \
		glibc-common-${glibc_ver} \
		grep-${grep_ver} \
		info-${info_ver} \
		keyutils-${keyutils_ver} \
		less-${less_ver} \
		ncurses-${ncurses_ver} \
		sed-${sed_ver} \
		setserial-${setserial_ver} \
		sqlite-${sqlite_ver} \
		util-linux-${util_ver} \
		util-linux-core-${util_ver} \
		which-${which_ver}
LIB_DISTNAMES=	bzip2-libs-${bzip2_ver} \
		e2fsprogs-libs-${e2fsprogs_ver} \
		fuse-libs-${fuse_ver} \
		gdbm-libs-${gdbm_ver} \
		geocode-glib-${geocode-glib_ver} \
		glib-networking-${glib-networking_ver} \
		glib2-${glib2_ver} \
		glibc-${glibc_ver} \
		glibc-gconv-extra-${glibc_ver} \
		gmp-${gmp_ver} \
		json-glib-${json-glib_ver} \
		keyutils-libs-${keyutils_ver} \
		krb5-libs-${krb5_ver} \
		libacl-${libacl_ver} \
		libattr-${libattr_ver} \
		libblkid-${util_ver} \
		libbrotli-${brotli_ver} \
		libcap-${libcap_ver}  \
		libcom_err-${e2fsprogs_ver} \
		libdatrie-${libdatrie_ver} \
		libdb-${libdb_ver} \
		libedit-${libedit_ver} \
		libevdev-${libevdev_ver} \
		libfdisk-${util_ver} \
		libffi-${libffi_ver} \
		libgcc-${gcc_ver} \
		libgudev-${libgudev_ver} \
		libidn2-${libidn2_ver} \
		libmount-${util_ver} \
		libnsl-${glibc_ver} \
		libproxy-${libproxy_ver} \
		libpsl-${libpsl_ver} \
		libselinux-${selinux_ver} \
		libsepol-${sepol_ver} \
		libsigsegv-${libsigsegv_ver} \
		libsmartcols-${util_ver} \
		libsoup-${libsoup_ver} \
		libstdc++-${gcc_ver} \
		libunistring-${libunistring_ver} \
		libuuid-${util_ver} \
		libverto-${libverto_ver} \
		libxcrypt-${libxcrypt_ver} \
		libzstd-${zstd_ver} \
		mpfr-${mpfr_ver} \
		mtdev-${mtdev_ver} \
		ncurses-libs-${ncurses_ver} \
		openssl-libs-${openssl_ver} \
		pcre-${pcre_ver} \
		pcre-utf16-${pcre_ver} \
		pcre-utf32-${pcre_ver} \
		pcre2-${pcre2_ver} \
		pcre2-utf16-${pcre2_ver} \
		pcre2-utf32-${pcre2_ver} \
		popt-${popt_ver} \
		readline-${readline_ver} \
		slang-${slang_ver} \
		sqlite-libs-${sqlite_ver} \
		xz-libs-${xz_ver} \
		zlib-${zlib_ver}

SHARE_DISTNAMES=basesystem-${basesystem_ver} \
		ncurses-base-${ncurses_ver} \
		rocky-release-${rocky-release_ver} \
		setup-${setup_ver}
SRC_DISTFILES=	acl-${libacl_ver}${SRC_SUFX}:SOURCE \
		attr-${libattr_ver}${SRC_SUFX}:SOURCE \
		basesystem-${basesystem_ver}${SRC_SUFX}:SOURCE \
		bash-${bash_ver}${SRC_SUFX}:SOURCE \
		bzip2-${bzip2_ver}${SRC_SUFX}:SOURCE \
		coreutils-${coreutils_ver}${SRC_SUFX}:SOURCE \
		diffutils-${diffutils_ver}${SRC_SUFX}:SOURCE \
		e2fsprogs-${e2fsprogs_ver}${SRC_SUFX}:SOURCE \
		filesystem-${filesystem_ver}${SRC_SUFX}:SOURCE \
		findutils-${findutils_ver}${SRC_SUFX}:SOURCE \
		fuse-${fuse_ver}${SRC_SUFX}:SOURCE \
		gawk-${gawk_ver}${SRC_SUFX}:SOURCE \
		gcc-${gcc_ver}${SRC_SUFX}:SOURCE \
		gdbm-${gdbm_ver}${SRC_SUFX}:SOURCE \
		geocode-glib-${geocode-glib_ver}${SRC_SUFX}:SOURCE \
		glib-networking-${glib-networking_ver}${SRC_SUFX}:SOURCE \
		glib2-${glib2_ver}${SRC_SUFX}:SOURCE \
		glibc-${glibc_ver}${SRC_SUFX}:SOURCE \
		gmp-${gmp_ver}${SRC_SUFX}:SOURCE \
		grep-${grep_ver}${SRC_SUFX}:SOURCE \
		json-glib-${json-glib_ver}${SRC_SUFX}:SOURCE \
		keyutils-${keyutils_ver}${SRC_SUFX}:SOURCE \
		krb5-${krb5_ver}${SRC_SUFX}:SOURCE \
		less-${less_ver}${SRC_SUFX}:SOURCE \
		libcap-${libcap_ver}${SRC_SUFX}:SOURCE \
		libdatrie-${libdatrie_ver}${SRC_SUFX}:SOURCE \
		libdb-${libdb_ver}${SRC_SUFX}:SOURCE \
		libedit-${libedit_ver}${SRC_SUFX}:SOURCE \
		libevdev-${libevdev_ver}${SRC_SUFX}:SOURCE \
		libffi-${libffi_ver}${SRC_SUFX}:SOURCE \
		libgudev-${libgudev_ver}${SRC_SUFX}:SOURCE \
		libproxy-${libproxy_ver}${SRC_SUFX}:SOURCE \
		libselinux-${selinux_ver}${SRC_SUFX}:SOURCE \
		libsepol-${sepol_ver}${SRC_SUFX}:SOURCE \
		libsigsegv-${libsigsegv_ver}${SRC_SUFX}:SOURCE \
		libsoup-${libsoup_ver}${SRC_SUFX}:SOURCE \
		libverto-${libverto_ver}${SRC_SUFX}:SOURCE \
		libxcrypt-${libxcrypt_ver}${SRC_SUFX}:SOURCE \
		mpfr-${mpfr_ver}${SRC_SUFX}:SOURCE \
		mtdev-${mtdev_ver}${SRC_SUFX}:SOURCE \
		ncurses-${ncurses_ver}${SRC_SUFX}:SOURCE \
		openssl-${openssl_ver}${SRC_SUFX}:SOURCE \
		pcre-${pcre_ver}${SRC_SUFX}:SOURCE \
		pcre2-${pcre2_ver}${SRC_SUFX}:SOURCE \
		popt-${popt_ver}${SRC_SUFX}:SOURCE \
		readline-${readline_ver}${SRC_SUFX}:SOURCE \
		rocky-release-${rocky-release_ver}${SRC_SUFX}:SOURCE \
		sed-${sed_ver}${SRC_SUFX}:SOURCE \
		setserial-${setserial_ver}${SRC_SUFX}:SOURCE \
		setup-${setup_ver}${SRC_SUFX}:SOURCE \
		slang-${slang_ver}${SRC_SUFX}:SOURCE \
		texinfo-${info_ver}${SRC_SUFX}:SOURCE \
		util-linux-${util_ver}${SRC_SUFX}:SOURCE \
		which-${which_ver}${SRC_SUFX}:SOURCE \
		xz-${xz_ver}${SRC_SUFX}:SOURCE \
		zlib-${zlib_ver}${SRC_SUFX}:SOURCE \
		zstd-${zstd_ver}${SRC_SUFX}:SOURCE \

PLIST_SUB=	LINUXBASE=${LINUXBASE} SYSCTLMIB=${SYSCTLMIB}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

REMOVE_DIRS=	boot etc/pam.d home media mnt proc root run sys tmp var/log \
		var/tmp
REMOVE_FILES=	bin/chfn bin/chsh bin/findmnt bin/login bin/lsblk bin/lscpu \
		bin/lsipc bin/lslogins bin/lsmem bin/lsns bin/script \
		bin/setpriv bin/su \
		etc/exports etc/group etc/gshadow etc/motd \
		etc/passwd etc/printcap etc/protocols etc/services etc/shadow \
		sbin/clock sbin/debugfs sbin/hwclock sbin/runuser sbin/zramctl \
		usr/bin/chrt usr/bin/dmesg usr/bin/flock usr/bin/hardlink \
		usr/bin/ionice usr/bin/ipcmk usr/bin/ipcrm usr/bin/ipcs usr/bin/kill \
		usr/bin/logger usr/bin/nsenter usr/bin/renice usr/bin/setsid \
		usr/bin/taskset usr/bin/unshare usr/sbin/agetty usr/sbin/blkid \
		usr/sbin/blockdev usr/sbin/fsck usr/sbin/losetup usr/sbin/mkswap \
		usr/sbin/partx usr/sbin/swapoff usr/sbin/swapon usr/sbin/switch_root \
		usr/lib/gio/modules/libgiognutls.so usr/lib64/gio/modules/libgiognutls.so \
		usr/share/man/man1/chrt.1.gz usr/share/man/man1/dmesg.1.gz \
		usr/share/man/man1/flock.1.gz usr/share/man/man1/hardlink.1.gz \
		usr/share/man/man1/ionice.1.gz usr/share/man/man1/ipcmk.1.gz \
		usr/share/man/man1/ipcrm.1.gz usr/share/man/man1/ipcs.1.gz \
		usr/share/man/man1/kill.1.gz usr/share/man/man1/logger.1.gz \
		usr/share/man/man1/nsenter.1.gz usr/share/man/man1/renice.1.gz \
		usr/share/man/man1/setsid.1.gz usr/share/man/man1/taskset.1.gz \
		usr/share/man/man1/unshare.1.gz usr/share/man/man8/agetty.8.gz \
		usr/share/man/man8/blkid.8.gz usr/share/man/man8/blockdev.8.gz \
		usr/share/man/man8/findmnt.8.gz usr/share/man/man8/fsck.8.gz \
		usr/share/man/man8/losetup.8.gz usr/share/man/man8/mkswap.8.gz \
		usr/share/man/man8/partx.8.gz usr/share/man/man8/swapoff.8.gz \
		usr/share/man/man8/swapon.8.gz usr/share/man/man8/switch_root.8.gz

.include <bsd.port.options.mk>

PLIST_SUB+=	NEWGLIBC=""

.if ${ARCH} == aarch64 || ${ARCH} == amd64
SYSCTLMIB=	kern.features.linux64
.else
SYSCTLMIB=	compat.linux.osrelease
.endif

post-extract:
# These directories become symbolic links when the filesystem distfile is
# extracted.  Other distfiles cannot be extracted when these are links so the
# filesystem distfile must be extracted last.
.for d in bin lib lib64 sbin
	@(cd ${WRKSRC} && if [ -e ${d} -a ! -L ${d} ]; then \
		${FIND} ${d} | ${CPIO} -dumpl --quiet usr && ${RM} -r ${d}; fi)
.endfor
	@(cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/f/filesystem-${filesystem_ver}${EXTRACT_SUFX_${ARCH}} \
		${EXTRACT_AFTER_ARGS})
.if ${ARCH} == i386
	@${CHMOD} u+w ${WRKSRC}/usr/lib/pm-utils
.elif ${ARCH} == aarch64 || ${ARCH} == amd64
	@${CHMOD} u+w ${WRKSRC}/usr/lib64/pm-utils
.endif

post-patch:
	@${RM} -r ${REMOVE_DIRS:S|^|${WRKSRC}/|}
	@${RM} ${REMOVE_FILES:S|^|${WRKSRC}/|}
	@${FIND} ${WRKSRC}/usr -type d -empty -not -path '*/lib*/gio/*' -delete
.if ${ARCH} == aarch64
	${BRANDELF} -t Linux ${WRKSRC}/usr/lib/ld-linux-*
.else
	${BRANDELF} -t Linux ${WRKSRC}/usr/lib64/ld-linux-*.so.2
.endif

post-install:
	${RM} -r ${STAGEDIR}${LOCALBASE}
	${MV} ${STAGEDIR}${PREFIX}/etc/krb5.conf \
		${STAGEDIR}${PREFIX}/etc/krb5.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/nsswitch.conf \
		${STAGEDIR}${PREFIX}/etc/nsswitch.conf.sample
	${LN} -sf "../proc/self/mounts" ${STAGEDIR}${PREFIX}/etc/mtab
	${LN} -sf ${LOCALBASE}/share/icons ${STAGEDIR}${PREFIX}/usr/share/icons
	${LN} -sf /var/run ${STAGEDIR}${PREFIX}/run
	${LN} -sf /var/tmp ${STAGEDIR}${PREFIX}/usr/tmp

.include <bsd.port.mk>
