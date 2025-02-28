PORTNAME=	libnvme
DISTVERSION=	1.11.1
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	imp@FreeBSD.org
COMMENT=	C Library for NVM Express on Linux ported to FreeBSD
WWW=		https://github.com/linux-nvme/libnvme

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64
BUILD_DEPENDS=	freebsd-nvme-shim>0:devel/freebsd-nvme-shim \
		bash>0:shells/bash
LIB_DEPENDS=	libjson-c.so:devel/json-c

USES=		meson pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp
GH_TAGNAME=	freebsd-${DISTVERSION}

CFLAGS+=	-I${LOCALBASE}/include/freebsd-nvme-shim

PLIST_SUB=	DISTVERSION=${DISTVERSION} \
		MAJORVER=${DISTVERSION:R:R}

MESON_ARGS=	-Dkeyutils=disabled \
		-Dopenssl=disabled \
		-Dpython=disabled \
		-Dtests=false

.include <bsd.port.mk>
