# Created by: ijliao
# $FreeBSD$

PORTNAME=	findlib
PORTVERSION=	1.5.1
CATEGORIES=	devel
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@FreeBSD.org
COMMENT=	OCaml package manager

USE_OCAML=	yes
HAS_CONFIGURE=	yes
USES=		gmake
ALL_TARGET=	all opt

CONFIGURE_ARGS=	-bindir "${PREFIX}/bin" -mandir "${PREFIX}/man" \
		-sitelib "${PREFIX}/${OCAML_SITELIBDIR}" \
		-config "${PREFIX}/etc/findlib.conf"
USE_OCAML_FINDLIB=yes
OCAMLFIND_DEPEND=	# Avoid dependency loop

OPTIONS_DEFINE=	TOOLBOX DOCS
OPTIONS_DEFAULT=TOOLBOX
OPTIONS_SUB=	yes
TOOLBOX_DESC=	Include toolbox interface (requires OCaml with TK)
TOOLBOX_CONFIGURE_ON=	-with-toolbox

MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's,path="@SITELIB@,&:${PREFIX}/${OCAML_LIBDIR},' \
		${WRKSRC}/findlib.conf.in

post-install:
	@-${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/ocamlfind \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/findlib/make_wizard
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR} \
		"! -regex .*ref-man.*"
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ocamlfind
	# Copied from Makefile; requires functional installation:
	cd ${WRKSRC}/src/bytes/_build && \
	${SETENV} ${MAKE_ENV} \
		OCAMLFIND_CONF=${STAGEDIR}${PREFIX}/etc/findlib.conf \
		${STAGEDIR}${PREFIX}/bin/ocamlfind install bytes ../META \
			bytes.cmi bytes.cma -optional \
			bytes.cmx bytes.cmxa bytes.a bytes.cmxs

.include <bsd.port.mk>
