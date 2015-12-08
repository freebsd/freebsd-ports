# $FreeBSD$

PORTNAME=	dash.el
PORTVERSION=	2.11.0
CATEGORIES=	devel elisp

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Modern list library for Emacs

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	magnars

USE_EMACS=	yes

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/dash.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/dash-functional.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
