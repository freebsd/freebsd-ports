# Created by: Denis Podolskiy <bytestore@yandex.ru>
# $FreeBSD$

PORTNAME=	jpeg-turbo
PORTVERSION=	1.3.1
PORTREVISION?=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/lib${PORTNAME}/${PORTVERSION}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	bytestore@yandex.ru
COMMENT?=	SIMD-accelerated JPEG codec which replaces libjpeg

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	amd64 i386
USES=		cpe libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jpeg8
USE_LDCONFIG=	yes
ALL_TARGET=	test
INSTALL_TARGET=	install-strip
CPE_VENDOR=	d.r.commander
CPE_PRODUCT=	libjpeg-turbo

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_MAKE_ARGS=		docdir="${DOCSDIR}"
DOCS_MAKE_ARGS_OFF=	dist_doc_DATA=""

EXAMPLES_MAKE_ARGS=	exampledir="${EXAMPLESDIR}"
EXAMPLES_MAKE_ARGS_OFF=	dist_example_DATA=""

.if defined(SLAVE_PORT)
CONFIGURE_ARGS+=--with-pic
PLIST_SUB+=	JPEG="@comment " LIBTURBOJPEG=""
.else
CONFIGURE_ARGS+=--program-suffix=-turbo --without-libturbojpeg
PLIST_SUB+=	JPEG="" LIBTURBOJPEG="@comment "

post-install:
	@${ECHO_CMD} "libjpeg.so.8 libjpeg.so.8.0.2" \
		> ${STAGEDIR}${PREFIX}/etc/libmap.d/${PORTNAME}.conf
.endif

.include <bsd.port.mk>
