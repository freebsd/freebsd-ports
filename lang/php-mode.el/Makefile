# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	php-mode.el
PORTVERSION=	1.20.0
DISTVERSIONPREFIX=	v
CATEGORIES=	lang elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	PHP mode for GNU Emacs

LICENSE=	GPLv3

USES=		emacs gmake
USE_GITHUB=	yes
GH_ACCOUNT=	emacs-php
GH_PROJECT=	${PORTNAME:S/.el$//}

NO_ARCH=	yes
PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/php-mode.el \
		${EMACS_VERSION_SITE_LISPDIR}/php-mode.elc \
		${EMACS_VERSION_SITE_LISPDIR}/php-project.el \
		${EMACS_VERSION_SITE_LISPDIR}/php-project.elc

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} \
		${WRKSRC}/php-mode.el \
		${WRKSRC}/php-mode.elc \
		${WRKSRC}/php-project.el \
		${WRKSRC}/php-project.elc \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

.include <bsd.port.mk>
