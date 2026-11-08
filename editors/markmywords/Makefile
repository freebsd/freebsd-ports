PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	g20200722
CATEGORIES=	editors

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Minimal WebKitGTK-based markdown editor
WWW=		https://github.com/voldyman/MarkMyWords

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libmarkdown.so:textproc/discount \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40

USES=		cmake desktop-file-utils gnome pkgconfig
USE_GNOME=	gtksourceview3
CMAKE_OFF=	GSETTINGS_COMPILE
GLIB_SCHEMAS=	org.markmywords.gschema.xml

USE_GITHUB=	yes
GH_ACCOUNT=	voldyman
GH_PROJECT=	MarkMyWords
GH_TAGNAME=	970b459

post-patch:
	@${REINPLACE_CMD} -e '/add_custom_command/ \
	    s,TARGET pot,& POST_BUILD,' \
		${WRKSRC}/cmake/Translations.cmake
# 3:2 (450x300) "About" window looks much better
	@${REINPLACE_CMD} -e '/set_default_size/s,500,300,' \
		${WRKSRC}/src/Widgets/AboutDialog.vala

.include <bsd.port.mk>
