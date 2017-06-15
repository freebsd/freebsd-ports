# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wavelet-decompose
DISTVERSION=	0.1.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gimp plugin to losslessly decompose images into wavelet scales layers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:graphics/gimp-app
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:graphics/gimp-app

USES=		gettext gmake pkgconfig

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins

PLIST_FILES=	${PLUGIN_DIR}/wavelet-decompose

LANGUAGES=	de ru it pl

OPTIONS_DEFINE=	NLS

.for language in ${LANGUAGES}
NLS_PLIST_FILES+=	share/locale/${language}/LC_MESSAGES/gimp20-${PORTNAME}-plug-in.mo
.endfor

post-patch:
	@${REINPLACE_CMD} \
		-e 's|gimptool-2.0|${LOCALBASE}/bin/gimptool-2.0|' \
		${WRKSRC}/src/Makefile

post-patch-NLS-off:
	@${REINPLACE_CMD} -E \
		-e 's|(^all:.*)po |\1|' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/wavelet-decompose ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}

do-install-NLS-on:
.for language in ${LANGUAGES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${language}/LC_MESSAGES/
	${INSTALL_DATA} ${WRKSRC}/po/${language}.mo ${STAGEDIR}${PREFIX}/share/locale/${language}/LC_MESSAGES/gimp20-${PORTNAME}-plug-in.mo
.endfor

.include <bsd.port.mk>
