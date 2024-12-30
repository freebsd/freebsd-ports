PORTNAME=	mysql
PORTVERSION=	1.2.4
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://ygrek.org.ua/p/release/ocaml-mysql/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	OCaml bindings to libmysqlclient
WWW=		http://ygrek.org.ua/p/ocaml-mysql/

LICENSE=	LGPL21

USES=		gmake ocaml:camlp4,findplist,ldconfig mysql
IGNORE_WITH_MYSQL=	80 81

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
