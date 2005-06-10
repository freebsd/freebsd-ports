# New ports collection makefile for:	linux_base-suse-9.2
# Date created:				2005-01-11
# Whom:					trevor
# based on ports/emulators/linux_base by Marcel Moolenaar and others
#
# $FreeBSD$
# $FreeBSD$
#

PORTNAME=		linux_base-suse
PORTVERSION=		9.2
CATEGORIES=		emulators linux
MASTER_SITES=		${MASTER_SITE_SUSE} ${MASTER_SITE_SUSE:S/$/:update/}
MASTER_SITE_SUBDIR=	i386/9.2/suse/i586 i386/update/9.2/rpm/i586/:update
DISTFILES=	\
	suse-release-9.2-3.1.i586.rpm \
	glibc-locale-2.3.3-118.i586.rpm \
	glibc-2.3.3-118.i586.rpm \
	filesystem-9.2-2.1.i586.rpm \
	libattr-2.4.16-2.i586.rpm \
	db-4.2.52-90.i586.rpm \
	compat-gdbm-1.8.0-4.i586.rpm \
	glib-1.2.10-589.i586.rpm \
	bash-3.0-8.2.i586.rpm:update \
	ncurses-5.4-65.i586.rpm \
	readline-5.0-1.2.i586.rpm:update \
	zlib-1.2.1-74.i586.rpm \
	bzip2-1.0.2-347.i586.rpm \
	libzio-0.1-4.i586.rpm \
	info-4.7-6.i586.rpm \
	grep-2.5.1-431.i586.rpm \
	desktop-file-utils-0.7-2.1.i586.rpm \
	coreutils-5.2.1-32.i586.rpm \
	popt-1.7-190.i586.rpm \
	insserv-1.00.5-6.2.i586.rpm \
	setserial-2.17-579.i586.rpm \
	libstdc++-3.3.4-11.i586.rpm \
	slang-1.4.9-123.i586.rpm \
	libacl-2.2.25-2.i586.rpm \
	libselinux-1.16-3.i586.rpm \
	rpm-4.1.1-191.i586.rpm \
	libgcc-3.3.4-11.i586.rpm \
	termcap-2.0.8-878.i586.rpm

MAINTAINER=		trevor@FreeBSD.org
COMMENT=		Basic packages for Linux mode from SUSE 9.2/i386

EXTRACT_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

CONFLICTS=		linux_base-7* linux_base-debian* \
			linux_base-gentoo* linux_base-rh* linux_base-suse-9.1*

RESTRICTED=	"binaries under GNU GPL:  http://www.gnu.org/licenses/gpl.txt"
ONLY_FOR_ARCHS=		amd64 i386
DIST_SUBDIR=		rpm/i386/suse/9.2
PREFIX=			${LINUXBASE}
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PLIST=			${WRKDIR}/plist

# Avoid cyclic dependency.
.undef USE_LINUX

.include <bsd.port.pre.mk>
REMOVE_DIRS=		boot dev home initrd root tmp var/tmp usr/local usr/tmp
REMOVE_FILES=		bin/df bin/su etc/exports etc/group etc/localtime \
			etc/motd etc/passwd etc/printcap etc/services \
			etc/protocols
BRAND_FILES=		bin/rpm sbin/ldconfig

.if (${ARCH} == "amd64")
LATEST_LINK:=	${LATEST_LINK:C/linux/linux32/}
FALLBACK_ELF_MIB=	kern.elf32.fallback_brand
.else
FALLBACK_ELF_MIB=	kern.fallback_elf_brand
.endif
LINUX_ELF=		3
PREVIOUS_ELF!=		/sbin/sysctl -n ${FALLBACK_ELF_MIB}

do-extract:
#
# Handle the loading of the linux loadable kernel module if required.
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${MKDIR} ${WRKSRC}/var/lib/rpm ${WRKSRC}/var/tmp ${WRKSRC}/lib
	@cd ${WRKSRC}/lib && ${LN} -sf libtermcap.so.2.0.8 libtermcap.so.2
	LC_ALL=C rpm --initdb --root ${WRKSRC} --dbpath /var/lib/rpm
#
# Install all packages. Ignore dependencies just like the Red Hat installer.
# Also, set the ELF fallback brand to Linux, so that we don't have to do
# anything special to run statically linked binaries.
	@/sbin/sysctl -w ${FALLBACK_ELF_MIB}=${LINUX_ELF}
	@for ii in ${DISTFILES:S/:update//}; do \
		LC_ALL=C rpm -U --root ${WRKSRC} --dbpath /var/lib/rpm \
			--nodeps --replacepkgs --ignoreos --ignorearch \
			${DISTDIR}/${DIST_SUBDIR}/$$ii; \
	done
	@for F in ${BRAND_FILES}; do \
		${BRANDELF} -t Linux ${WRKSRC}/$$F; \
	done
	@/sbin/sysctl -w ${FALLBACK_ELF_MIB}=${PREVIOUS_ELF}
#
# Install yp.conf as a hint to NIS users and make sure there's an
# mtab in etc, albeit an empty one. This is needed in a couple of
# cases, notably staroffice6.
#
	${INSTALL} ${COPY} -m 644 ${FILESDIR}/yp.conf ${WRKSRC}/etc
	${TOUCH} ${WRKSRC}/etc/mtab ${WRKSRC}/etc/host.conf
#
# Finish
#
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${WRKSRC}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} -f ${WRKSRC}/$$F; \
	done
	@${LN} -sf /var/tmp ${WRKSRC}/usr/tmp

do-build:
#
# Generate packing list.
	cd ${WRKSRC} && ${FIND} -s * -type f -o -type l > ${PLIST} \
		&& ${FIND} -d * -type d | ${SED} -e 's:^:@dirrm :' >> ${PLIST}

do-install:
#
# Try to hard-link the contents of the work directory to the installation
# directory.  If hard-linking is possible (installing to the same mount point),
# no disk space is consumed in the installation step.  The fallback is to copy,
# and cpio is noisy in this case.
	cd ${WRKSRC} && ${FIND} * | ${CPIO} -dlmp ${PREFIX}
	${FIND} ${PREFIX} -type d -exec ${CHMOD} 755 \{\} \;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
