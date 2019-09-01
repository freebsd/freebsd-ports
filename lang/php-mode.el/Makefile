# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	php-mode.el
PORTVERSION=	1.21.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
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

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} \
		${WRKSRC}/php-face.el \
		${WRKSRC}/php-face.elc \
		${WRKSRC}/php-mode-debug.el \
		${WRKSRC}/php-mode-debug.elc \
		${WRKSRC}/php-mode-test.el \
		${WRKSRC}/php-mode-test.elc \
		${WRKSRC}/php-mode.el \
		${WRKSRC}/php-mode.elc \
		${WRKSRC}/php-project.el \
		${WRKSRC}/php-project.elc \
		${WRKSRC}/php.el \
		${WRKSRC}/php.elc \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

.include <bsd.port.mk>
