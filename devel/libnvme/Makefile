PORTNAME=	libnvme
DISTVERSION=	1.11.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	imp@FreeBSD.org
COMMENT=	C Library for NVM Express on Linux ported to FreeBSD
WWW=		https://github.com/linux-nvme/libnvme

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64
BUILD_DEPENDS=	freebsd-nvme-shim>0:devel/freebsd-nvme-shim \
		bash>0:shells/bash \
		swig>0:devel/swig

USES=		meson
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp
GH_TAGNAME=	freebsd-${DISTVERSION}

CFLAGS+=	-I${LOCALBASE}/include/freebsd-nvme-shim

PLIST_SUB=	DISTVERSION=${DISTVERSION} \
		MAJORVER=${DISTVERSION:R:R}

MESON_ARGS=	-Djson-c=disabled \
		-Dkeyutils=disabled \
		-Dopenssl=disabled \
		-Dpython=disabled \
		-Dtests=false

.include <bsd.port.mk>
