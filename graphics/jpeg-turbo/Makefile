# Created by: Denis Podolskiy <bytestore@yandex.ru>
# $FreeBSD$

PORTNAME=	jpeg-turbo
PORTVERSION=	1.5.1
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
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/turbojpeg.c
LICENSE_FILE_IJG=	${WRKSRC}/README.ijg
LICENSE_FILE_ZLIB=	${WRKSRC}/simd/jsimdext.inc
LICENSE_PERMS_IJG=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe libtool pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jpeg8
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	test
CPE_VENDOR=	d.r.commander
CPE_PRODUCT=	libjpeg-turbo

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_MAKE_ARGS=		docdir="${DOCSDIR}"
DOCS_MAKE_ARGS_OFF=	dist_doc_DATA=""

EXAMPLES_MAKE_ARGS=	exampledir="${EXAMPLESDIR}"
EXAMPLES_MAKE_ARGS_OFF=	dist_example_DATA=""

.include <bsd.port.options.mk>

.if ${ARCH} == i386 || ${ARCH} == amd64
BUILD_DEPENDS+=	nasm:devel/nasm
.endif

.if ${SLAVE_PORT} == yes
# libturbojpeg.a has to be built with PIC for virtualgl
CONFIGURE_ARGS+=--with-pic
PLIST_SUB+=	JPEG="@comment " LIBTURBOJPEG=""
.else
CONFIGURE_ARGS+=--without-turbojpeg
CONFLICTS_INSTALL=	jpeg-[0-9]*
PLIST_SUB+=	JPEG="" LIBTURBOJPEG="@comment "
.endif

.include <bsd.port.mk>
