# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lensfun
DISTVERSION=	0.2.4-dev
CATEGORIES=	graphics
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Gimp plugin to correct lens distortion using the lensfun library

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/exiv2.pc:${PORTSDIR}/graphics/exiv2 \
		${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:${PORTSDIR}/graphics/gimp-app \
		${LOCALBASE}/libdata/pkgconfig/lensfun.pc:${PORTSDIR}/graphics/lensfun
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/exiv2.pc:${PORTSDIR}/graphics/exiv2 \
		${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:${PORTSDIR}/graphics/gimp-app \
		${LOCALBASE}/libdata/pkgconfig/lensfun.pc:${PORTSDIR}/graphics/lensfun

USE_GITHUB=	yes
GH_ACCOUNT=	seebk
GH_PROJECT=	GIMP-Lensfun
GH_COMMIT=	d0a0bd2
GH_TAGNAME=	${GH_COMMIT}

USES=		gmake pkgconfig

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins/
PLUGINS=	gimp-lensfun

# installed files
.for plugin in ${PLUGINS}
PLIST_FILES+=	${PLUGIN_DIR}/${plugin}
.endfor

# installed dirs
PLIST_DIRSTRY=	libexec/gimp/2.2/plug-ins \
		libexec/gimp/2.2 \
		libexec/gimp

post-patch:
	@${REINPLACE_CMD} \
		-e 's|gimptool-2.0|${LOCALBASE}/bin/gimptool-2.0|' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
.for plugin in ${PLUGINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${plugin} ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
.endfor

.include <bsd.port.mk>
