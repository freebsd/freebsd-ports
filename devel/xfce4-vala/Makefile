# Created by: Olivier Duchateau <olivierd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-vala
PORTVERSION=	4.10.3
CATEGORIES=	devel xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/bindings/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Vala binding for the Xfce core libraries

LICENSE=	LGPL21

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala

GNU_CONFIGURE=	yes
USES=	pkgconfig gmake pathfix tar:bzip2
USE_XFCE=	configenv garcon libexo libmenu libutil panel xfconf

# vala-1.0.pc is symlink to libvala-${VALA_VER}.pc
CONFIGURE_ARGS=	--with-vala-api=1.0

post-patch:
	@${REINPLACE_CMD} -e 's|libvala-|vala-|g' ${WRKSRC}/acinclude.m4 \
		${WRKSRC}/configure

.include <bsd.port.mk>
