# New ports collection makefile for:	yc.el
# Date created:		1999/12/05
# Whom:			HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	yc.el
PORTVERSION=	3.5.0
PORTEPOCH=	1
CATEGORIES=	japanese elisp
MASTER_SITES=	http://www.ceres.dti.ne.jp/~knak/
EXTRACT_SUFX=	.gz

MAINTAINER=	t@nakao.org

EXTRACT_AFTER_ARGS=	> yc.el
NO_WRKSUBDIR=	yes

EMACS_PORT_NAME?=	emacs21
YC_LISPDIR=		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/yc

do-build:
	${EMACS_CMD} -batch -f batch-byte-compile ${WRKSRC}/yc.el

do-install:
	${MKDIR} ${YC_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/yc.el ${YC_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/yc.elc ${YC_LISPDIR}

post-install:
	@${CAT} ${MASTERDIR}/pkg-message

.include <bsd.port.mk>
