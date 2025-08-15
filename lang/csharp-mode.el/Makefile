PORTNAME=	csharp-mode.el
PORTVERSION=	0.9.2
PORTREVISION=	17
DISTVERSIONPREFIX=	v
CATEGORIES=	lang elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs major mode for editing C\# source code
WWW=		https://github.com/josteink/csharp-mode

LICENSE=	GPLv2

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	josteink
GH_PROJECT=	csharp-mode

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/csharp-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/csharp-mode.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
