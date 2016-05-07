# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	id3el
PORTVERSION=	0.05
CATEGORIES=	audio elisp
MASTER_SITES=	http://www.gentei.org/~yuuji/software/mpg123el/
DISTNAME=	id3el-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Add-on to edit ID3 tags for mpg123-mode (mpg123.el) on Emacsen

RUN_DEPENDS=	${LOCALBASE}/lib/xemacs/site-lisp/mpg123.el:audio/mpg123.el

ALL_TARGET=	id3put

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	@${MKDIR} ${STAGEDIR}${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/id3.el ${STAGEDIR}${ELISPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/id3put ${STAGEDIR}${PREFIX}/bin
# For XEmacs
	@${MKDIR} ${STAGEDIR}${XELISPDIR}
	(cd ${STAGEDIR}${XELISPDIR} && ${LN} -sf ${ELISPDIR}/id3.el .)

.include <bsd.port.mk>
