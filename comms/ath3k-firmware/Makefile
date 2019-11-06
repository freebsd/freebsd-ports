# Created by: Vladimir Kondratyev <wulf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ath3k-firmware
PORTVERSION=	20161130
CATEGORIES=	comms
MASTER_SITES=	DEBIAN/pool/non-free/f/firmware-nonfree/
DISTNAME=	firmware-atheros_${PORTVERSION}-4_all
EXTRACT_SUFX=	.deb

MAINTAINER=	wulf@FreeBSD.org
COMMENT=	Atheros AR3011/AR3012 bluetooth adaptor firmwares used by ath3kfw(8)

BROKEN=		unfetchable

LICENSE=	ATHEROS
LICENSE_NAME=	Atheros firmware license
LICENSE_FILE=	${WRKDIR}/usr/share/doc/firmware-atheros/copyright
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

NO_BUILD=	yes
NO_ARCH=	yes

EXTRACT_CMD=	${AR}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	data.tar.xz | ${TAR} -xf - ${EXTRACT_FILES}
EXTRACT_FILES=	lib/firmware/ar3k \
		lib/firmware/ath3k-1.fw \
		usr/share/doc/firmware-atheros/copyright

# Do not track for firmware updates that are irrelevant for us
# ath3k-firmware is a rather stable part of larger distribution package
PORTSCOUT=	ignore:1

SUB_FILES=	ath3k.conf

do-install:
	cd ${WRKDIR}/lib/firmware && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} \
		${WRKDIR}/ath3k.conf ${STAGEDIR}${PREFIX}/etc/devd/ath3k.conf

.include <bsd.port.mk>
