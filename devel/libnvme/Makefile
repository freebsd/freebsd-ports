PORTNAME=	libnvme
PORTVERSION=	1.11.1
CATEGORIES=	devel

MAINTAINER=	imp@FreeBSD.org
COMMENT=	Port of Linux nvme cli utility
WWW=		https://github.com/linux-nvme/libnvme

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	freebsd-nvme-shim>0:devel/freebsd-nvme-shim \
		bash>0:shells/bash \
		swig>0:devel/swig

USES=		meson
USE_LDCONFIG=	yes
MESON_ARGS=	-Dopenssl=disabled -Dkeyutils=disabled -Djson-c=disabled \
		-Dpython=disabled
CXXFLAGS+=	-I${LOCALBASE}/include/freebsd-nvme-shim
CFLAGS+=	-I${LOCALBASE}/include/freebsd-nvme-shim
PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		MAJORVER=${PORTVERSION:C/^([0-9]+)\..*/\1/}

USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp
GH_TAGNAME=	freebsd-${PORTVERSION}

.include <bsd.port.mk>
