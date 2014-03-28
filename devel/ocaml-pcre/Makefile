# Created by: Henrik Motakef <henrik.motakef@web.de>
# $FreeBSD$

PORTNAME=	pcre
PORTVERSION=	7.0.4
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/mmottl/pcre-ocaml/downloads/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PORTNAME}-${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Perl compatible regular expressions for Objective Caml

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes

EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/pcre-ocaml

post-patch:
	@${REINPLACE_CMD} -e 's|$$prefix"/"share|${STAGEDIR}${PREFIX}/share|' \
		${WRKSRC}/setup.ml

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
