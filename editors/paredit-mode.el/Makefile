# $FreeBSD$

PORTNAME=	paredit-mode.el
PORTVERSION=	23
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

NO_STAGE=	yes
do-install:
	@${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${PREFIX}/${EMACS_SITE_LISPDIR}/paredit.el

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
