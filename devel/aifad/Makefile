# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	aifad
PORTVERSION=	2.0.8
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Machine learning system

LICENSE=	LGPL21+

BUILD_DEPENDS=	menhir:devel/menhir \
		ocaml-cfg>0:devel/ocaml-cfg \
		ocaml-pcre>0:devel/ocaml-pcre \
		ocaml-res>0:devel/ocaml-res
LIB_DEPENDS=	libpcre.so:devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	mmottl

USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${STAGEDIR}${PREFIX}

PORTDOCS=	AUTHORS.txt CHANGES.txt README.md TODO.md
PORTEXAMPLES=	*
PLIST_FILES=	bin/aifad

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aifad

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
