# New ports collection makefile for:	yc.el
# Date created:		1999/12/05
# Whom:			HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	yc.el
PORTVERSION=	3.2.4
PORTEPOCH=	1
CATEGORIES=	japanese elisp
MASTER_SITES=	http://www.ceres.dti.ne.jp/~knak/
EXTRACT_SUFX=	.gz

MAINTAINER=	honda@kashio.info.mie-u.ac.jp

EXTRACT_AFTER_ARGS=	> yc.el

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/yc.el ${ELISPDIR}
# for xemacs
	${MKDIR} ${XELISPDIR}
	${LN} -sf ${ELISPDIR}/yc.el ${XELISPDIR}

.include <bsd.port.mk>
