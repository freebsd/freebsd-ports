# $FreeBSD$

PORTNAME=	lazpaint
PORTVERSION=	7.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Image editor written in Lazarus

LICENSE=	GPLv3

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2

USES=		desktop-file-utils dos2unix fpc gnome lazarus:flavors xorg
USE_FPC=	chm fcl-base fcl-image fcl-json fcl-net fcl-web fcl-xml \
		opengl openssl pasjpeg rtl-extra rtl-objpas x11
USE_XORG=	x11
DOS2UNIX_REGEX=	.*\.([txt]|pas|lpi|txt)
USE_GITHUB=	yes
GH_ACCOUNT=	bgrabitmap
GH_PROJECT=	lazpaint
GH_TUPLE=	bgrabitmap:bgracontrols:a0a5a40:bgracontrols/bgracontrols \
		bgrabitmap:bgrabitmap:1ea4cb9:bgrabitmap/bgrabitmapnew

USE_FPC_gtk2=	cairo
USE_GNOME_gtk2=	cairo
USE_FPC+=	${USE_FPC_${FLAVOR}}
USE_GNOME+=	${USE_GNOME_${FLAVOR}}

DESKTOP_ENTRIES="LazPaint" \
		"Image editor written in Lazarus" \
		"lazpaint" \
		"${PREFIX}/bin/lazpaint" \
		"Graphics;" \
		${TRUE}

LAZARUS_PROJECT_FILES=	bgrabitmapnew/bgrabitmap/bgrabitmappack.lpk
LAZARUS_PROJECT_FILES+=	bgracontrols/bgracontrols.lpk
LAZARUS_PROJECT_FILES+=	lazpaintcontrols/lazpaintcontrols.lpk
LAZARUS_PROJECT_FILES+=	lazpaint/lazpaint.lpi

LAZBUILD_ARGS=	-d --bm=Release

post-patch:
	${REINPLACE_CMD} 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/lazpaint/utranslation.pas

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lazpaint/release/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${WRKSRC}/lazpaint/release/debian/linux32/usr/share/pixmaps/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/lazpaint/release/bin && ${COPYTREE_SHARE} "i18n models" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
