PORTNAME=	freetennis
PORTVERSION=	0.4.8
PORTREVISION=	18
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tennis simulation
WWW=		https://freetennis.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${OCAMLFIND_DEPEND} \
		${SA_DIR}/camlimages/META:graphics/ocaml-images \
		${SA_DIR}/lablGL/gl.ml:graphics/ocaml-lablgl \
		${SA_DIR}/lablgtk2/gtk.ml:x11-toolkits/ocaml-lablgtk2 \
		${SA_DIR}/sdl/sdl.mli:devel/ocaml-sdl

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgtkgl-2.0.so:x11-toolkits/gtkglarea2 \
		libharfbuzz.so:print/harfbuzz

USES=		gettext gl gnome sdl tar:bzip2 xorg
USE_OCAML=	yes
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango
USE_GL=		gl glu
USE_SDL=	ttf mixer sdl
USE_XORG=	x11 xext xmu

PLIST_FILES=	bin/freetennis
PORTDATA=	*

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|sfxDir = "sfx"|sfxDir = "${DATADIR}/sfx"|; \
		s|gfxDir = "graphics"|gfxDir = "${DATADIR}/graphics"|' \
		${WRKSRC}/freetennis.ml

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/freetennis ${STAGEDIR}${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "graphics sfx" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
