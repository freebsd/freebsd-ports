# $FreeBSD$

PORTNAME=	pkg-info.el
PORTVERSION=	0.6
CATEGORIES=	devel elisp

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Provide information about Emacs packages

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	lunaryorn
USE_EMACS=	yes
NO_BUILD=	yes
PLIST_FILES=	%%EMACS_SITE_LISPDIR%%/pkg-info.el

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${PLIST_FILES:M*.el:T} \
	    ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
