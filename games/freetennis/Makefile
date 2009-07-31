# New ports collection makefile for:	freetennis
# Date created:				07 Mar 2007
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freetennis
PORTVERSION=	0.4.8
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freetennis

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tennis simulation

BUILD_DEPENDS=	ocamlopt:${PORTSDIR}/lang/ocaml \
		${OCAML_DEPENDS}
RUN_DEPENDS=	${OCAML_DEPENDS}

OCAML_DEPENDS=	${LOCALBASE}/lib/ocaml/lablgtk2/gtk.ml:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2 \
		${LOCALBASE}/lib/ocaml/lablGL/gl.ml:${PORTSDIR}/graphics/ocaml-lablgl \
		${LOCALBASE}/lib/ocaml/camlimages/oImages.cmx:${PORTSDIR}/graphics/ocaml-images \
		${LOCALBASE}/lib/ocaml/site-lib/sdl/sdl.mli:${PORTSDIR}/devel/ocaml-sdl

USE_BZIP2=	yes

PLIST=		${WRKDIR}/pkg-plist
PLIST_FILES=	bin/freetennis
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e 's|sfxDir = "sfx"|sfxDir = "${DATADIR}/sfx"|; \
		s|gfxDir = "graphics"|gfxDir = "${DATADIR}/graphics"|' \
		${WRKSRC}/freetennis.ml

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
