# Ports collection makefile for:  linux_base-debian
# Date created:		17 April 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	linux_base
PORTVERSION=	3.0.23
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	dists/woody/main/disks-${ARCH}/base-images-${PORTVERSION}-${DISTDATE} \
			pool/main/u/util-linux
PKGNAMESUFFIX=	-debian
DISTFILES=	basedebs.tar util-linux-locales_2.11n-7_all.deb
EXTRACT_ONLY=	basedebs.tar

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Debian base set for the Linux mode

CONFLICTS=	linux_base-7* linux_base-8* linux_base-gentoo* \
		linux_base-rh* linux_base-suse*
ONLY_FOR_ARCHS=	alpha amd64 i386

RESTRICTED=	"binaries under GNU GPL:  http://www.gnu.org/licenses/gpl.txt"

BUILD_DEPENDS=	${DPKG_CMD}:${PORTSDIR}/archivers/dpkg

PREFIX?=	${LINUXBASE}

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
LATEST_LINK=	${PORTNAME:C/linux_base/linux32_base/}
ARCH=		i386
.endif

DIST_SUBDIR=	debian-${PORTVERSION}-${DISTDATE}-${ARCH}
DISTDATE=	2002-07-18
WRKSRC=		${WRKDIR}/var/cache/apt/archives
MD5_FILE=	${MASTERDIR}/distinfo.${ARCH}
NO_BUILD=	yes
NO_MTREE=	yes
NO_FILTER_SHLIBS=	yes
DPKGDB=		${PREFIX}/var/lib/dpkg
DPKG_CMD?=	${LOCALBASE}/bin/dpkg
DPKG_ARGS=	--force-architecture --force-depends
DPKG=		${BATCHENV} PATH="${PATH}:${LOCALBASE}/sbin" ${DPKG_CMD} \
		--root=${PREFIX} --admindir=${DPKGDB} ${DPKG_ARGS}
LIBC6NAME=	libc6_2.2.5-6_${ARCH}
INSTALL_INFO?=	/usr/bin/install-info

.if defined(BATCH)
BATCHENV=	DEBIAN_FRONTEND=Noninteractive
.endif

BASEPACKAGES=	adduser apt-utils apt base-config base-files base-passwd \
		bash bsdmainutils bsdutils console-common console-data \
		console-tools console-tools-libs cpio debconf debianutils \
		diff e2fsprogs ed fdutils fileutils findutils gettext-base \
		grep groff-base gzip hostname info libcap1 libdb2 libdb3 \
		libgdbmg1 libident libldap2 liblockfile1 libncurses5 \
		libnewt0 libpam-modules libpam-runtime libpam0g libpcap0 \
		libpcre3 libpopt0 libreadline4 libsasl7 \
		libstdc++2.10-glibc2.2 libwrap0 login man-db manpages \
		mawk modutils mount nano ncurses-base ncurses-bin net-tools \
		netkit-inetd netkit-ping nvi passwd perl-base procps \
		psmisc sed shellutils slang1 sysvinit tar tasksel tcpd \
		telnet textutils util-linux util-linux-locales whiptail

post-extract:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/util-linux-locales_2.11n-7_all.deb \
		${WRKSRC}

do-install:
# Create /dev/null for the chrooted environment.
	${MKDIR} ${PREFIX}/dev
	${RM} -f ${PREFIX}/dev/null
	mknod ${PREFIX}/dev/null c 2 2
	${CHMOD} 666 ${PREFIX}/dev/null

# Extract packages that will be used during the installation session.
	${MKDIR} ${DPKGDB}
.for pkg in dpkg shellutils libc6 debconf bash libncurses5 fileutils \
		perl-base sysvinit textutils grep sed findutils
	${DPKG_CMD} -x ${WRKSRC}/${pkg}_*.deb ${PREFIX}
.endfor

# Touch empty data files.
	${MKDIR} ${PREFIX}/usr/info
	${INSTALL_INFO} ${PREFIX}/usr/share/info/fileutils.info.gz \
		${PREFIX}/usr/info/dir
	${TOUCH} ${DPKGDB}/status ${DPKGDB}/available

# Pre-generate timezone file, if this is a non-interactive build.
.if defined(BATCH)
	${ECHO_CMD} "Etc/GMT" > ${PREFIX}/etc/timezone
.endif

# These base packages must be installed first.
	${DPKG} -i ${WRKSRC}/dpkg_*.deb
	${DPKG} --unpack ${WRKSRC}/libc6_*.deb
	${BRANDELF} -t Linux ${PREFIX}/sbin/ldconfig
	${DPKG} --configure libc6

# Install the base packages.
	${MKDIR} ${WRKSRC}/instpkgs
	for pkg in ${BASEPACKAGES}; do \
		${LN} -sf ${WRKSRC}/$${pkg}_*.deb ${WRKSRC}/instpkgs/; \
	done
	${DPKG} -i ${WRKSRC}/instpkgs/*

# Clean up.
	${RM} -rf ${PREFIX}/tmp/* ${PREFIX}/etc/timezone.*

.include <bsd.port.post.mk>
