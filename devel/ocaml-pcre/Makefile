# New ports collection makefile for:   ocaml-pcre
# Date created:        21 April 2002
# Whom:                Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	pcre
PORTVERSION=	4.31.0
CATEGORIES=	devel
MASTER_SITES=	http://www.oefai.at/~markus/ocaml_sources/
MASTER_SITE_SUBDIR=	pcre-ocaml
PKGNAMEPREFIX=	ocaml-
DISTNAME=	pcre-ocaml-${PORTVERSION}

MAINTAINER=	henrik.motakef@web.de

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

USE_GMAKE=	yes
MAKE_ENV=	OCAML_LIB_INSTALL="${PREFIX}/lib/ocaml/site-lib/pcre" \
		INCDIRS="${LOCALBASE}/include" LIBDIRS="${LOCALBASE}/lib"

post-install:
	${INSTALL_DATA} ${WRKSRC}/META ${PREFIX}/lib/ocaml/site-lib/pcre; \
		${ECHO_CMD} "${PREFIX}/lib/ocaml/site-lib/pcre" >> ${PREFIX}/lib/ocaml/ld.conf

.include <bsd.port.mk>
