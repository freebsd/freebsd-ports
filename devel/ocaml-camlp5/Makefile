# ex:ts=8
# Ports collection makefile for:	camlp5
# Date created:			Mar 23 2008
# Whom:				Hirohisa Yamaguchi <umq@ueo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	camlp5
PORTVERSION=	5.12
CATEGORIES=	devel
MASTER_SITES=	http://cristal.inria.fr/~ddr/camlp5/distrib/src/ \
		http://pauillac.inria.fr/~ddr/camlp5/distrib/src/
PKGNAMEPREFIX=	ocaml-
EXTRACT_SUFX=	.tgz

MAINTAINER=	umq@ueo.co.jp
COMMENT=	A preprocessor-pretty-printer of OCaml

USE_OCAML=	yes
HAS_CONFIGURE=	yes

.if defined(WITH_TRANSITIONAL) || !defined(WITH_STRICT)
CONFIGURE_ARGS=	--transitional --prefix ${PREFIX}
.else
CONFIGURE_ARGS=	--strict --prefix ${PREFIX}
.endif
ALL_TARGET=	world.opt

MAN1=		camlp5.1
MANCOMPRESSED=	no
MLINKS=		camlp5.1 camlp5o.1 camlp5.1 camlp5o.opt.1 camlp5.1 camlp5r.1 \
		camlp5.1 camlp5r.opt.1 camlp5.1 camlp5sch.1 camlp5.1 mkcamlp5.1 \
		camlp5.1 mkcamlp5.opt.1 camlp5.1 ocpp5.1
PORTDOCS=	CHANGES DEVEL ICHANGES INSTALL LICENSE MODE README UPGRADING

.include <bsd.port.pre.mk>

post-patch:
	${FIND} ${WRKSRC} -name "*.sh" -exec ${REINPLACE_CMD} -e "s,^#!/bin/bash,#!/bin/sh," {} \;
	${REINPLACE_CMD} -e "s,^#!/bin/bash,#!/bin/sh," ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/etc/META ${PREFIX}/lib/ocaml/${PORTNAME}

.include <bsd.port.post.mk>
