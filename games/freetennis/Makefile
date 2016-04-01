# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freetennis
PORTVERSION=	0.4.8
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tennis simulation

BUILD_DEPENDS=	ocamlopt:lang/ocaml \
		ocaml-images>3.0:graphics/ocaml-images \
		${OCAML_DEPENDS}
RUN_DEPENDS=	${OCAML_DEPENDS}

OCAML_DEPENDS=	${LOCALBASE}/lib/ocaml/site-lib/lablgtk2/gtk.ml:x11-toolkits/ocaml-lablgtk2 \
		${LOCALBASE}/lib/ocaml/lablGL/gl.ml:graphics/ocaml-lablgl \
		${LOCALBASE}/lib/ocaml/site-lib/sdl/sdl.mli:devel/ocaml-sdl

USES=		tar:bzip2

PLIST_FILES=	bin/freetennis
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|sfxDir = "sfx"|sfxDir = "${DATADIR}/sfx"|; \
		s|gfxDir = "graphics"|gfxDir = "${DATADIR}/graphics"|' \
		${WRKSRC}/freetennis.ml
	@${REINPLACE_CMD} -Ee 's@(\+)(lablgtk2)@\1site-lib/\2@' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freetennis ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "graphics sfx" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
