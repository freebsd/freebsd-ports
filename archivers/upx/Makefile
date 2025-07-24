PORTNAME=	upx
PORTVERSION=	5.0.2
MASTER_SITES=	https://github.com/upx/upx/releases/download/v${PORTVERSION}/
CATEGORIES=	archivers
DISTVERSIONSUFFIX=	-src

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ultimate Packer for eXecutables
WWW=		https://upx.github.io/ \
		https://github.com/upx/upx

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libucl.so:archivers/ucl

USES=		cmake compiler:c++17-lang cpe tar:xz

CMAKE_ON=	UPX_CONFIG_DISABLE_BZIP2 \
		UPX_CONFIG_DISABLE_BZIP2 \
		UPX_CONFIG_DISABLE_GITREV \
		UPX_CONFIG_DISABLE_SANITIZE \
		UPX_CONFIG_DISABLE_SELF_PACK_TEST \
		UPX_CONFIG_DISABLE_THREADS \
		UPX_CONFIG_DISABLE_WERROR \
		UPX_CONFIG_DISABLE_WSTRICT

CPE_VENDOR=	upx_project

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
