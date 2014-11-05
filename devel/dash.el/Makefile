# $FreeBSD$

PORTNAME=	dash.el
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	devel elisp
DISTNAME=	dash-${PORTVERSION}

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Modern list library for Emacs

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	magnars
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	9b50f26

USE_EMACS=	yes

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/dash.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/dash-functional.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
