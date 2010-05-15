# New ports collection makefile for:	libdrm
# Date created:				29 Dec 2005
# Whom:					lesi@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libdrm
PORTVERSION=	${LIBDRM_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://dri.freedesktop.org/libdrm/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Userspace interface to kernel Direct Rendering Module services

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:${PORTSDIR}/devel/libpthread-stubs
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:${PORTSDIR}/devel/libpthread-stubs

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NOUVEAU)
LIBDRM_VERSION=	2.4.17
CONFIGURE_ARGS=	--disable-nouveau-experimental-api \
		--disable-radeon-experimental-api
PLIST_SUB+=	NEW= OLD="@comment "
.else
LIBDRM_VERSION=	2.4.12
CONFIGURE_ARGS=	--enable-nouveau-experimental-api
PLIST_SUB+=	OLD= NEW="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|g' \
	    ${WRKSRC}/configure

.include <bsd.port.post.mk>
