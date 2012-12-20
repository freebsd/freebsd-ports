# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	type-conv
PORTVERSION=	108.07.00
CATEGORIES=	devel
MASTER_SITES=	https://ocaml.janestreet.com/ocaml-core/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}/individual
DISTNAME=	${PORTNAME:S,-,_,}-${PORTVERSION}
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Type conversion routines for OCaml

LICENSE=	BSD


USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAMLFIND_PLIST=yes
OCAML_PKGDIRS=	${PORTNAME:S,-,_,}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX} --disable-docs
MAKE_JOBS_UNSAFE=yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME:S,-,_,}
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_DIRSTRY=	${OCAML_DOCSDIR:S,^${PREFIX}/,,}
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in CHANGES.txt README.md
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
