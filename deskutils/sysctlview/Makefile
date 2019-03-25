# $FreeBSD$

PORTNAME=	sysctlview
PORTVERSION=	0.2
CATEGORIES=	deskutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Show sysctl mib

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsysctlmibinfo.so:devel/libsysctlmibinfo

USES=		pkgconfig gettext-runtime gnome
USE_GNOME=	gtkmm30 atkmm glibmm pangomm glibmm gtk30 pango atk \
		cairo glib20 cairomm libsigc++20 gdkpixbuf2 glib20

USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_COMMIT=	b5f2b0071945b4324c3f1e9202f7580cd94baf56

DESKTOP_ENTRIES="Sysctlview" "Show kernel state" "" \
		"sysctlview" "System;" false

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

PLIST_FILES=	bin/sysctlview \
		man/man1/sysctlview.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sysctlview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sysctlview.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
