# New ports collection makefile for:	yc.el
# Date created:		1999/12/05
# Whom:			HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	yc.el
PORTVERSION=	19991203
CATEGORIES=	japanese elisp
MASTER_SITES=	http://www.ceres.dti.ne.jp/~knak/
EXTRACT_SUFX=	.gz
DISTNAME=	${PORTNAME}

MAINTAINER=	honda@kashio.info.mie-u.ac.jp

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}
	@(cd ${WRKSRC} ; ${GUNZIP_CMD} ${DISTNAME}${EXTRACT_SUFX})

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${ELISPDIR}
# for xemacs
	${MKDIR} ${XELISPDIR}
	${LN} -sf ${ELISPDIR}/${DISTNAME} ${XELISPDIR}

.include <bsd.port.mk>
