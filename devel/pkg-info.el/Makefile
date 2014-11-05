# $FreeBSD$

PORTNAME=	pkg-info.el
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	devel elisp
DISTNAME=	pkg-info-${PORTVERSION}

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Provide information about Emacs packages

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	lunaryorn
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	fc749d9

USE_EMACS=	yes

NO_BUILD=	yes


do-install:
	${INSTALL_DATA} ${WRKSRC}/pkg-info.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
