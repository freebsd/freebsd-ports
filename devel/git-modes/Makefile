PORTNAME=	git-modes
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.8
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel elisp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Emacs modes for Git-related files
WWW=		https://github.com/magit/git-modes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	compat.el>=30.1.0.0:misc/compat.el
RUN_DEPENDS=	compat.el>=30.1.0.0:misc/compat.el \
		git:devel/git

USES=		emacs:build gmake
USE_GITHUB=	yes
GH_ACCOUNT=	magit

ALL_TARGET=	autoloads

CONFLICTS_INSTALL=	git-modes-emacs_*

NO_ARCH=	yes

PLIST_SUB=	ELISPDIR=${ELISPDIR}
PORTDOCS=	README.org

OPTIONS_DEFINE=	DOCS

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/${ELISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
