PORTNAME=	satty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
CATEGORIES=	graphics wayland
MASTER_SITES=	CRATESIO

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	57f5e68d2b23.patch:-p1 # https://github.com/gabm/Satty/pull/176

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Modern screenshot annotation
WWW=		https://github.com/gabm/Satty

LICENSE=	MPL20

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		cargo desktop-file-utils gnome
USE_GITHUB=	yes
USE_GNOME=	gdkpixbuf gtk40 libadwaita
GH_ACCOUNT=	gabm
GH_PROJECT=	Satty
CARGO_ENV=	SOURCE_DIR="${WRKSRC}"
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg

post-install:
.for f in *.desktop assets/*.svg
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}:H}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}}
.endfor

.include <bsd.port.mk>
