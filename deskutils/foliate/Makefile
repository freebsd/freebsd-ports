# $FreeBSD$

PORTNAME=	foliate
PORTVERSION=	2.2.1
CATEGORIES=	deskutils

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Simple and modern GTK eBook viewer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		gjs-console:lang/gjs
LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3
RUN_DEPENDS=	gjs-console:lang/gjs

USES=		desktop-file-utils gnome localbase meson python:3.6+ shebangfix
USE_GNOME=	cairo gtk30 introspection

INSTALLS_ICONS=	yes

SHEBANG_FILES=	${WRKSRC}/build-aux/meson/postinstall.py \
		${WRKSRC}/src/assets/KindleUnpack/*.py

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

USE_GITHUB=	yes
GH_ACCOUNT=	johnfactotum

GLIB_SCHEMAS=	com.github.johnfactotum.Foliate.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's/@PYTHON_VERSION@/${PYTHON_VERSION}/g' \
		${WRKSRC}/src/epubView.js

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/foliate
	@${MV} ${STAGEDIR}${PREFIX}/bin/com.github.johnfactotum.Foliate \
		${STAGEDIR}${PREFIX}/libexec/foliate/com.github.johnfactotum.Foliate
	@${RLN} ${STAGEDIR}${PREFIX}/libexec/foliate/com.github.johnfactotum.Foliate \
		${STAGEDIR}${PREFIX}/bin/foliate
	@${REINPLACE_CMD} -e 's/Exec=com.github.johnfactotum.Foliate %U/Exec=foliate %U/g' \
		${STAGEDIR}${PREFIX}/share/applications/com.github.johnfactotum.Foliate.desktop

.include <bsd.port.mk>
