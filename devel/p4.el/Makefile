# New ports collection makefile for:	p4.el for Emacsen
# Date created:		2 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	p4.el
PORTVERSION=	8.5
CATEGORIES=	devel elisp
MASTER_SITES=	http://www.dsmit.com/p4/
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	p4:${.CURDIR}/../perforce

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	${MKDIR} ${EMACSLISPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME} ${EMACSLISPDIR}/p4.el
	${MKDIR} ${XEMACSLISPDIR}
	${LN} -sf ${EMACSLISPDIR}/p4.el ${XEMACSLISPDIR}

.include <bsd.port.mk>
