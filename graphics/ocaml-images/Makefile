# ex:ts=8
# Ports collection makefile for:	ocaml-images
# Date created:			Feb 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	images
PORTVERSION=	2.10
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/caml-light/bazar-ocaml/
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
LIB_DEPENDS=	ungif:${PORTSDIR}/graphics/libungif \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff

USE_XPM=	yes
USE_FREETYPE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
	LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
USE_GMAKE=	yes

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
