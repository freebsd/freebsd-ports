# New ports collection makefile for:	libjpeg-turbo
# Date created:				2010-04-09
# Whom:					Denis Podolskiy <bytestore@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	libjpeg-turbo
PORTVERSION=	1.2.1
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
MAKE_JOBS_SAFE=	yes
ALL_TARGET=	test

MAN1=		cjpeg.1 djpeg.1 jpegtran.1 rdjpgcom.1 wrjpgcom.1
PLIST_SUB=	SOVERSION=${SOVERSION}
PORTDOCS=	*
PORTEXAMPLES=	*

# chase graphics/jpeg
SOVERSION=	11

OPTIONS+=	PIC "Static library with PIC (required for VirtualGL)" off

.include <bsd.port.options.mk>

.if defined(WITH_PIC)
CONFIGURE_ARGS+=--with-pic
.endif

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/^install-data-am/s,install-dist_docDATA,,' \
		${WRKSRC}/Makefile.in
.else
	${REINPLACE_CMD} -e '/^docdir/s,=.*,= ${DOCSDIR},' \
		${WRKSRC}/Makefile.in
.endif

.if defined(NOPORTEXAMPLES)
	${REINPLACE_CMD} -e '/^install-data-am/s,install-dist_exampleDATA,,' \
		${WRKSRC}/Makefile.in
.else
	${REINPLACE_CMD} -e '/^exampledir/s,=.*,= ${EXAMPLESDIR},' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
