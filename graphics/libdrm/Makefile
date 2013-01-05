# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	libdrm
PORTVERSION=	${LIBDRM_VERSION}
PORTREVISION=	${LIBDRM_REVISION}
CATEGORIES=	graphics x11
MASTER_SITES=	http://dri.freedesktop.org/libdrm/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Userspace interface to kernel Direct Rendering Module services

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:${PORTSDIR}/devel/libpthread-stubs
LIB_DEPENDS=	pciaccess:${PORTSDIR}/devel/libpciaccess \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:${PORTSDIR}/devel/libpthread-stubs

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-nouveau-experimental-api

MAKE_JOBS_SAFE=	yes

.if defined(WITH_NEW_XORG)

OPTIONS_DEFINE=	KMS
KMS_DESC=	Enable experimental KMS support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKMS}
CONFIGURE_ARGS+=--enable-libkms
EXTRA_PATCHES+=	${FILESDIR}/extra-xf86drmMode.c
PLIST_SUB+=	KMS=""
.else
PLIST_SUB+=	KMS="@comment "
.endif

LIBDRM_VERSION=	2.4.31
LIBDRM_REVISION=1
PLIST_SUB+=	OLD="@comment " NEW=""
.else
LIBDRM_VERSION=	2.4.17
LIBDRM_REVISION=1
PLIST_SUB+=	OLD="" NEW="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386" || ${ARCH} == "ia64" || ${ARCH} == "powerpc"
PLIST_SUB+=	INTEL_DRIVER=""
PLIST_SUB+=	RADEON_DRIVERS=""
.else
PLIST_SUB+=	INTEL_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|g; \
			   12661s/x86_/amd/g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
