# New ports collection makefile for:	id3el
# Date created:		Sep 26, 2000
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	id3el
PORTVERSION=	0.05
CATEGORIES=	audio elisp
MASTER_SITES=	http://www.gentei.org/~yuuji/software/mpg123el/
DISTNAME=	id3el-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An add-on to edit an id3 tag for mpg123-mode (mpg123.el) on Emacsen

RUN_DEPENDS=	${LOCALBASE}/lib/xemacs/site-lisp/mpg123.el:${PORTSDIR}/audio/mpg123.el

ALL_TARGET=	id3put

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/id3.el ${ELISPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/id3put ${PREFIX}/bin
# For XEmacs
	${MKDIR} ${XELISPDIR}
	${LN} -sf ${ELISPDIR}/id3.el ${XELISPDIR}

.include <bsd.port.mk>
