PORTNAME=	lazpaint
PORTVERSION=	7.3
DISTVERSIONPREFIX=	v
PORTREVISION=	7
CATEGORIES=	graphics
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Image editor written in Lazarus
WWW=		https://wiki.freepascal.org/LazPaint

LICENSE=	GPLv3

ONLY_FOR_ARCHS=	amd64 i386

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5 ${PORTNAME}-qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5

USES=		desktop-file-utils dos2unix fpc gnome lazarus:flavors xorg
USE_XORG=	x11
DOS2UNIX_REGEX=	.*\.([txt]|pas|lpi|txt)
USE_GITHUB=	yes
GH_TAGNAME=	a11930b
GH_ACCOUNT=	bgrabitmap
GH_TUPLE=	bgrabitmap:bgracontrols:20dbed8:bgracontrols/bgracontrols \
		bgrabitmap:bgrabitmap:6ada359:bgrabitmap/bgrabitmapnew

USE_GNOME_gtk2=	cairo
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
.	for RESO in 128 16 24 256 32 48 512 64 96
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${RESO}x${RESO}/apps
		${INSTALL_DATA} ${WRKSRC}/resources/icon/${RESO}x${RESO}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${RESO}x${RESO}/apps/${PORTNAME}.png
.	endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/lazpaint/release/bin && ${COPYTREE_SHARE} "i18n models" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
