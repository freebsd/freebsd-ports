# ex:ts=8
# Ports collection makefile for:	ocaml-images
# Date created:			Feb 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	images
PORTVERSION=	2.11
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/caml-light/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	camlimages-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Objective Caml image processing library

USE_GHOSTSCRIPT=	yes

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		lablgtk:${PORTSDIR}/x11-toolkits/ocaml-lablgtk
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		lablgtk:${PORTSDIR}/x11-toolkits/ocaml-lablgtk
LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

BROKEN=		Changes permissions of installed file

USE_XPM=	yes
USE_FREETYPE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
	LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
USE_GMAKE=	yes

PKGDEINSTALL=	${PKGINSTALL}

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/camlimages -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/camlimages" >> ${TMPPLIST}

.include <bsd.port.mk>
