# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	mysql
PORTVERSION=	1.2.4
CATEGORIES=	databases
MASTER_SITES=	http://ygrek.org.ua/p/release/ocaml-mysql/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	OCaml bindings to libmysqlclient

LICENSE=	LGPL21

USES=		gmake mysql
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_LDCONFIG=	yes

GNU_CONFIGURE=		yes

ALL_TARGET=		all opt
MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_ALL_TARGET=	htdoc

post-patch:
	${REINPLACE_CMD} 's,OCAMLFIND_INSTFLAGS=,OCAMLFIND_INSTFLAGS=-ldconf ignore ,' \
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mysql/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
