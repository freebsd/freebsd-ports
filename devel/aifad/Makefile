# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	aifad
PORTVERSION=	2.0.6
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Machine learning system

LICENSE=	GPLv3

BUILD_DEPENDS=	menhir:${PORTSDIR}/devel/menhir \
		ocaml-cfg>0:${PORTSDIR}/devel/ocaml-cfg \
		ocaml-pcre>0:${PORTSDIR}/devel/ocaml-pcre \
		ocaml-res>0:${PORTSDIR}/devel/ocaml-res
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

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
