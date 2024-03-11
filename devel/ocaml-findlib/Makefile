PORTNAME=	findlib
PORTVERSION=	1.9.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	OCaml package manager
WWW=		http://projects.camlcity.org/projects/findlib.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_OCAML=	yes
USE_OCAML_CAMLP4=yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-bindir "${PREFIX}/bin" -mandir "${PREFIX}/share/man" \
		-sitelib "${PREFIX}/${OCAML_SITELIBDIR}" \
		-config "${PREFIX}/etc/findlib.conf"
MAKE_ENV=	OCAML_LIBDIR="${PREFIX}/${OCAML_LIBDIR}"
ALL_TARGET=	all opt
MAKE_JOBS_UNSAFE=	yes
DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	TOOLBOX DOCS
OPTIONS_DEFAULT=TOOLBOX
OPTIONS_SUB=	yes

TOOLBOX_DESC=	Include toolbox interface (requires OCaml with Tk)
TOOLBOX_CONFIGURE_ON=	-with-toolbox
TOOLBOX_RUN_DEPENDS=	labltk:x11-toolkits/ocaml-labltk
TOOLBOX_BUILD_DEPENDS=	${TOOLBOX_RUN_DEPENDS}

.include <bsd.port.pre.mk>

post-install:
	# META files provided by the respective ocaml-* package,
	# (those libraries used to be belong in the core ocaml
	# compiler package).
	@for oldlib in camlp4 graphics labltk ocamlbuild; \
	do ${RM} -r ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/$$oldlib ; done
	@(cd ${STAGEDIR}${PREFIX} && \
	    ${STRIP_CMD} bin/ocamlfind \
	    ${OCAML_SITELIBDIR}/findlib/findlib.cmxs \
	    ${OCAML_SITELIBDIR}/findlib/findlib_dynload.cmxs \
	    ${OCAML_SITELIBDIR}/findlib/findlib_top.cmxs)

post-install-TOOLBOX-on:
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/ocamlfind \
	    ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/findlib/make_wizard

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR} \
	    "! -regex .*ref-man.*"

.include <bsd.port.post.mk>
