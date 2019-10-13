# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	php-mode.el
PORTVERSION=	1.22.0
DISTVERSIONPREFIX=	v
CATEGORIES=	lang elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	PHP mode for GNU Emacs

LICENSE=	GPLv3

.if ${FLAVOR:U} == devel_full || ${FLAVOR:U} == devel_nox
BROKEN=		php.el:232:10:Error: Symbol's function definition is void: rx-form
.endif

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
		${WRKSRC}/php-mode.el \
		${WRKSRC}/php-mode.elc \
		${WRKSRC}/php-project.el \
		${WRKSRC}/php-project.elc \
		${WRKSRC}/php.el \
		${WRKSRC}/php.elc \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

.include <bsd.port.mk>
