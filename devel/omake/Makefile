PORTNAME=	omake
PORTVERSION=	0.10.3
CATEGORIES=	devel
MASTER_SITES=	http://download.camlcity.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible build system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=yes
USES=		ncurses readline
HAS_CONFIGURE=	yes
MAKE_ENV=	INSTALL_ROOT=${STAGEDIR}
MAKE_JOBS_UNSAFE=	yes

INFO=		omake-doc

OPTIONS_DEFINE=	DOCS

do-test:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_ARGS} boot/omake check
	@${FIND} -ds ${WRKSRC}/test -type f -name 'result.log' -print0 | \
		${XARGS} -0tI @ ${CAT} @

bench: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_ARGS} boot/omake bench

post-install:
	@(cd ${WRKSRC}/doc/info && ${INSTALL_DATA} omake-doc.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH})
	@(cd ${WRKSRC}/doc/info && ${INSTALL_DATA} omake-doc.info-* \
		${STAGEDIR}${PREFIX}/${INFO_PATH})

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
