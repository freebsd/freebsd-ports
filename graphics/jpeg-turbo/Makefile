# Created by: Denis Podolskiy <bytestore@yandex.ru>
# $FreeBSD$

PORTNAME=	jpeg-turbo
PORTVERSION=	2.0.1
PORTREVISION?=	0
CATEGORIES=	graphics
MASTER_SITES=	SF/lib${PORTNAME}/${PORTVERSION}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	portmgr@FreeBSD.org
COMMENT?=	SIMD-accelerated JPEG codec which replaces libjpeg

LICENSE=	BSD3CLAUSE IJG ZLIB 
LICENSE_COMB=	multi
LICENSE_GROUPS_IJG=	FSF GPL
LICENSE_NAME_IJG=	Independent JPEG Group License
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE.md
LICENSE_FILE_IJG=	${WRKSRC}/README.ijg
LICENSE_FILE_ZLIB=	${WRKSRC}/LICENSE.md
LICENSE_PERMS_IJG=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake cpe
USE_LDCONFIG=	yes
CMAKE_ON=	WITH_JPEG8
CPE_VENDOR=	d.r.commander
CPE_PRODUCT=	libjpeg-turbo
TEST_TARGET=	test

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/libjpeg-turbo

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == i386 || ${ARCH} == amd64
BUILD_DEPENDS+=	nasm:devel/nasm
.endif

.if ${SLAVE_PORT} == yes
PLIST_SUB+=	JPEG="@comment " LIBTURBOJPEG=""
.else
CMAKE_OFF=	WITH_TURBOJPEG
CONFLICTS_INSTALL=	jpeg-[0-9]*
PLIST_SUB+=	JPEG="" LIBTURBOJPEG="@comment "
.endif

.include <bsd.port.mk>
