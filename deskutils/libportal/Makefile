PORTNAME=	libportal
PORTVERSION=	0.7.1
CATEGORIES=	deskutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT?=	GIO-styled async APIs for Flatpak
WWW=		https://github.com/flatpak/libportal

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc

USES+=		gnome meson pkgconfig

USE_GNOME+=	glib20 introspection:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	flatpak

OPTIONS_DEFINE=		VAPI
OPTIONS_DEFAULT=	VAPI

VAPI_MESON_TRUE=	vapi
VAPI_USES=		vala:build

MESON_ARGS=	-Ddocs=false \
		-Dbackend-gtk3=disabled -Dbackend-gtk4=disabled -Dbackend-qt5=disabled
OPTIONS_SUB=	yes

.if defined(BACKEND)
LIB_DEPENDS=	libportal.so:deskutils/libportal
PLIST=		${PKGDIR}/pkg-plist.${BACKEND}
MESON_ARGS+=	-Dbackend-${BACKEND}=enabled

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${CAT} ${PKGDIR}/pkg-plist | ${SED} -e 's/^%%VAPI%%//' | ${XARGS} ${RM}
	@${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete
.endif

.include <bsd.port.mk>
