# $FreeBSD$

PORTNAME=	pkg-info.el
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	devel elisp

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Provide information about Emacs packages

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	lunaryorn

USE_EMACS=	yes

NO_BUILD=	yes


do-install:
	${INSTALL_DATA} ${WRKSRC}/pkg-info.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
