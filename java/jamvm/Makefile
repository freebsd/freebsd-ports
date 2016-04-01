# Created by: Bjoern Koenig <bkoenig@alpha-tierchen.de>
# $FreeBSD$

PORTNAME=	jamvm
PORTVERSION=	1.5.4
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/JamVM%20${PORTVERSION}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Compact Java virtual machine

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/share/classpath/glibj.zip:java/classpath

CONFIGURE_ARGS=	--with-classpath-install-dir=${LOCALBASE}
GNU_CONFIGURE=	yes
OPTIONS_SUB=	yes
USES=		compiler gmake libtool pkgconfig

OPTIONS_DEFINE=	FFI ZIP
OPTIONS_DEFAULT=FFI ZIP
FFI_DESC=	use libffi to call native methods
ZIP_DESC=	turn-on zip support in the bootstrap loader

FFI_CONFIGURE_ENABLE=	ffi
FFI_LIB_DEPENDS=	libffi.so:devel/libffi
ZIP_BUILD_DEPENDS=	zip:archivers/zip
ZIP_CONFIGURE_ENABLE=	zip

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MFFI) && ${ARCH} == "sparc64"
IGNORE=		for ${ARCH} requires libffi
.endif

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CONFIGURE_ARGS+=	--disable-int-inlining
.endif

post-extract:
	@${REINPLACE_CMD} -e "s,\(^include_HEADERS = .*\)jni.h\(.*\),\1\2," ${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
