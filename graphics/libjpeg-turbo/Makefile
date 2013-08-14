# Created by: Denis Podolskiy <bytestore@yandex.ru>
# $FreeBSD$

PORTNAME=	libjpeg-turbo
PORTVERSION=	1.3.0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	bytestore@yandex.ru
COMMENT=	SIMD-accelerated JPEG codec which provides both the libjpeg,TurboJPEG

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

CONFLICTS_INSTALL=	jpeg-[0-9]*
ONLY_FOR_ARCHS=	amd64 i386
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	SO_MAJOR_VERSION=${SOVERSION}
CONFIGURE_ARGS=	--with-jpeg8
USE_LDCONFIG=	yes
ALL_TARGET=	test

MAN1=		cjpeg.1 djpeg.1 jpegtran.1 rdjpgcom.1 wrjpgcom.1
PLIST_SUB=	SOVERSION=${SOVERSION}
PORTDOCS=	*
PORTEXAMPLES=	*

# chase graphics/jpeg
SOVERSION=	11

OPTIONS_DEFINE=	PIC
PIC_DESC=	Static library with PIC (required for VirtualGL)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPIC}
CONFIGURE_ARGS+=--with-pic
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/^install-data-am/s,install-dist_docDATA,,' \
		${WRKSRC}/Makefile.in
.else
	${REINPLACE_CMD} -e '/^docdir/s,=.*,= ${DOCSDIR},' \
		${WRKSRC}/Makefile.in
.endif

.if ! ${PORT_OPTIONS:MEXAMPLES}
	${REINPLACE_CMD} -e '/^install-data-am/s,install-dist_exampleDATA,,' \
		${WRKSRC}/Makefile.in
.else
	${REINPLACE_CMD} -e '/^exampledir/s,=.*,= ${EXAMPLESDIR},' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
