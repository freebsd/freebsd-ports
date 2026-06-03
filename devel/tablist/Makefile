PORTNAME=	tablist
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0-13
DISTVERSIONSUFFIX=	-gfaab7a0
PORTREVISION=	12
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Emacs package for extended tabulated-list-mode
WWW=		https://github.com/politza/tablist

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	politza

CONFLICTS_INSTALL=	tablist-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${EMACS_SITE_LISPDIR}/tablist-filter.el \
		${EMACS_SITE_LISPDIR}/tablist.el

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
