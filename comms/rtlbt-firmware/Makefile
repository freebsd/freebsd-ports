PORTNAME=	rtlbt-firmware
DISTVERSION=	20251111
DEB_REVISION=	1
CATEGORIES=	comms
MASTER_SITES=	DEBIAN/pool/non-free-firmware/f/firmware-nonfree/
DISTNAME=	firmware-realtek_${PORTVERSION}-${DEB_REVISION}_all
EXTRACT_SUFX=	.deb

MAINTAINER=	wulf@FreeBSD.org
COMMENT=	Realtek USB bluetooth adaptor firmwares used by rtlbtfw(8)
WWW=		https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git

LICENSE=	REALTEK
LICENSE_NAME=	Realtek firmware license
LICENSE_FILE=	${WRKDIR}/usr/share/doc/firmware-realtek/copyright
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

NO_BUILD=	yes
NO_ARCH=	yes

EXTRACT_CMD=	${AR}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	data.tar.xz | ${TAR} -xf - ${EXTRACT_FILES}
EXTRACT_FILES=	usr/lib/firmware/rtl_bt \
		usr/share/doc/firmware-realtek/copyright

do-install:
	cd ${WRKDIR}/usr/lib/firmware/rtl_bt && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
