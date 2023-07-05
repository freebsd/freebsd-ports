PORTNAME=	omake
DISTVERSION=	0.10.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.camlcity.org/download/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Flexible build system
WWW=		http://projects.camlcity.org/projects/omake.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ncurses readline
USE_OCAML=	yes

NO_OCAML_RUNDEPENDS=	yes
HAS_CONFIGURE=	yes
MAKE_ENV=	INSTALL_ROOT=${STAGEDIR}
MAKE_JOBS_UNSAFE=	yes

INFO=		omake-doc

OPTIONS_DEFINE=	DOCS

bench: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_ARGS} boot/omake bench

post-install:
	@(cd ${WRKSRC}/doc/info && ${INSTALL_DATA} omake-doc.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH})
	@(cd ${WRKSRC}/doc/info && ${INSTALL_DATA} omake-doc.info-* \
		${STAGEDIR}${PREFIX}/${INFO_PATH})
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/omake

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

do-test:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_ARGS} boot/omake check
	@${FIND} -ds ${WRKSRC}/test -type f -name 'result.log' -print0 | \
		${XARGS} -0tI @ ${CAT} @

.include <bsd.port.mk>
