# New ports collection makefile for:	mpg123.el
# Version required:	1.5
# Date created:		99/10/6
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	mpg123.el
PKGNAME=	mpg123.el-1.5
CATEGORIES=	audio elisp
MASTER_SITES=	http://www.gentei.org/~yuuji/software/mpg123el/
EXTRACT_SUFX=	# empty

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME} ${ELISPDIR}
# For XEmacs
	${MKDIR} ${XELISPDIR}
	${LN} -sf ${ELISPDIR}/${DISTNAME} ${XELISPDIR}

.include <bsd.port.mk>
