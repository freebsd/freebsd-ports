# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	csharp-mode.el
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	lang elisp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs/XEmacs major mode for editing C\# source code

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	josteink
GH_PROJECT=	csharp-mode

NO_BUILD=	yes
USE_EMACS=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/csharp-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/csharp-mode.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
