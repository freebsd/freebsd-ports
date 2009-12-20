# New ports collection makefile for:	csharp-mode.el
# Date created:				19 Jun 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	csharp-mode.el
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	lang elisp
MASTER_SITES=	http://mfgames.com/releases/csharp-mode/ \
		http://gentoo.kiev.ua/ftp/distfiles/ \
		http://unix.miet.ru/pub/linux/gentoo/distfiles/
DISTNAME=	${PORTNAME:S|.el$||}-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Emacs/XEmacs major mode for editing C\# source code

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes

USE_EMACS=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/csharp-mode.el \
		${EMACS_SITE_LISPDIR}/csharp-mode.elc

post-patch:
	@${MV} ${WRKSRC}/csharp-mode-${PORTVERSION}.el ${WRKSRC}/csharp-mode.el

do-build:
	cd ${WRKSRC} && ${EMACS_CMD} -batch -q -f batch-byte-compile csharp-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/csharp-mode.* ${PREFIX}/${EMACS_SITE_LISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
