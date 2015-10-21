# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wavelet-denoise
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GIMP plugin to reduce noise in each channel of an image separately

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:${PORTSDIR}/graphics/gimp-app
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:${PORTSDIR}/graphics/gimp-app

OPTIONS_DEFINE=	NLS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS
OPTIONS_SUB=	yes

USES=		gettext gmake pkgconfig

PLIST_SUB=	GIMP_PLUGIN_DIR=${GIMP_PLUGIN_DIR}
GIMP_PLUGIN_DIR=	libexec/gimp/2.2/plug-ins

# l10n languages
LANGUAGES=	de et it pl ru

.include <bsd.port.options.mk>

# optimized CFLAGS
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|gimptool-2.0|${LOCALBASE}/bin/gimptool-2.0|' \
		-e '/^LIBS =/s/$$/ -lm/' \
		${WRKSRC}/src/Makefile
#
## l10n
# disable l10n if appropriate
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -E \
		-e 's|(^all:.*)po |\1|' \
		${WRKSRC}/Makefile
.endif

do-install:
# plugin
	@${MKDIR} ${STAGEDIR}${PREFIX}/${GIMP_PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${STAGEDIR}${PREFIX}/${GIMP_PLUGIN_DIR}
#
## l10n
#
.if ${PORT_OPTIONS:MNLS}
.for language in ${LANGUAGES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${language}/LC_MESSAGES/
	${INSTALL_DATA} ${WRKSRC}/po/${language}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${language}/LC_MESSAGES/gimp20-${PORTNAME}-plug-in.mo
.endfor
.endif

.include <bsd.port.mk>
