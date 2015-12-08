# $FreeBSD$

PORTNAME=	epl.el
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	devel elisp

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Emacs Package Library

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	cask
GH_PROJECT=	epl

USE_EMACS=	yes

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/epl.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
