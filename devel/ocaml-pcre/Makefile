# New ports collection makefile for:   ocaml-pcre
# Date created:        21 April 2002
# Whom:                Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	pcre
PORTVERSION=	4.33.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.henrik-motakef.de/freebsd-distfiles/
MASTER_SITE_SUBDIR=	pcre-ocaml
PKGNAMEPREFIX=	ocaml-
DISTNAME=	pcre-ocaml-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl compatible regular expressions for Objective Caml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

USE_GMAKE=	yes
MAKE_ENV=	OCAML_LIB_INSTALL="${PREFIX}/lib/ocaml/site-lib/pcre" \
		INCDIRS="${LOCALBASE}/include" LIBDIRS="${LOCALBASE}/lib"
.if !defined(WITH_CUSTOM)
MAKE_ENV+=	NO_CUSTOM=y
.endif

.include <bsd.port.mk>
