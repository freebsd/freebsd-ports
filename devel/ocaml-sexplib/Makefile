# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	sexplib
PORTVERSION=	108.07.00
CATEGORIES=	devel
MASTER_SITES=	https://ocaml.janestreet.com/ocaml-core/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}/individual
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OCaml library for working with S-expressions

LICENSE=	BSD

BUILD_DEPENDS=	ocaml-type-conv>0:${PORTSDIR}/devel/ocaml-typeconv
RUN_DEPENDS=	ocaml-type-conv>0:${PORTSDIR}/devel/ocaml-typeconv

OPTIONS_DEFINE=	DOCS

USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAMLFIND_PLIST=yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX} --disable-docs
MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_DIRSTRY+=	${OCAML_DOCSDIR:S,^${PREFIX}/,,)
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in CHANGES.txt README.md
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
