PORTNAME=	lua-mode
PORTVERSION=	20210802
DISTVERSIONPREFIX=v
PORTREVISION=	12
CATEGORIES=	devel elisp

MAINTAINER=	se@FreeBSD.org
COMMENT=	Minor mode for LUA
WWW=		https://github.com/immerrr/lua-mode

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs

USE_GITHUB=	yes
GH_ACCOUNT=	immerrr

CONFLICTS_INSTALL=	lua-mode-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/lua-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/lua-mode.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/

.include <bsd.port.mk>
