# Created by: Denis Podolskiy <bytestore@yandex.ru>
# $FreeBSD$

PORTNAME=	jpeg-turbo
PORTVERSION=	1.4.0
PORTREVISION?=	0
CATEGORIES=	graphics
MASTER_SITES=	SF/lib${PORTNAME}/${PORTVERSION}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	bytestore@yandex.ru
COMMENT?=	SIMD-accelerated JPEG codec which replaces libjpeg

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

.include <bsd.port.options.mk>

.if ${ARCH} == i386 || ${ARCH} == amd64
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

.if ${SLAVE_PORT} == yes
CONFIGURE_ARGS+=--with-pic
PLIST_SUB+=	JPEG="@comment " LIBTURBOJPEG=""
.else
CONFIGURE_ARGS+=--program-suffix=-turbo --without-turbojpeg
PLIST_SUB+=	JPEG="" LIBTURBOJPEG="@comment "

post-install:
	@${ECHO_CMD} "libjpeg.so.8 libjpeg.so.8.0.2" \
		> ${STAGEDIR}${PREFIX}/etc/libmap.d/${PORTNAME}.conf
.endif

.include <bsd.port.mk>
