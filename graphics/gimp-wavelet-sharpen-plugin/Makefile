# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wavelet-sharpen
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GIMP plugin to sharpen by increasing contrast in high frequency space

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:graphics/gimp-app
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:graphics/gimp-app

USES=		gettext gmake pkgconfig

PLIST_SUB=	GIMP_PLUGIN_DIR=${GIMP_PLUGIN_DIR}
GIMP_PLUGIN_DIR=	libexec/gimp/2.2/plug-ins

LANGUAGES=	de et it pl ru

OPTIONS_DEFINE=	NLS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS
OPTIONS_SUB=	yes

OPTIMIZED_CFLAGS_CFLAGS=	-O3

post-patch:
	@${REINPLACE_CMD} \
		-e 's|gimptool-2.0|${LOCALBASE}/bin/gimptool-2.0|' \
		-e '/^LIBS =/s/$$/ -lm/' \
		${WRKSRC}/src/Makefile

post-patch-NLS-off:
	@${REINPLACE_CMD} -E \
		-e 's|(^all:.*)po |\1|' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${GIMP_PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${STAGEDIR}${PREFIX}/${GIMP_PLUGIN_DIR}

do-install-NLS-on:
.for language in ${LANGUAGES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${language}/LC_MESSAGES/
	${INSTALL_DATA} ${WRKSRC}/po/${language}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${language}/LC_MESSAGES/gimp20-${PORTNAME}-plug-in.mo
.endfor

.include <bsd.port.mk>
