# New ports collection makefile for:	yc.el
# Date created:		1999/12/05
# Whom:			HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	yc.el
PORTVERSION=	4.0.13
PORTEPOCH=	1
CATEGORIES=	japanese elisp
MASTER_SITES=	http://www.ceres.dti.ne.jp/~knak/
DISTNAME=	yc-${PORTVERSION}

MAINTAINER=	t@nakao.org
COMMENT=	Yet another Canna client for Emacs/XEmacs

EMACS_PORT_NAME?=	emacs21
YC_LISPDIR=		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/yc

MAKE_ARGS+=	LISPDIR=${YC_LISPDIR}
MAKE_ARGS+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ARGS+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

PLIST_FILES=	bin/icanna \
		%%EMACS_VERSION_SITE_LISPDIR%%/yc/yc.el \
		%%EMACS_VERSION_SITE_LISPDIR%%/yc/yc.elc
PLIST_DIRS=	%%EMACS_VERSION_SITE_LISPDIR%%/yc

post-install:
	@${CAT} ${MASTERDIR}/pkg-message

.include <bsd.port.mk>
