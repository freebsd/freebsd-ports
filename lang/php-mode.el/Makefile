# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	php-mode.el
PORTVERSION=	1.5.0
CATEGORIES=	lang elisp
MASTER_SITES=	SF/php-mode/php-mode/${PORTVERSION}
DISTNAME=	${PORTNAME:S/.el$//}-${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Emacs lisp module for the PHP language

INFO=		php-mode

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

NO_STAGE=	yes
do-build:
	cd ${BUILD_WRKSRC} && makeinfo --no-split php-mode.texi

do-install:
	${MKDIR} ${EMACSLISPDIR}
	${MKDIR} ${XEMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/php-mode.el ${EMACSLISPDIR}/php-mode.el
	${LN} -sf ${EMACSLISPDIR}/php-mode.el ${XEMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/php-mode.info ${PREFIX}/${INFO_PATH}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
