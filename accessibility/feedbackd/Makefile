PORTNAME=	feedbackd
PORTVERSION=	s20210125
CATEGORIES=	accessibility

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Haptic/visual/audio feedback for GNOME

LICENSE=	GPLv3+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LIB

USES=		compiler:c11 gnome meson pkgconfig python:build shebangfix
USE_GITLAB=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GL_SITE=	https://source.puri.sm
GL_ACCOUNT=	Librem5
GL_COMMIT=	aac3306ad5e24ca46e1ca402a478f505b01b351e
SHEBANG_FILES=	build-aux/post_install.py
GLIB_SCHEMAS=	org.sigxcpu.feedbackd.gschema.xml

OPTIONS_DEFINE=	DAEMON DOCS GIR MANPAGES VAPI
OPTIONS_DEFAULT=DAEMON DOCS GIR MANPAGES VAPI
OPTIONS_SUB=	yes

DAEMON_DESC=		Build DBus daemon
DAEMON_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
DAEMON_LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
			libgudev-1.0.so:devel/libgudev
DAEMON_USE=		GNOME=gsound
DAEMON_MESON_TRUE=	daemon

DOCS_BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk_doc
DOCS_VARS=		DOCSDIR="${PREFIX}/share/gtk-doc/html/libfeedback"

GIR_DESC=		Build Gobject Introspection
GIR_USE=		GNOME=introspection:build
GIR_MESON_ENABLED=	introspection

MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt
MANPAGES_MESON_TRUE=	man

VAPI_BUILD_DEPENDS=	vapigen:lang/vala
VAPI_MESON_TRUE=	vapi
VAPI_IMPLIES=		GIR

.include <bsd.port.mk>
