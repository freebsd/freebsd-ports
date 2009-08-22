# New ports collection makefile for:	p4.el for Emacsen
# Date created:		2 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	p4.el
PORTVERSION=	10.6
CATEGORIES=	devel elisp
MASTER_SITES=	SF/p4el/p4el/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perforce-Emacs Integration

RUN_DEPENDS=	p4:${PORTSDIR}/devel/perforce

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	${MKDIR} ${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/p4.el ${EMACSLISPDIR}/
	${MKDIR} ${XEMACSLISPDIR}
	${LN} -sf ${EMACSLISPDIR}/p4.el ${XEMACSLISPDIR}

.include <bsd.port.mk>
