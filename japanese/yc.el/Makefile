# New ports collection makefile for:	yc.el
# Version required:	19991203
# Date created:		1999/12/05
# Whom:			HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	yc.el
PKGNAME?=	ja-yc.el-19991203
CATEGORIES=	japanese elisp
MASTER_SITES=	http://www.ceres.dti.ne.jp/~knak/
EXTRACT_SUFX=	.gz

MAINTAINER=	honda@kashio.info.mie-u.ac.jp

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
WRKSRC=		${WRKDIR}

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/yc.el.gz ${WRKSRC}
	@(cd ${WRKSRC} ; ${GUNZIP_CMD} yc.el.gz)

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/yc.el ${ELISPDIR}
# for xemacs
	${MKDIR} ${XELISPDIR}
	${LN} -sf ${ELISPDIR}/yc.el ${XELISPDIR}

.include <bsd.port.mk>
