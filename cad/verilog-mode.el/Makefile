# New ports collection makefile for:	verilog-mode.el
# Date created:		12 January 2009
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	verilog-mode.el
PORTVERSION=	465
PORTREVISION=	1
CATEGORIES=	cad elisp
MASTER_SITES=	http://www.veripool.org/ftp/
DISTNAME=	verilog-mode-${PORTVERSION}.el
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs lisp modules for the Verilog language

NO_BUILD=	yes
EXTRACT_AFTER_ARGS=	> ${ELFILE}

ELFILE=		verilog-mode.el
EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKDIR}/${ELFILE} ${DATADIR}/
	${MKDIR} ${XEMACSLISPDIR}
	${LN} -sf ${DATADIR}/${ELFILE} ${EMACSLISPDIR}/
	${LN} -sf ${DATADIR}/${ELFILE} ${XEMACSLISPDIR}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
