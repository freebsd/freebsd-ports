# New ports collection makefile for:	php-mode.el
# Date created:				21 June 2002
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	php-mode.el
PORTVERSION=	1.4.0
CATEGORIES=	lang elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=php-mode
DISTNAME=	${PORTNAME:S/.el$//}-${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Emacs lisp module for the PHP language

INFO=		php-mode

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-build:
.if !defined(NOPORTDOCS)
	cd ${BUILD_WRKSRC} && makeinfo --no-split php-mode.texi
.endif

do-install:
	${MKDIR} ${EMACSLISPDIR}
	${MKDIR} ${XEMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/php-mode.el ${EMACSLISPDIR}/php-mode.el
	${LN} -sf ${EMACSLISPDIR}/php-mode.el ${XEMACSLISPDIR}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/php-mode.info ${PREFIX}/${INFO_PATH}/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
