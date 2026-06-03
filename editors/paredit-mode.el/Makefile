PORTNAME=	paredit-mode.el
PORTVERSION=	24
PORTREVISION=	22
CATEGORIES=	editors elisp
MASTER_SITES=	http://mumble.net/~campbell/emacs/
DISTNAME=	paredit-${PORTVERSION}.el
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Minor mode for performing editing of S-expression data
WWW=		https://www.emacswiki.org/emacs/ParEdit

LICENSE=	GPLv3+

USES=		emacs

CONFLICTS_INSTALL=	paredit-mode.el-emacs_*

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/paredit.el

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/paredit.el

.include <bsd.port.mk>
