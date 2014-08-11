# Created by: vassilisl
# $FreeBSD$

PORTNAME=	dbus
PORTVERSION=	1
CATEGORIES=	devel linux
MASTER_SITES=		http://archives.fedoraproject.org/pub/fedora/linux/releases/${LINUX_RPM_VERSION}/Everything/${LINUX_CPU_ARCH}/os/Packages/
PKGNAMEPREFIX=	linux-f20-
DISTFILES=	${BIN_DISTFILES}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	D-BUS message bus & X11-requiring add-ons for D-BUS (Linux Fedora 20)

BIN_DISTFILES=	\
	d/dbus-1.6.12-1.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
	d/dbus-x11-1.6.12-1.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm

ONLY_FOR_ARCHS=	i386 amd64
LINUX_CPU_ARCH=		i386
LINUX_RPM_ARCH=		i686
LINUX_RPM_VERSION=	20
USE_LINUX_PREFIX=	yes
NO_WRKSUBDIR=		yes
DISTINFO_FILE?=		${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

EXTRACT_CMD?=		${TAR}
EXTRACT_BEFORE_ARGS?=	-xPf
EXTRACT_AFTER_ARGS?=

do-build:

do-install:
	@cd ${WRKSRC} && ${FIND} * ! -path "stage*" -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/{}" \;
	@cd ${WRKSRC} && ${FIND} * ! -path "stage/*" ! -type d \
		| ${CPIO} -pm -R root:wheel ${STAGEDIR}${PREFIX}

post-install:
	@${WRKSRC}/bin/dbus-uuidgen --ensure=${STAGEDIR}${PREFIX}/var/lib/dbus/machine-id

USE_LDCONFIG=	yes

.include <bsd.port.mk>
