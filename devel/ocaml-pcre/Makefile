# Created by: Henrik Motakef <henrik.motakef@web.de>
# $FreeBSD$

PORTNAME=	pcre
PORTVERSION=	7.1.5
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Perl compatible regular expressions for Objective Caml

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	mmottl
GH_PROJECT=	${PORTNAME}-ocaml
GH_TAGNAME=	v${PORTVERSION}

USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes

EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/pcre-ocaml

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|$$prefix"/"share|${STAGEDIR}${PREFIX}/share|' \
	-e '/datarootdir/s|$$pkg_name|&-ocaml|' \
		${WRKSRC}/setup.ml
	@${REINPLACE_CMD} -e 's| safe_string,||' ${WRKSRC}/_tags

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
