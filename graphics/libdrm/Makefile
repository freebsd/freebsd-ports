# New ports collection makefile for:	libdrm
# Date created:				29 Dec 2005
# Whom:					lesi@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libdrm
PORTVERSION=	2.4.12
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

CONFIGURE_ARGS=	--enable-nouveau-experimental-api

pre-patch:
	@${REINPLACE_CMD} 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|g' \
	    ${WRKSRC}/configure

.include <bsd.port.mk>
