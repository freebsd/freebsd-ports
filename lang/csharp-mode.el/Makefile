# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	csharp-mode.el
PORTVERSION=	0.8.5
PORTREVISION=	8
CATEGORIES=	lang elisp
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME:S|.el$||}-${PORTVERSION}.el
EXTRACT_SUFX=	# none

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Emacs/XEmacs major mode for editing C\# source code

LICENSE=	GPLv2

PROJECTHOST=	csharpmode
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# none
EXTRACT_AFTER_ARGS=	.

USE_EMACS=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/csharp-mode.el

post-patch:
	@${MV} ${WRKSRC}/csharp-mode-${PORTVERSION}.el ${WRKSRC}/csharp-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/csharp-mode.* \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
