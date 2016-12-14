# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magic
PORTVERSION=	0.7.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/ocaml-${PORTNAME}/ocaml-${PORTNAME}/0.7
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml binding for libmagic(3)

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

USES=		gmake
GNU_CONFIGURE=	yes

ALL_TARGET+=	doc examples
DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

# This really is overzealous but I work this way
.if !exists(/usr/lib/libmagic.so)
LIB_DEPENDS+=	libmagic.so:sysutils/file
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
