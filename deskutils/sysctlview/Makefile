# $FreeBSD$

PORTNAME=	sysctlview
PORTVERSION=	1.0
CATEGORIES=	deskutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Show sysctl MIB Tree

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsysctlmibinfo.so:devel/libsysctlmibinfo

USES=		pkgconfig gettext-runtime gnome
USE_GNOME=	gtkmm30 atkmm glibmm pangomm glibmm gtk30 pango atk \
		cairo glib20 cairomm libsigc++20 gdkpixbuf2 glib20

USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_COMMIT=	c6ea138ffbea46adb79fa857d032d2559e71a61f

INSTALLS_ICONS=	yes

DESKTOP_ENTRIES="Sysctlview" "Show kernel state" "sysctlview" \
		"sysctlview" "System;" false

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sysctlview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sysctlview.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.for i in 16 22 24 32 36 48 64 72 96 128 192 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/ && \
	${MV} ${WRKSRC}/icon/sysctlview-${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/sysctlview.png
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/ && \
	${MV} ${WRKSRC}/icon/sysctlview.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/sysctlview.svg

.include <bsd.port.mk>
