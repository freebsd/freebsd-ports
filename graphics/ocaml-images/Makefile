# ex:ts=8
# Ports collection makefile for:	ocaml-images
# Date created:			Feb 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	images
PORTVERSION=	2.2
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/caml-light/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	camlimages-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Objective Caml image processing library

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		lablgtk:${PORTSDIR}/x11-toolkits/ocaml-lablgtk \
		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		lablgtk:${PORTSDIR}/x11-toolkits/ocaml-lablgtk \
		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_GHOSTSCRIPT=	yes
USE_XORG=	xpm
USE_FREETYPE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--includedir=${LOCALBASE}/include
USE_GMAKE=	yes

PKGDEINSTALL=	${PKGINSTALL}

#the default docsdir gets expanded to ${PREFIX}/share/doc/images
#which isn't of much help when you are searching for the package docs
DOCSDIR=	${PREFIX}/share/doc/ocaml-images

.if !defined(NOPORTDOCS)
PORTDOCS=	Announce Announce-2.2 CHANGES INSTALL LICENSE doc
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${FIND} doc | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${WRKSRC}/Announce ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/Announce-2.2 ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif
	@${FIND} ${PREFIX}/lib/ocaml/camlimages -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/camlimages" >> ${TMPPLIST}

.include <bsd.port.mk>
