# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lensfun
DISTVERSION=	0.2.4-dev
PORTREVISION=	5
CATEGORIES=	graphics
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gimp plugin to correct lens distortion using the lensfun library

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/exiv2.pc:graphics/exiv2 \
		${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:graphics/gimp-app \
		${LOCALBASE}/libdata/pkgconfig/lensfun.pc:graphics/lensfun
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	seebk
GH_PROJECT=	GIMP-Lensfun
GH_TAGNAME=	d0a0bd2

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLUGINS=	gimp-lensfun

# installed files
.for plugin in ${PLUGINS}
PLIST_FILES+=	${PLUGIN_DIR}/${plugin}
.endfor

post-patch:
	@${REINPLACE_CMD} \
		-e 's|gimptool-2.0|${LOCALBASE}/bin/gimptool-2.0|' \
		${WRKSRC}/Makefile
# CCI support has been removed from recent versions of lensfun
	@${REINPLACE_CMD} -e '/CCI/d' ${WRKSRC}/src/gimplensfun.cpp

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
.for plugin in ${PLUGINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${plugin} ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
.endfor

.include <bsd.port.mk>
