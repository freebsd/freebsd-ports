# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	mysql
PORTVERSION=	1.1.1
CATEGORIES=	databases
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/870/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	OCaml bindings to libmysqlclient

USES=			gmake
USE_MYSQL=		yes
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_LDCONFIG=	yes

GNU_CONFIGURE=		yes

ALL_TARGET=		all opt

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=		htdoc

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mysql/html/* ${STAGEDIR}${DOCSDIR}
.endif

post-patch:
	${REINPLACE_CMD} 's,OCAMLFIND_INSTFLAGS=,OCAMLFIND_INSTFLAGS=-ldconf ignore ,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
