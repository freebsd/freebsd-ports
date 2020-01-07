# $FreeBSD$

PORTNAME=	graphql.el
DISTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	Emacs lisp library for GraphQL web services

LICENSE=	GPLv3+

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	vermiculus

NO_ARCH=	yes

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/graphql.el \
		${EMACS_VERSION_SITE_LISPDIR}/graphql.elc

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md

do-build:
	(cd ${WRKSRC} ; ${EMACS_CMD} -batch -q -f batch-byte-compile graphql.el)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/graphql.el* \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
