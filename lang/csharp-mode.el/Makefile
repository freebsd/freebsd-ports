PORTNAME=	csharp-mode.el
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	lang elisp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs major mode for editing C\# source code
WWW=		https://github.com/josteink/csharp-mode

LICENSE=	GPLv2

DEPRECATED=	No longer maintained upstream as a standalone package. This mode is part of Emacs core since Emacs 29
EXPIRATION_DATE=2026-06-30

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	josteink
GH_PROJECT=	csharp-mode

CONFLICTS_INSTALL=	csharp-mode.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/csharp-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/csharp-mode.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
