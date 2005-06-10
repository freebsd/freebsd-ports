# New ports collection makefile for:	linux_base-rh-7.3
# Date created:				2005-01-11
# Whom:					trevor
# based on ports/emulators/linux_base by Marcel Moolenaar and others
#
# $FreeBSD$
#

PORTNAME=		linux_base-rh
PORTVERSION=		7.3
CATEGORIES=		emulators linux
MASTER_SITES=	${MASTER_SITE_REDHAT_LINUX} ${MASTER_SITE_LOCAL:S/$/:x11/} \
		http://download.fedoralegacy.org/redhat/7.3/updates/i386/:legacy
MASTER_SITE_SUBDIR=	7.3/en/os/i386/RedHat/RPMS trevor/:x11
DISTFILES=	\
	glibc-common-2.2.5-44.legacy.3.i386.rpm:legacy \
	glibc-2.2.5-44.legacy.3.i386.rpm:legacy \
	redhat-release-7.3-1.noarch.rpm \
	setup-2.5.12-1.noarch.rpm \
	filesystem-2.1.6-2.noarch.rpm \
	basesystem-7.0-2.noarch.rpm \
	termcap-11.0.1-10.noarch.rpm \
	db1-1.85-8.i386.rpm \
	db3-3.3.11-6.i386.rpm \
	gdbm-1.8.0-14.i386.rpm \
	glib-1.2.10-5.i386.rpm \
	glib2-2.0.1-2.i386.rpm \
	libtermcap-2.0.8-28.i386.rpm \
	bash-2.05a-13.i386.rpm \
	bzip2-libs-1.0.2-2.i386.rpm \
	bzip2-1.0.2-2.i386.rpm \
	libstdc++-2.96-110.i386.rpm \
	compat-libstdc++-6.2-2.9.0.16.i386.rpm \
	ncurses-5.2-26.i386.rpm \
	info-4.1-1.i386.rpm \
	fileutils-4.1-10.i386.rpm \
	grep-2.5.1-1.i386.rpm \
	popt-1.6.4-7x.18.i386.rpm \
	readline-4.2a-4.i386.rpm \
	setserial-2.17-5.i386.rpm \
	slang-1.4.5-2.i386.rpm \
	sh-utils-2.0.11-14.i386.rpm \
	rpm-4.0.4-7x.18.i386.rpm \
	zlib-1.1.3-25.7.i386.rpm \
	XFree86-libs-4.3.0-78.EL.tj.i386.rpm:x11

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Basic packages for Linux mode from Red Hat 7.3/i386

EXTRACT_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

CONFLICTS=	linux_base-7.1* linux_base-debian* \
		linux_base-gentoo* linux_base-rh-9* linux_base-suse-9* \
		linux-XFree86-libs*

NO_LATEST_LINK=		yes
ONLY_FOR_ARCHS=		amd64 i386
DIST_SUBDIR=		rpm/rh-7.3
PREFIX=			${LINUXBASE}
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PLIST=			${WRKDIR}/plist

.undef USE_LINUX

.include <bsd.port.pre.mk>
DBPATH=			/var/lib/rpm
RPMDIR=			${DISTDIR}/${DIST_SUBDIR}
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
	@${MKDIR} ${WRKSRC}/${DBPATH} ${WRKSRC}/var/tmp ${WRKSRC}/lib
	@cd ${WRKSRC}/lib && ${LN} -sf libtermcap.so.2.0.8 libtermcap.so.2
	LC_ALL=C rpm --initdb --root ${WRKSRC} --dbpath ${DBPATH}
#
# Install all packages. Ignore dependencies just like the Red Hat installer.
# Also, set the ELF fallback brand to Linux, so that we don't have to do
# anything special to run statically linked binaries.
	@/sbin/sysctl -w ${FALLBACK_ELF_MIB}=${LINUX_ELF}
	@for R in ${DISTFILES:S/:legacy//:S/:x11//}; do \
		LC_ALL=C rpm -U --root ${WRKSRC} --dbpath ${DBPATH} --nodeps \
			--replacepkgs --ignoreos --ignorearch ${RPMDIR}/$$R; \
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

pre-package:
	@${ECHO_MSG} ""
	@${ECHO_MSG} If you are distributing the package, you may be required
	@${ECHO_MSG} to offer the sources as well.  You can do this easily
	@${ECHO_MSG} with the emulators/linux_base-src-rh-7.3 port.
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
