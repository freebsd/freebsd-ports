PORTNAME=	iwmbt-firmware
DISTVERSION=	20250410
DEB_REVISION=	2
CATEGORIES=	comms
MASTER_SITES=	DEBIAN/pool/non-free-firmware/f/firmware-nonfree/:main \
		https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/intel/:old
DISTFILES=	${MAINFW_FILE}:main \
		${OLDFW_FILE}${OLDFW_SUFX}:old
EXTRACT_ONLY=	${MAINFW_FILE}

MAINTAINER=	wulf@FreeBSD.org
COMMENT=	Intel Wireless 8260 bluetooth adaptor firmwares used by iwmbtfw(8)
WWW=		https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git

LICENSE=	INTEL
LICENSE_NAME=	Intel firmware license
LICENSE_FILE=	${WRKDIR}/usr/share/doc/firmware-iwlwifi/copyright
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

NO_BUILD=	yes
NO_ARCH=	yes

MAINFW_FILE=	firmware-iwlwifi_${DISTVERSION}-${DEB_REVISION}_all.deb
OLDFW_FILE=	ibt-hw-37.8.10-fw-22.50.19.14.f.bseq
OLDFW_SUFX=	?id=6be4747ea1d731f661c5320acf3f1273a459d6da

EXTRACT_CMD=	${AR}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	data.tar.xz | ${TAR} -xf - ${EXTRACT_FILES}
EXTRACT_FILES=	usr/lib/firmware/intel \
		usr/share/doc/firmware-iwlwifi/copyright

# PR/267581: Downgrade ibt-hw-37.8.10-fw-22.50.19.14.f.bseq to fw_patch_num 36
post-extract:
	${CP} ${DISTDIR}/${OLDFW_FILE}${OLDFW_SUFX} ${WRKDIR}/usr/lib/firmware/intel/${OLDFW_FILE}

do-install:
	cd ${WRKDIR}/usr/lib/firmware/intel && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
