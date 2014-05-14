# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=	camlp5
PORTVERSION=	6.11
CATEGORIES=	devel
MASTER_SITES=	http://cristal.inria.fr/~ddr/camlp5/distrib/src/ \
		http://pauillac.inria.fr/~ddr/camlp5/distrib/src/
PKGNAMEPREFIX=	ocaml-
DIST_SUBDIR=	${UNIQUENAME}

PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	Preprocessor-pretty-printer of OCaml

LICENSE=	INRIA
LICENSE_NAME=	INRIA permissive license with copyright notice requirements
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=			tar:tgz
USE_OCAML=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix ${PREFIX}

OPTIONS_SINGLE=		MODE
OPTIONS_SINGLE_MODE=	TRANSITIONAL STRICT
OPTIONS_DEFAULT=	STRICT
TRANSITIONAL_DESC=	Compatible syntax tree with old versions
STRICT_DESC=		New syntax tree quotations kit

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CHANGES DEVEL ICHANGES INSTALL MODE README UPGRADING

MAKE_JOBS_UNSAFE= yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTRANSITIONAL}
CONFIGURE_ARGS+=	--transitional
.elif ${PORT_OPTIONS:MSTRICT}
CONFIGURE_ARGS+=	--strict
.endif
ALL_TARGET=	world.opt

MLINKS=		camlp5.1 camlp5o.1 \
		camlp5.1 camlp5o.opt.1 \
		camlp5.1 camlp5r.1 \
		camlp5.1 camlp5r.opt.1 \
		camlp5.1 camlp5sch.1 \
		camlp5.1 mkcamlp5.1 \
		camlp5.1 mkcamlp5.opt.1 \
		camlp5.1 ocpp5.1

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/etc/META \
		${STAGEDIR}${PREFIX}/lib/ocaml/camlp5

.include <bsd.port.mk>
