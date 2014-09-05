# Created by: Denis Podolskiy <bytestore@yandex.ru>
# $FreeBSD$

PORTNAME=	jpeg-turbo
PORTVERSION=	1.3.0
PORTREVISION?=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	bytestore@yandex.ru
COMMENT?=	SIMD-accelerated JPEG codec which replaces libjpeg

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	amd64 i386
USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SO_MAJOR_VERSION=${SOVERSION}
CONFIGURE_ARGS=	--with-jpeg8
USE_LDCONFIG=	yes
ALL_TARGET=	test
INSTALL_TARGET=	install-strip

PLIST_SUB=	SOVERSION=${SOVERSION}
PORTDOCS=	*
PORTEXAMPLES=	*

# chase graphics/jpeg
SOVERSION=	11

OPTIONS_DEFINE=	DOCS EXAMPLES PIC 
PIC_DESC=	Static library with PIC (required for VirtualGL)

DOCS_MAKE_ARGS=		docdir="${DOCSDIR}"
DOCS_MAKE_ARGS_OFF=	dist_doc_DATA=""

EXAMPLES_MAKE_ARGS=	exampledir="${EXAMPLESDIR}"
EXAMPLES_MAKE_ARGS_OFF=	dist_example_DATA=""

PIC_CONFIGURE_ON=	--with-pic

.if defined(SLAVE_PORT)
PLIST_SUB+=	JPEG="@comment " LIBTURBOJPEG=""
.else
PLIST_SUB+=	JPEG="" LIBTURBOJPEG="@comment "
CONFLICTS_INSTALL=	jpeg-[0-9]*
CONFIGURE_ARGS+=--without-libturbojpeg
.endif

.include <bsd.port.mk>
