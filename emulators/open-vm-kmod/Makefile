PORTNAME=	open-vm-kmod
PORTVERSION=	13.0.10
DISTVERSIONPREFIX=	stable-
PORTEPOCH=	2
CATEGORIES=	emulators

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Open VMware kernel modules for FreeBSD VMware guests
WWW=		https://github.com/vmware/open-vm-tools

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/vmblock/COPYING
LICENSE_FILE_GPLv2=	${WRKSRC}/vmmemctl/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	vmware
GH_PROJECT=	open-vm-tools

MAKE_ARGS=	OVT_SOURCE_DIR=${WRKSRC:H:H:H}
WRKSRC_SUBDIR=	open-vm-tools/modules/freebsd/

PLIST_FILES=	${KMODDIR}/vmblock.ko \
		${KMODDIR}/vmmemctl.ko

.include <bsd.port.mk>
