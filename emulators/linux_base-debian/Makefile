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
DISTFILES=	basedebs.tar util-linux-locales_2.11n-4_all.deb
EXTRACT_ONLY=	basedebs.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Debian base set for the Linux mode

BUILD_DEPENDS=	${DPKG_CMD}:${PORTSDIR}/archivers/dpkg

CONFLICTS=	linux_base-*
DIST_SUBDIR=	debian-${PORTVERSION}-${DISTDATE}
DISTDATE=	2002-07-18
WRKSRC=		${WRKDIR}/var/cache/apt/archives
NO_BUILD=	yes
NO_MTREE=	yes
NO_FILTER_SHLIBS= yes
ONLY_FOR_ARCHS=	i386

PREFIX?=	${LINUXBASE}
DPKGDB=		${PREFIX}/var/lib/dpkg
DPKG_CMD?=	${LOCALBASE}/bin/dpkg
DPKG_ARGS=	--force-architecture --force-depends
DPKG=		${BATCHENV} PATH="${PATH}:${LOCALBASE}/sbin" ${DPKG_CMD} \
		--root=${PREFIX} --admindir=${DPKGDB} ${DPKG_ARGS}
LIBC6NAME=	libc6_2.2.5-6_${ARCH}
INSTALL_INFO?=	install-info

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
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/util-linux-locales_2.11n-4_all.deb \
		${WRKSRC}

do-patch: build-depends
	cd ${WRKSRC} && \
	${DPKG_CMD} -x ${LIBC6NAME}.deb ${LIBC6NAME} && \
	${DPKG_CMD} -e ${LIBC6NAME}.deb ${LIBC6NAME}/DEBIAN && \
	brandelf -t Linux ${WRKSRC}/${LIBC6NAME}/sbin/ldconfig && \
	${DPKG_CMD} -b ${LIBC6NAME}

do-install:
# Create /dev/null for the chrooted environment
	${MKDIR} ${PREFIX}/dev
	${RM} -f ${PREFIX}/dev/null
	mknod ${PREFIX}/dev/null c 2 2
	${CHMOD} 666 ${PREFIX}/dev/null

# Extract packages that will be used while the install session
	${MKDIR} ${DPKGDB}
.for pkg in dpkg shellutils libc6 debconf bash libncurses5 fileutils \
		perl-base sysvinit textutils grep sed findutils
	${DPKG_CMD} -x ${WRKSRC}/${pkg}_*.deb ${PREFIX}
.endfor

# Touch empty data files
	${MKDIR} ${PREFIX}/usr/info
	${INSTALL_INFO} ${PREFIX}/usr/share/info/fileutils.info.gz \
		${PREFIX}/usr/info/dir
	${TOUCH} ${DPKGDB}/status ${DPKGDB}/available

# Pre-generate timezone file for noninteractive
.if defined(BATCH)
	${ECHO_CMD} "Etc/GMT" > ${PREFIX}/etc/timezone
.endif

# Install the `special' base packages that must be installed before all
	${DPKG} -i ${WRKSRC}/dpkg_*.deb
	${DPKG} --force-all -i ${WRKSRC}/libc6_*.deb

# Install the base packages
	${MKDIR} ${WRKSRC}/instpkgs
	for pkg in ${BASEPACKAGES}; do \
		${LN} -sf ${WRKSRC}/$${pkg}_*.deb ${WRKSRC}/instpkgs/; \
	done
	${DPKG} -i ${WRKSRC}/instpkgs/*

	${RM} -rf ${PREFIX}/tmp/* ${PREFIX}/etc/timezone.*

.include <bsd.port.mk>
