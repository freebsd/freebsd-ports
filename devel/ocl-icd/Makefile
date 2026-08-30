PORTNAME=	ocl-icd
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.5
CATEGORIES=	devel

MAINTAINER=	ohartmann@walstatt.org
COMMENT=	OpenCL Installable Client Driver
WWW=		https://github.com/OCL-dev/ocl-icd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

PORT_DEPENDS=	opencl>=3.1:devel/opencl
BUILD_DEPENDS=	${PORT_DEPENDS}
RUN_DEPENDS=	${PORT_DEPENDS}

USES=		autoreconf gmake libtool localbase:ldflags pathfix ruby:build

USE_GITHUB=	yes
GH_ACCOUNT=	OCL-dev
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug \
		--enable-custom-layerdir=${LOCALBASE}/etc/OpenCL/layers \
		--enable-custom-vendordir=${LOCALBASE}/etc/OpenCL/vendors \
		--enable-pthread-once

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-DCL_TARGET_OPENCL_VERSION=310

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			xmlto:textproc/xmlto

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${LOCALBASE}/etc/|g' \
		${WRKSRC}/doc/libOpenCL.7.txt.in

.include <bsd.port.mk>
