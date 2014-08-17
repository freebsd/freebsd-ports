# Created by: Bjoern Koenig <bkoenig@alpha-tierchen.de>
# $FreeBSD$

PORTNAME=	jamvm
PORTVERSION=	1.5.4
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/JamVM%20${PORTVERSION}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Compact Java virtual machine

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/share/classpath/glibj.zip:${PORTSDIR}/java/classpath

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-classpath-install-dir=${LOCALBASE}
USES=		gmake libtool pkgconfig

OPTIONS_DEFINE=	FFI ZIP
OPTIONS_DEFAULT=FFI ZIP
FFI_DESC=	use libffi to call native methods
ZIP_DESC=	turn-on zip support in the bootstrap loader

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFFI}
LIB_DEPENDS+=		libffi.so:${PORTSDIR}/devel/libffi
CONFIGURE_ARGS+=	--enable-ffi
.elif ${ARCH} == "sparc64"
IGNORE=		for ${ARCH} requires libffi
.endif

.if ${PORT_OPTIONS:MZIP}
BUILD_DEPENDS+=		zip:${PORTSDIR}/archivers/zip
PLIST_SUB+=		WITH_ZIP="" WITHOUT_ZIP="@comment "
.else
CONFIGURE_ARGS+=	--disable-zip
PLIST_SUB+=		WITH_ZIP="@comment " WITHOUT_ZIP=""
.endif

post-extract:
	@${REINPLACE_CMD} -e "s,\(^include_HEADERS = .*\)jni.h\(.*\),\1\2," ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
