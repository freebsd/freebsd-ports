PORTNAME=	libliftoff
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	graphics

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	2218b45d14de.patch:-p1 # https://gitlab.freedesktop.org/emersion/libliftoff/-/issues/75

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Lightweight KMS plane library
WWW=		https://gitlab.freedesktop.org/emersion/libliftoff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		compiler:c11 meson pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	emersion
GL_COMMIT=	40834142e1ab25cf0fc8e5461e51f08562294f11

.include <bsd.port.mk>
