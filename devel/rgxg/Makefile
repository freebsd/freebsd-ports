PORTNAME=	rgxg
DISTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	alexander.naumochkin@gmail.com
COMMENT=	Regular expression generator
WWW=		https://rgxg.github.io

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	m4:devel/m4

USES=		autoreconf libtool pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS COPYING NEWS README

OPTIONS_DEFINE=	DOCS

pre-configure:
	@echo "m4_define([_PACKAGE_VERSION], [${DISTVERSION}])" > ${WRKSRC}/m4/version.m4

.include <bsd.port.mk>
