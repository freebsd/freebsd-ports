PORTNAME=	satty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.3
CATEGORIES=	graphics wayland
MASTER_SITES=	CRATESIO

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Modern screenshot annotation
WWW=		https://github.com/gabm/Satty

LICENSE=	MPL20

USES=		cargo desktop-file-utils gnome
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk40 libadwaita
GH_ACCOUNT=	gabm
GH_PROJECT=	Satty
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for f in *.desktop assets/*.svg
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}:H}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}}
.endfor

.include <bsd.port.mk>
