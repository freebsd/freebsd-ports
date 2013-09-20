# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=	camlp5
PORTVERSION=	6.08.p${PATCHLEVEL}
CATEGORIES=	devel
MASTER_SITES=	http://cristal.inria.fr/~ddr/camlp5/distrib/src/ \
		http://pauillac.inria.fr/~ddr/camlp5/distrib/src/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${UNIQUENAME}

PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	preprocessor-pretty-printer of OCaml

LICENSE=	BSD

OPTIONS_SINGLE=		MODE
OPTIONS_SINGLE_MODE=	TRANSITIONAL STRICT
OPTIONS_DEFAULT=	STRICT
TRANSITIONAL_DESC=	Compatible syntax tree with old versions
STRICT_DESC=		New syntax tree quotations kit

NO_STAGE=	yes
.include <bsd.port.options.mk>

PATCHLEVEL=	1
PATCHFILES!=	${JOT} -s " " -w \
		patch-${PORTVERSION:R}-%d \
		${PATCHLEVEL} 1 ${PATCHLEVEL}

USE_OCAML=	yes
HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX}

.if ${PORT_OPTIONS:MTRANSITIONAL}
CONFIGURE_ARGS+=	--transitional
.elif ${PORT_OPTIONS:MSTRICT}
CONFIGURE_ARGS+=	--strict
.endif
ALL_TARGET=	world.opt

MAN1=		camlp5.1
MANCOMPRESSED=	no
MLINKS=		camlp5.1 camlp5o.1 camlp5.1 camlp5o.opt.1 camlp5.1 camlp5r.1 \
		camlp5.1 camlp5r.opt.1 camlp5.1 camlp5sch.1 camlp5.1 mkcamlp5.1 \
		camlp5.1 mkcamlp5.opt.1 camlp5.1 ocpp5.1
PORTDOCS=	CHANGES DEVEL ICHANGES INSTALL MODE README UPGRADING

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/etc/META ${PREFIX}/lib/ocaml/${PORTNAME}

.include <bsd.port.mk>
