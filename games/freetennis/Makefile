# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freetennis
PORTVERSION=	0.4.8
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tennis simulation

BUILD_DEPENDS=	ocamlopt:${PORTSDIR}/lang/ocaml \
		ocaml-images>3.0:${PORTSDIR}/graphics/ocaml-images \
		${OCAML_DEPENDS}
RUN_DEPENDS=	${OCAML_DEPENDS}

OCAML_DEPENDS=	${LOCALBASE}/lib/ocaml/site-lib/lablgtk2/gtk.ml:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2 \
		${LOCALBASE}/lib/ocaml/lablGL/gl.ml:${PORTSDIR}/graphics/ocaml-lablgl \
		${LOCALBASE}/lib/ocaml/site-lib/sdl/sdl.mli:${PORTSDIR}/devel/ocaml-sdl

USE_BZIP2=	yes

PLIST=		${WRKDIR}/pkg-plist
PLIST_FILES=	bin/freetennis
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e 's|sfxDir = "sfx"|sfxDir = "${DATADIR}/sfx"|; \
		s|gfxDir = "graphics"|gfxDir = "${DATADIR}/graphics"|' \
		${WRKSRC}/freetennis.ml
	@${REINPLACE_CMD} -Ee 's@(\+)(lablgtk2)@\1site-lib/\2@' \
		${WRKSRC}/Makefile

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} graphics sfx -type f | ${SORT} \
		| ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} graphics sfx -type d | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freetennis ${PREFIX}/bin
	cd ${WRKSRC} && \
	${FIND} graphics sfx -type d -exec \
		${MKDIR} "${DATADIR}/{}" \; && \
	${FIND} graphics sfx -type f -exec \
		${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

.include <bsd.port.mk>
