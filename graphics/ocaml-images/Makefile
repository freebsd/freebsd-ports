# ex:ts=8
# Ports collection makefile for:	ocaml-images
# Date created:			Feb 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	images
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/caml-light/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	camlimages-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Objective Caml image processing library

.if defined(WITH_GHOSTSCRIPT_AFPL) && ${WITH_GHOSTSCRIPT_AFPL} == yes
GSPORT?=	print/ghostscript-afpl
.else
GSPORT?=	print/ghostscript-gnu
.endif

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		lablgtk:${PORTSDIR}/x11-toolkits/ocaml-lablgtk \
		gs:${PORTSDIR}/${GSPORT}
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		lablgtk:${PORTSDIR}/x11-toolkits/ocaml-lablgtk \
		gs:${PORTSDIR}/${GSPORT}
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

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
