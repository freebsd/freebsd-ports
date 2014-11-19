# $FreeBSD$

PORTNAME=	paredit-mode.el
PORTVERSION=	23
PORTREVISION=	1
CATEGORIES=	editors elisp
MASTER_SITES=	http://mumble.net/~campbell/emacs/
DISTNAME=	paredit-${PORTVERSION}.el
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Minor mode for performing editing of S-expression data

USE_EMACS=	yes

NO_BUILD=	yes

PLIST_FILES=	%%EMACS_SITE_LISPDIR%%/paredit.el

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/paredit.el

.include <bsd.port.mk>
