# Created by: Vladimir Kondratyev <wulf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iwmbt-firmware
PORTVERSION=	20190717
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	DEBIAN/pool/non-free/f/firmware-nonfree/
DISTNAME=	firmware-iwlwifi_${PORTVERSION}-2_all
EXTRACT_SUFX=	.deb

MAINTAINER=	wulf@FreeBSD.org
COMMENT=	Intel Wireless 8260 bluetooth adaptor firmwares used by iwmbtfw(8)

LICENSE=	INTEL
LICENSE_NAME=	Intel firmware license
LICENSE_FILE=	${WRKDIR}/usr/share/doc/firmware-iwlwifi/copyright
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

NO_BUILD=	yes
NO_ARCH=	yes

EXTRACT_CMD=	${AR}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	data.tar.xz | ${TAR} -xf - ${EXTRACT_FILES}
EXTRACT_FILES=	lib/firmware/intel/ibt-*.sfi \
		lib/firmware/intel/ibt-*.ddc \
		usr/share/doc/firmware-iwlwifi/copyright

do-install:
	cd ${WRKDIR}/lib/firmware/intel && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
