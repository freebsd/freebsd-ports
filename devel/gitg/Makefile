# Created by: kipz <somicide@gmail.com>
# $FreeBSD$

PORTNAME=	gitg
PORTVERSION=	3.19.6
CATEGORIES=	devel deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GTK-based git repository viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libgee-0.8.so:devel/libgee \
		libgit2-glib-1.0.so:devel/libgit2-glib \
		libpeas-1.0.so:devel/libpeas \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libsecret-1.so:security/libsecret
BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		valac:lang/vala
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

CONFLICTS=	gitg0-[0-9]*
PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--disable-maintainer-mode \
		--enable-compile-warnings=no
USE_GNOME=	glib20 gtk30 gtksourceview3 intlhack introspection
INSTALL_TARGET=	install-strip

INSTALLS_ICONS=	yes
GLIB_SCHEMAS=	org.gnome.gitg.gschema.xml

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DEBUG NLS PYTHON
OPTIONS_SUB=	yes
DEBUG_CONFIGURE_ENABLE=	debug
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
PYTHON_USES=	python:3
PYTHON_CONFIGURE_ENABLE=	python
PYTHON_USE=	GNOME=py3gobject3
PYTHON_PLIST_SUB=	PYTHON_SUFFIX=${PYTHON_SUFFIX}

.include <bsd.port.pre.mk>

.if defined(PYTHON_REL)
.if ${PYTHON_REL} < 3500
PYOEXTENSION=	pyo
.else
PYOEXTENSION=	opt-1.pyc
.endif
.endif

PLIST_SUB+=	PYOEXTENSION=${PYOEXTENSION}

post-patch:
	@${REINPLACE_CMD} -e 's|0.24.0|0.25.0|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
