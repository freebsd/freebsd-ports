# $FreeBSD$

PORTNAME=	sysctlview
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Graphical sysctl MIB explorer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsysctlmibinfo2.so:devel/libsysctlmibinfo2
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		compiler:c++11-lang gettext-runtime gnome pkgconfig
USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_COMMIT=	91028a02b584eaf8c16c72d839f57cd1680b5b62
USE_GNOME=	atk atkmm cairo cairomm gdkpixbuf2 glib20 glibmm gtk30 gtkmm30 \
		libsigc++20 pango pangomm

INSTALLS_ICONS=	yes

DESKTOP_ENTRIES=	"Sysctlview" \
			"Show and set the kernel state" \
			"sysctlview" \
			"sysctlview" \
			"System;" \
			false

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200019
IGNORE=		needs oid_label member of struct sysctl_oid defined in sysctl.h which was first introduced in FreeBSD 12
.endif
.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sysctlview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sysctlview.1 ${STAGEDIR}${MAN1PREFIX}/share/man/man1
.for i in 16 22 24 32 36 48 64 72 96 128 192 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/
	${INSTALL_DATA} ${WRKSRC}/icon/sysctlview-${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/sysctlview.png
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/
	${INSTALL_DATA} ${WRKSRC}/icon/sysctlview.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/sysctlview.svg

.include <bsd.port.post.mk>
