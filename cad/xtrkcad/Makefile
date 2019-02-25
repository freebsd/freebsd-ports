# $FreeBSD$

PORTNAME=	xtrkcad
DISTVERSIONPREFIX=	source-
DISTVERSION=	5.1.2a
CATEGORIES=	cad
MASTER_SITES=	SF/xtrkcad-fork/XTrackCad/Version%20${DISTVERSION:C/[:alpha:]//}

MAINTAINER=	freebsd@rheinwolf.de
COMMENT=	CAD program for designing model railroad layouts

LICENSE=	GPLv2

LIB_DEPENDS=	libcmocka.so:sysutils/cmocka \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libsoup-2.4.so:devel/libsoup \
		libwebkitgtk-1.0.so:www/webkit-gtk2

DEPRECATED=	Uses webkit-gtk2 which has security issues
EXPIRATION_DATE=2019-03-24

USES=		cmake gnome pkgconfig
USE_GNOME=	gdkpixbuf2 gtk20 cairo

CMAKE_ON=	XTRKCAD_USE_GTK
CMAKE_OFF=	XTRKCAD_TESTING

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	NLS

DOCS_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc

NLS_USES=	gettext-runtime:lib gettext-tools:build
NLS_CMAKE_BOOL=	XTRKCAD_USE_GETTEXT

post-install:
	${MKDIR} ${STAGEDIR}${DESKTOPDIR} \
		 ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${EXAMPLESDIR} \
		 ${STAGEDIR}${PREFIX}/share/pixmaps
	${MV} ${STAGEDIR}/usr/share/applications/xtrkcad.desktop ${STAGEDIR}${DESKTOPDIR}
	${MV} ${STAGEDIR}/usr/share/pixmaps/xtrkcad.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${RM} ${STAGEDIR}${DATADIR}/COPYING
	${RMDIR} ${STAGEDIR}/usr/share/applications ${STAGEDIR}/usr/share/pixmaps ${STAGEDIR}/usr/share

post-install-DOCS-on:
	${MV} ${STAGEDIR}${DATADIR}/CHANGELOG.txt ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${DATADIR}/Readme.txt ${STAGEDIR}${DOCSDIR}

post-install-DOCS-off:
	${RM} ${STAGEDIR}${DATADIR}/*.txt

post-install-EXAMPLES-on:
	${MV} ${STAGEDIR}${DATADIR}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${RMDIR} ${STAGEDIR}${DATADIR}/examples

post-install-EXAMPLES-off:
	${RM} -rf ${STAGEDIR}${DATADIR}/examples

.include <bsd.port.mk>
